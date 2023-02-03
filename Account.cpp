#include "Account.hpp"
#define ACCOUNTS_FILE "Account.txt"

//Login
void Account::login()
{
    string inputName, inputPass;
    while (1)
    {
        cout<< "--------------------------------------------\n"
            << "           Log into your account\n"
            << "--------------------------------------------\n"
            << "Please enter your username: ";
        cin >> inputName;
        cout<< "Please enter your password: ";
        cin >> inputPass;

        // Setters
        setName(inputName);
        setPass(inputPass);

        if (verification() == 1)
            break;
    }

}

// Login verification
int Account::verification()
{
    readAccountFromFile();
    string inputPass, anything;
    if (username == ReadName)
    {
        for (int i = 0; i < 3; i++)
        {
            if (password == ReadPass)
            {   
                cout << "\nLOGIN SUCCESSFUL!" << endl;
                break;
            }
            else
            {   
                if (i < 3)
                {
                    cout << "\nPassword is wrong!!!" << endl;
                    cout << "Please enter your password again!" << endl;
                    cout << "You have " << 3 - i << " tries left" << endl;
                    cout << "Please enter your password: ";
                    cin >> inputPass;
                    setPass(inputPass);
                }
                else
                    cout << "Please try logging in again" << endl;
            }
        }
        cout << "Enter anything to continue." << endl;
        cin >> anything;
        system("cls");
        return 1;
    }
    else
    {
        cout << "\nUsername does not exist!!!" << endl;
        cout << "Please enter your username again!" << endl;
        cout << "Enter anything to continue." << endl;
        cin >> anything;
        system("cls");
        return 0;
    }
};

// Read Account Name and Password from text file
void Account::readAccountFromFile()
{
    ifstream inFile;
    inFile.open(ACCOUNTS_FILE);
    if (inFile.is_open()) 
    {
        while (inFile >> ReadName >> ReadPass)
        {
            if (ReadName == username) 
                break;
        }
        inFile.close();
    } 
    else 
    {
        cout << "Error opening file." << endl;
    }

}

// Read Admin Name from text file
bool Account::readAdminNameFromFile()
{
    ifstream inFile;
    inFile.open("Admin.txt");
    if (inFile.is_open()) 
    {
        while (inFile >> ReadAdminName)
        {
            if (ReadAdminName == username) 
            {
                return 1;
                break;
            }
        }
        inFile.close();
    } 
    else 
    {
        cout << "Error opening file." << endl;
    }
    return 0;
} 

// Create Account
void Account::signUp() 
{
    string inputName, inputPass, anything;
    cout<< "-----------------------------------------\n" 
        << "           CREATE an account\n"
        << "-----------------------------------------\n"
        << "Enter a username for your account: ";
    cin >> inputName;
    cout<< "Enter a password for your account: ";
    cin >> inputPass;
    cout<< "\nYour account has been created SUCCESSFULLY!\n";

    // Setters
    setName(inputName);
    setPass(inputPass);
    
    //Add into text
    writeAccountToFile();
    cout << "Enter anything to return to main menu." << endl;
    cin >> anything;
    system("cls");
    
}
   
// Write Account Name and Password to text file   
void Account::writeAccountToFile()
{
    ofstream outFile;
    outFile.open(ACCOUNTS_FILE, ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << endl;
        outFile.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

//Getters for Name and Password
string Account::getName()
{
    return username;
};
string Account::getPass()
{
    return password;
};

//Setters for Name and Password
void Account::setName(string inputName)
{
    username = inputName;
};
void Account::setPass(string inputPass)
{
    password = inputPass;
}; 