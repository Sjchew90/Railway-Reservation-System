#include "Ticket.hpp"

void Ticket::ticketMainMenu(string username)
{
  Username = username;
  int number = 1;
  while(number == 1)
  {
    int choice = ticketMenu();
    switch (choice)
    {
    case 1 :
        system("cls");
        buyTicket();
        break;
    case 2 :
        system("cls");
        refundTicket();
        break;
    case 3 :
        system("cls");
        number = 0;
        break;
    default:
        break;
    }
  }
};

int Ticket::ticketMenu()
{
  while (1)
  {
    int userPick; string anything; 
    system("cls");
    cout<< "--------------------------------------------\n"
        << "           Welcome back, " << Username << " \n"
        << "--------------------------------------------\n"
        << "Tickets bought: ";
        ticketsbought(); 
        cout<< "\n-*Please select an option from the menu below*-\n\n"
            << "1. Buy Ticket" << endl
            << "2. Refund" << endl
            << "3. Return to Main Menu\n" << endl
            << "Please select your choice (1, 2 or 3): ";
    cin >> userPick;
    cout << endl;
    if (0 < userPick && userPick < 4)
        return userPick;
    else
    {
        cout << "Invalid Input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter anything to retry." << endl;
        cin >> anything;
        system("cls");
      }
  }

};

void Ticket::buyTicket()
{
  int age, startChoice, endChoice, referenceNumber, confirmation; string anything;
  double price;
  while(1)
  {
    age = askAge();
    startChoice = startLocationMenu(); 
    endChoice = TrainSelector(endLocationMenu(startChoice));
    price = PriceCalculation(startChoice,endChoice,age);
    referenceNumber = generateReferenceNumber();
    cout<< "The total for the ticket is RM " << fixed << setprecision(2) << price << endl;
    cout<< "\nPlease confirm your purchase:\n" << endl;
    cout<< "Ticket Reference:\t" << referenceNumber << endl;
    cout<< "Starting Location:\t" << places[startChoice - 1] 
        << "\nEnding Location:\t" << places[endChoice - 1] 
        << "\nTime of Departure:\t" ;
    if(Train == 1 )
      cout << times[startChoice - 1] << endl;
    else
      cout << times[PlacesCounter - startChoice - 1] << endl;

    cout<< "\nEnter 1 to confirm and 0 to cancel: "; 
    cin >> confirmation;
    cout << endl;
    if (0 <= confirmation && confirmation < 2)
    {
      if(confirmation == 0)
        break;
      else
      {
        writeUserInfoToFile(startChoice,endChoice,age,price,referenceNumber);
        cout << "Thanks for buying, please come before the designated time to not miss the train!" << endl;
        cout << "Enter anything to return to Main Menu." << endl;
        cin >> anything;
        system("cls");
        break;
      }

    }
    else
    {
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
      cout << "Enter anything to retry." << endl;
      cin >> anything;
      system("cls");
    }
  }

  
};

int Ticket::askAge()
{
  int age;
  string anything;
  while (1)
  {
    cout << "Please enter the age of passenger: " << endl;
    cin >> age;

  if (0 <= age && age <= 100)
    return age;
  else
    {
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter anything to retry." << endl;
      cin >> anything;
      system("cls");
    }
  }
}

int Ticket::startLocationMenu()
{
  int startinglocation;
  while(1)
  {
    cout<< "---------------------------------------------------\n"
      << "   Welcome to the Train Ticket Reservation Centre\n" 
      << "---------------------------------------------------\n";

    for (int i = 0; i < PlacesCounter; i++)
      {
        cout << i+1 << " . " << places[i] << endl;
      }
    cout <<"\nPlease choose your starting location (1-" << PlacesCounter << "): " << endl;
    cin >> startinglocation;
    cout << endl;

    string anything;
    if (0 < startinglocation && startinglocation <= PlacesCounter)
    {
      system("cls");
      return startinglocation;
    }
    else
    {
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter anything to retry." << endl;
      cin >> anything;
      system("cls");
    }    
  }
};

int Ticket::endLocationMenu(int startChoice)
{
  int trainNum, destination;
  while(1)
  {
    cout<< "---------------------------------------------------\n"
      << "\t\t|||TRAIN SCHEDULE|||\n"
      << "---------------------------------------------------\n"
      <<"    Train 1\t\tTime\t\tTrain 2\n";
    for (int i = 0; i < PlacesCounter; i++)
    {
      cout << i+1 << " . " << places[i] << "   " << "\t" << times[i] << " \t" << places[PlacesCounter - 1 - i] << endl;
    }
    cout << "\nStarting Location: " << places[startChoice - 1] << endl;
    cout << "Please choose the train number that you want (1 or 2): ";
    cin >> trainNum;
    cout << endl;
    string anything;
    if (0 < trainNum && trainNum < 3)
      trainNum = trainNum;
    else
    {
      cout << "Invalid Input" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter anything to retry." << endl;
      cin >> anything;
      system("cls");
      continue;
    } 
    system("cls");
    return endLocationMenu2(startChoice,trainNum);
  }

};

