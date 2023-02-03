#include "Admin.hpp"

int main()
{
    int number = 1;
    while (number == 1)
    {
        int UserChoice = ETSMainMenu();
        Account functions;
        Ticket functions2;
        Admin functions3;

        switch (UserChoice)
        {
        case 1 :
            system("cls");
            functions.login();
            if(functions.readAdminNameFromFile())
                functions3.AdminMainMenu(functions.getName());
            else
                functions2.ticketMainMenu(functions.getName());
            break;

        case 2 :
            system("cls");
            functions.signUp();
            break;
        case 3 :
            number = 0;
        default:
            break;
        }

    }


    return 0;
}



int ETSMainMenu()
{
    int userPick; string anything;
    while (1)
    {
        cout << "    !WELCONE TO RAILWAY RESERVATION SYSTEM!\n";
        cout << "-----------------------------------------------\n";
        cout << "            ETS Reservation System\n";
        cout << "-----------------------------------------------\n" << endl;
        cout << "-*Please select an option from the menu below*-\n";
        cout << "1. Login\n";
        cout << "2. Create a NEW Account\n";
        cout << "3. Quit \n" << endl;
        cout << "Please select your choice (1, 2 or 3): ";
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

