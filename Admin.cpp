#include "Admin.hpp"

void Admin::AdminMainMenu(string username)
{
  Username = username;
  int number = 1;
  while(number == 1)
  {
    int choice = AdminMenu();
    switch (choice)
    {
    case 1 :
        system("cls");
        editPlaces();
        editTimes();
        break;
    case 2 :
        system("cls");
        editPrice();
        break;
    case 3 :
        system("cls");
        editTicket();
        break;
    case 4 :
        system("cls");
        number = 0;
        break;
    default:
        break;
    }
  }

};

int Admin::AdminMenu()
{
    while (1)
    {
        int userPick; string anything; 
        system("cls");
        cout<< "--------------------------------------------\n"
            << "           Welcome back, " << Username << " \n"
            << "--------------------------------------------\n"
            << "--------------------------------------------\n"
            << ">>>>>>>>>>>>ADMINSTRATOR MODE<<<<<<<<<<<<<<<\n"
            << "--------------------------------------------\n";
            cout<< "\n-*Please select an option from the menu below*-\n\n"
                << "1. Edit Location and Time" << endl
                << "2. Edit Price" << endl
                << "3. View Bought Tickets" << endl
                << "4. Return to Main Menu\n" << endl
                << "Please select your choice (1 - 4): ";
        cin >> userPick;
        cout << endl;
        if (0 < userPick && userPick < 5)
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

void Admin::editPlaces ()
{
    int number = 1;
    while(number == 1)
    {
    cout<< "---------------------------------------------------------------------------\n"
        << "*******************************TAKE NOTE !!!*******************************\n"
        << "---------------------------------------------------------------------------\n"
        << "---------------------------------------------------------------------------\n"
        << "*For every place removed/added, a corresponding time must be removed/added*\n"
        << "---------------------------------------------------------------------------\n\n";

    string fileName = "Ticket_location.txt";
    vector<string> places = readPlacesFromFile(fileName);
    cout << "----------------------------------------------------" << endl ;
    cout << "Current places: " << endl;
    cout << endl ;
    for (int i = 0; i < places.size(); i++)
        cout << i + 1 << ". " << places[i] << endl;
    
    cout << endl;
    cout << "----------------------------------------------------\n" << endl ;
    
    int choice = editPlacesMenu();
    switch (choice)
    {
    case 1 :
        system("cls");
        while(true)
        {
            cout << "Enter a new place (e.g Kuala_Lumpur) or 0 to exit : ";
            string newPlace;
            cin >> newPlace;
            if(newPlace == "0")
                break;
            cout << "\nPlease confirm the addition of " << newPlace << "\nEnter 1 to confirm, 0 to exit" <<endl;
            int addChoice = confirmationCheck();
            if (addChoice == 1)
                {
                    addPlace(places, newPlace);
                    system("cls");
                    break;
                }
            else
                break;
        };
        break;
    case 2 :
        system("cls");
        while(true)
        {
            cout << "Enter a place (e.g Kuala_Lumpur) to remove or 0 to exit : ";
            string placeToRemove;
            cin >> placeToRemove;
            if(placeToRemove == "0")
                break;
            cout << "\nPlease confirm the removal of " << placeToRemove << "\nEnter 1 to confirm, 0 to exit" <<endl;
            int removeChoice = confirmationCheck();
            if (removeChoice == 1)
                {
                    removePlace(places, placeToRemove);
                    system("cls");
                    break;
                }
            else
                break;
        };
        break;
    case 3 :
        system("cls");
        number = 0;
        break;
    default:
        break;
    }
    writePlacesToFile(places, fileName);
    
  }
};

int Admin::editPlacesMenu()
{
    int userPick; string anything;
    while (1)
    {
        cout<< "-----------------------------------------------\n"
            << "               Location Editor                 \n"
            << "-----------------------------------------------\n" << endl
            << "-*Please select an option from the menu below*-\n"
            << "1. Add Location\n"
            << "2. Remove Location\n"
            << "3. Go to Time Editor\n" << endl
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
}

void Admin::addPlace(vector<string> &places, string newPlace)
{
    if (find(places.begin(), places.end(), newPlace) == places.end())
    {
        places.push_back(newPlace);
        cout << "Place added successfully!" << endl;
    }
    else
    {
        cout << "Place already exists in the system!" << endl;
    }
}

void Admin::removePlace(vector<string> &places, string placeToRemove)
{
    auto it = find(places.begin(), places.end(), placeToRemove);
    if (it != places.end())
    {
        places.erase(it);
        cout << "Place removed successfully!" << endl;
    }
    else
    {
        cout << "Place does not exist in the system!" << endl;
    }
}

void Admin::writePlacesToFile(vector<string> &places, string fileName)
{
    ofstream file(fileName);

    for (string place : places)
    {
        file << place << endl;
    }

    file.close();
}

vector<string> Admin::readPlacesFromFile(string fileName)
{
    vector<string> places;
    string line;
    ifstream file(fileName);

    while (getline(file, line))
    {
        places.push_back(line);
    }

    file.close();

    return places;
}

void Admin::editTimes ()
{   
    int number = 1;
    while(number == 1)
    {
        cout<< "---------------------------------------------------------------------------\n"
        << "*******************************TAKE NOTE !!!*******************************\n"
        << "---------------------------------------------------------------------------\n"
        << "---------------------------------------------------------------------------\n"
        << "*For every place removed/added, a corresponding time must be removed/added*\n"
        << "---------------------------------------------------------------------------\n\n";
        string fileName = "Ticket_time.txt";
        vector<string> time = readTimeFromFile(fileName);
        cout << "----------------------------------------------------" << endl ;
        cout << "Current time: " << endl;
        cout << endl ;
        for (int i = 0; i < time.size(); i++)
            cout << i + 1 << ". " << time[i] << endl;
        cout << endl ;
        cout << "----------------------------------------------------\n" << endl ;
        int choice = editTimesMenu();
        switch (choice)
        {
        case 1 :
            system("cls");
            while(true)
            {
                string newTime;
                cout << "Enter a new time (e.g 7.00_AM) or 0 to exit : ";
                cin >> newTime;
                if(newTime == "0")
                    break;
                cout << "\nPlease confirm the addition of " << newTime << "\nEnter 1 to confirm, 0 to exit" <<endl;
                int addChoice = confirmationCheck();
                if (addChoice == 1)
                {    
                    addTime(time, newTime);
                    system("cls");
                    break;
                }
                else
                    break;
            }
            break;
        case 2 :
            system("cls");
            while(true)
            {
                cout << "Enter a time (e.g 7.00_AM) to remove or 0 to exit : ";
                string timeToRemove;
                cin >> timeToRemove;
                if(timeToRemove == "0")
                    break;
                cout << "\nPlease confirm the removal of " << timeToRemove << "\nEnter 1 to confirm, 0 to exit" <<endl;
                int removeChoice = confirmationCheck();
                if (removeChoice == 1)
                    {
                        removeTime(time, timeToRemove);
                        system("cls");
                        break;
                    }
                else
                    break;
            };
            break;
        case 3 :
            system("cls");
            number = 0;
            break;
        default:
            break;
        }
        writeTimeToFile(time, fileName);
        
    }
};

int Admin::editTimesMenu()
{
    int userPick; string anything;
    while (1)
    {
        cout<< "-----------------------------------------------\n"
            << "                   Time Editor                 \n"
            << "-----------------------------------------------\n" << endl
            << "-*Please select an option from the menu below*-\n"
            << "1. Add Time\n"
            << "2. Remove Time\n"
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

void Admin::addTime(vector<string> &time, string newTime)
{
    if (find(time.begin(), time.end(), newTime) == time.end())
    {
        time.push_back(newTime);
        cout << "time added successfully!" << endl;
    }
    else
    {
        cout << "Time already exists in the system!" << endl;
    }
}

void Admin::removeTime(vector<string> &time, string timeToRemove)
{
    auto it = find(time.begin(), time.end(), timeToRemove);
    if (it != time.end())
    {
        time.erase(it);
        cout << "time removed successfully!" << endl;
    }
    else
    {
        cout << "time does not exist in the system!" << endl;
    }
}

void Admin::writeTimeToFile(vector<string> &time, string fileName)
{
    ofstream file(fileName);

    for (string time : time)
    {
        file << time << endl;
    }

    file.close();
}

vector<string> Admin::readTimeFromFile(string fileName)
{
    vector<string> time;
    string line;
    ifstream file(fileName);

    while (getline(file, line))
    {
        time.push_back(line);
    }

    file.close();

    return time;
}

int Admin::confirmationCheck()
{
    int confirmation; string anything;
    while(1)
    {
        cin >> confirmation;
        cout << endl;
        if (0 <= confirmation && confirmation < 2)
            return confirmation;
        else
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter anything to retry." << endl;
            cin >> anything;
        }
    }
}

void Admin::editTicket()
{
    Ticket input;
    place = input.getLocation();
    time = input.getTime();
    PlacesCounter = input.getPlacesCounter();
    input.readLocationFromFile();
    input.readTimeFromFile();
    readAllUserInfo();
    cout << "Current Tickets: " << endl;
    cout << endl ;
    cout<< "--------------------------------------------------------------------------------------------------------------------\n"
        <<"Username\t\tAge\t\tTrain\t\tStarting Location\t\tEnding Location\t\tDeparture Time\t\tArrival Time\t\tPrice\t\t Reference Number\n";
    for (int i = 0; i < 10000; i++)
    {   if (i%7 != 0)
            continue;
        else
        {
            string start = *(place + stoi(AllUserInfo[i+2]));
            string end = *(place + stoi(AllUserInfo[i+3]));
            string start_time = *(time + input.departureTime(AllUserInfo[i+1],AllUserInfo[i+2]));
            string end_time = *(time + input.arrivalTime(AllUserInfo[i+1],AllUserInfo[i+2],AllUserInfo[i+3]));
            cout << i + 1 << ". " << AllUserInfo[i] << "\t\t" << AllUserInfo[i+4] << "\t\t" <<AllUserInfo[i+1] << "\t\t" << start << "\t\t" << end 
            << "\t\t" << start_time << "\t\t" << end_time << "\t\t" << AllUserInfo[i+5] << "\t\t" << AllUserInfo[i+6] << endl;
        }
    }
    
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------\n" << endl ;
    int number = 1;
    while(number == 1)
    {
        int choice = editTicketMenu();
        switch (choice)
        {
        case 1 :
            system("cls");
            addTicket();
            break;
        case 2 :
            system("cls");
            deleteTicket();
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

int Admin::editTicketMenu()
{
    int userPick; string anything;
    while (1)
    {
        cout<< "-----------------------------------------------\n"
            << "                 Ticket Editor                 \n"
            << "-----------------------------------------------\n" << endl
            << "-*Please select an option from the menu below*-\n"
            << "1. Add Ticket\n"
            << "1. Remove Ticket\n"
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

void Admin::readAllUserInfo()
{
    ifstream inFile;
    inFile.open("Ticket_userInfo.txt");
    if (inFile.is_open()) 
    {
    for (int i = 0; i < 60000; i++)
    {
        inFile >> AllUserInfo[i];
            if (AllUserInfo[i] == "")
                break;
    }
    inFile.close();
    }
    else 
    cout << "Error opening file." << endl; 

};

void Admin::addTicket()
{
    int age, startChoice, endChoice, referenceNumber, confirmation; string anything;
    double price;

    Ticket input2; string username1;

    while(1)
  {

    cout << "Please enter the username: ";
    cin >> username1;
    input2.setUserName(username1);
    age = input2.askAge();
    startChoice = input2.startLocationMenu(); 
    endChoice = input2.TrainSelector(input2.endLocationMenu(startChoice));
    price = input2.PriceCalculation(startChoice,endChoice,age);
    referenceNumber = input2.generateReferenceNumber();

    cout<< "The total for the ticket is RM " << fixed << setprecision(2) << price << endl;
    cout<< "\nPlease confirm the addition of:\n" << endl;
    cout<< "Ticket Reference:\t" << referenceNumber << endl;
    cout<< "Starting Location:\t" << *(place + startChoice - 1) 
        << "\nEnding Location:\t" << *(place + endChoice - 1) 
        << "\nTime of Departure:\t" ;
    if(input2.getTrain() == 1 )
      cout << time + startChoice - 1 << endl;
    else
      cout << *(time + PlacesCounter - startChoice - 1) << endl;

    cout<< "\nEnter 1 to confirm and 0 to cancel: "; 
    cin >> confirmation;
    cout << endl;
    if (0 <= confirmation && confirmation < 2)
    {
      if(confirmation == 0)
        break;
      else
      {
        input2.writeUserInfoToFile(startChoice,endChoice,age,price,referenceNumber);
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

void Admin::deleteTicket()
{
    int referenceNumber; string anything; Ticket input3; 
  while(1)
  {
    cout<< "--------------------------------------------\n"
        << ">>>>>>>>>>>>ADMINSTRATOR MODE<<<<<<<<<<<<<<<\n"
        << "--------------------------------------------\n"
        << "Ticket Deletion initiated.\n" 
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
    
    input3.readReferenceFromFile(); 
    int *Reference = input3.getReference();
    for (int i = 0; i < 10000; i++)
    {    
      if (referenceNumber == Reference[i])
      {
        input3.removeTicket(referenceNumber,i);
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
};

void Admin::editPrice()
{
    
    int number = 1;
    while(number == 1)
    {
        int choice = editPriceMenu();
        switch (choice)
        {
        case 1 :
            system("cls");
            editPriceFile();
            break;
        case 2 :
            system("cls");
            number = 0;
            break;
        default:
            break;
        }
    }
};

int Admin::editPriceMenu()
{
    int userPick; string anything;
    while (1)
    {
        readPriceFile();
        cout << "The price of ticket is calculated by using Number of Stations Travelled multiplied by a constant" << endl;
        cout << "The current Price Multiplier is " << PriceMultplier << endl;    
        cout<< "\n-----------------------------------------------\n"
            << "                   Price Editor                 \n"
            << "-----------------------------------------------\n" << endl
            << "-*Please select an option from the menu below*-\n"
            << "1. Edit Price\n"
            << "2. Return to Main Menu\n" << endl
            << "Please select your choice (1 or 2): ";
        cin >> userPick;
        cout << endl;
        if (0 < userPick && userPick < 3)
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


void Admin::editPriceFile()
{
    string anything;
    while(1)
    {
        cout << "New Price Multipler: ";
        cin >> PriceMultplier;
        if (0 < PriceMultplier && PriceMultplier < 100)
            break;
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
    fstream OriginFile;
    OriginFile.open("Ticket_price.txt");
    ofstream outFile;
    outFile.open("temp.txt", ios::app);
    if (outFile.is_open()) 
    {
        outFile << PriceMultplier << endl;
        outFile.close();
        OriginFile.close();
        const char * p = "Ticket_price.txt";
        remove(p);
        rename("temp.txt", p);
    } 
    else 
    {
        cout << "Error opening file." << endl;
    }

    cout << "Price Multipler has been changed to X " << PriceMultplier << " times" << endl;
    cout << "Enter anything to return to the Menu" << endl;
    cin >> anything;
    system("cls");


}
void Admin::readPriceFile()
{
    ifstream inFile;
    inFile.open("Ticket_price.txt");
    if (inFile.is_open()) 
    {
        while(inFile >> PriceMultplier)
            if (PriceMultplier = 0)
                break;
        inFile.close();
    }
    else 
    cout << "Error opening file." << endl; 

}