int Ticket::endLocationMenu2(int startChoice,int trainNum)
{
  int destination; string anything;
  while(1)
    {
      cout<< "---------------------------------------------------\n"
      << "\t\t|||TRAIN SCHEDULE|||\n"
      << "---------------------------------------------------\n"
      <<"    Train 1\t\tTime\t\tTrain 2\n";
      for (int i = 0; i < PlacesCounter; i++)
      {
        cout << i+1 << " . " << places[i] << "   " << "\t" << times[i] << " \t" << places[PlacesCounter - 1 - i] << endl;
      }

      cout << "\nStarting Location: " << places[startChoice - 1] << endl;
      cout << "Please choose the train number that you want (1 or 2): " << trainNum;
      cout << "\nPlease choose your destination (1-" << PlacesCounter << "): ";   
      cin >> destination;
      if (0 < destination && destination < PlacesCounter)
      {
        if(trainNum == 1)
        {
          if (destination <= startChoice)
          {
            cout << "Invalid Input" << endl;
            cout << "Enter anything to retry." << endl;
            cin >> anything;
            system("cls");
            continue;
          }
          else
          {
            system("cls");
            return destination;
          }
        }
        else
        {
          if (destination <= PlacesCounter - startChoice)
          {
            cout << "Invalid Input" << endl;
            cout << "Enter anything to retry." << endl;
            cin >> anything;
            system("cls");
            continue;
          }
          else
          {
            system("cls");
            return 10 + PlacesCounter - destination;
          }
          
        }
      }
      else
      {
        cout << "Invalid Input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter anything to retry." << endl;
        cin >> anything;
        system("cls");
      } 
    }
};

void Ticket::readLocationFromFile()
{
  ifstream inFile;
  inFile.open("Ticket_location.txt");
  if (inFile.is_open()) 
  {
    for(size_t x = 0; x < LOCATION_TIME_MAX; x++)
      {
        inFile >> places[x];
        if (places[x] == "")
          break;
        else
          PlacesCounter++;
      }
    inFile.close();
  }
  else 
    cout << "Error opening file." << endl; 
};

void Ticket::readTimeFromFile()
{
  ifstream inFile;
  inFile.open("Ticket_time.txt");
  int TimeCounter = 0;
  if (inFile.is_open()) 
  {
    for(size_t i = 0; i < LOCATION_TIME_MAX; i++)
    {
      inFile >> times[i];
    }
    inFile.close();
  } 
  else 
    cout << "Error opening file." << endl;
};

double Ticket::PriceCalculation(int startChoice,int endChoice, int age)
{
  readPriceFromFile();
  double diff = static_cast<double>(startChoice - endChoice);
  double absoluteDiff = sqrt(diff*diff);
  double result = absoluteDiff * Multiplier;
  if (0 <= age && age < 60)
    return result;
  else
    return 0; 
};

void Ticket::readPriceFromFile()
{
  ifstream inFile;
    inFile.open("Ticket_price.txt");
    if (inFile.is_open()) 
    {
      inFile >> Multiplier;
      inFile.close();
    } 
    else 
      cout << "Error opening file." << endl;
}

void Ticket::writeUserInfoToFile(int startChoice, int endChoice, int age, double price, int referenceNumber)
{

  ofstream outFile;
  outFile.open("Ticket_userInfo.txt", ios::app);
  if (outFile.is_open()) 
  {
    outFile << Username << " " << Train << " " << startChoice << " " << endChoice << " " << age << " " << 
    fixed << setprecision(2) << price << " " << referenceNumber << endl;
    outFile.close();
  } 
  else 
  {
    cout << "Error opening file." << endl;
  }
};

void  Ticket::readUserInfoFromFile()
{
  ifstream inFile;
  inFile.open("Ticket_userInfo.txt");
  if (inFile.is_open()) 
  {
    while (inFile >> UserInfo[0] >> UserInfo[1] >> UserInfo[2] >> UserInfo[3]>> UserInfo[4] >> UserInfo[5] >> UserInfo[6])
        {
            if (UserInfo[0] == Username) 
                break;
        }
    inFile.close();
  }
  else 
    cout << "Error opening file." << endl; 
};

int Ticket::generateReferenceNumber()
{
  int referenceNumber;
  readReferenceFromFile();
  for (int i = 0; i <= 9999; i++)
  {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10000000, 99999999);
    referenceNumber = dis(gen);
    if (referenceNumber == Reference[i])
      continue;
    else 
      break;
  }
  writeReferenceToFile(referenceNumber);
  return referenceNumber;
};

void Ticket::readReferenceFromFile()
{
  ifstream inFile;
  inFile.open("Ticket_reference.txt");
  if (inFile.is_open()) 
  {
    for (int i = 0; i <= 9999; i++)
    {
      inFile >> Reference[i];
    }
    inFile.close();
  }
  else 
    cout << "Error opening file." << endl; 
}

void Ticket::writeReferenceToFile(int referenceNumber)
{
  ofstream outFile;
  outFile.open("Ticket_reference.txt", ios::app);
  if (outFile.is_open()) 
  {
    outFile << referenceNumber << endl;
    outFile.close();
  } 
  else 
  {
      cout << "Error opening file." << endl;
  }

}

void Ticket::refundTicket()
{
  int referenceNumber; string anything;
  while(1)
  {
    cout<< "--------------------------------------------\n"
        << "           Welcome back, " << Username << " \n"
        << "--------------------------------------------\n"
        << "Refund process initiated.\n" 
        << "Enter your ticket reference number: ";
  cin >> referenceNumber;
  if (10000000 < referenceNumber && referenceNumber < 99999999)
      referenceNumber = referenceNumber;
  else
    {
      cout << "Ticket not found." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter anything to retry." << endl;
      cin >> anything;
      system("cls");
      continue;
    }    
  
    readReferenceFromFile(); 
    for (int i = 0; i < 10000; i++)
    {
      if (referenceNumber == Reference[i])
      {
        removeTicket(referenceNumber,i);
        break;
      }
      if (referenceNumber != Reference[9999])
      {
        cout << "Ticket not found." << endl;
        cout << "Enter anything to return to the Menu" << endl;
        cin >> anything;
        system("cls");
        break;
      }
    }
    break;
  }
}

void Ticket::removeTicket(int referenceNumber, int index)
{
  ifstream OriginFile;
  OriginFile.open("Ticket_reference.txt");
  ofstream outFile;
  outFile.open("temp.txt", ios::app);
  if (outFile.is_open()) 
  {
    for (int i = 0; i < 10000; i++)
    {
      if (Reference[i] != Reference[index])
        outFile << Reference[i] << endl;
    }
    outFile.close();
    OriginFile.close();
    const char * p = "Ticket_reference.txt";
    remove(p);
    rename("temp.txt", p);
  } 
  else 
  {
      cout << "Error opening file." << endl;
  }

  readUserInfoFromFile(); 

  string line;
  string eraseLine = UserInfo[0] + " " + UserInfo[1] + " " + UserInfo[2] + " " + UserInfo[3] + " " + UserInfo[4] + " " + UserInfo[5];
  ifstream ogFile;
  ogFile.open("Ticket_userInfo.txt");
  ofstream editFile;
  editFile.open("temp2.txt", ios::app);
  if (editFile.is_open())
  {
    while (getline(ogFile, line))
      {
        if (line != eraseLine)
          editFile << line << endl;
      }
    ogFile.close();
    editFile.close();
    const char * q = "Ticket_userInfo.txt";
    remove(q);
    rename("temp2.txt", q);
  }
  else 
  {
      cout << "Error opening file." << endl;
  }
  cout << "\nYour ticket has been removed" << endl;
  cout << "RM " << UserInfo[4] <<" has been refunded to your bank account" << endl;
  readUserInfoFromFile();
  string anything;
  cout << "Enter anything to return to the Menu" << endl;
  cin >> anything;
  system("cls");
};

void Ticket::ticketsbought()
{
  readLocationFromFile();
  readTimeFromFile();
  readUserInfoFromFile();
  
  while(1)
  {
    if (UserInfo[0] != Username)
    {
      cout << "-\n";
      break;
    }
    cout<< "\nTicket Reference:\t" << UserInfo[4] << endl;
    cout<< "Starting Location:\t" << places[stoi(UserInfo[2]) - 1] 
        <<"\nEnding Location:\t"  << places[stoi(UserInfo[3]) - 1] 
        <<"\nTime of Departure:\t"<< times[departureTime(UserInfo[1],UserInfo[2])] << endl
        <<"Estimated Time of Arrival:\t" << times[arrivalTime(UserInfo[1],UserInfo[2],UserInfo[3])] << endl
        <<"Age:\t" << UserInfo[3] << endl
        <<"Price:\t" << UserInfo[4] << endl;
    cout<<".\n.\n";
    break;
  }
}

int Ticket::TrainSelector(int a)
{
  if (a > 10)
  {
    Train = 2;
    return a - 10;
  }
  else
  {
    Train = 1;
    return a;
  }

};

int Ticket::departureTime(string trainNumber, string start)
{
  int a = stoi(start);
  int b = stoi(trainNumber);
  if (b == 1)
    return a;
  else
    return PlacesCounter - a;
};

int Ticket::arrivalTime(string trainNumber,string start, string end)
{

  int a = stoi(start);
  int b = stoi(end);
  int c = stoi(trainNumber);
  if (c == 1)
    return b;
  else
    return a;
  
}
// Getters for Name and Password
string* Ticket::getLocation()
{
    return places;
};
string* Ticket::getTime()
{
    return times;
}
int Ticket::getPlacesCounter()
{
  return PlacesCounter;
}
int Ticket::getTrain()
{
  return Train;
}

int* Ticket::getReference()
{
  return Reference;
}
void Ticket::setUserName(string username1)
{
  Username = username1;
}
