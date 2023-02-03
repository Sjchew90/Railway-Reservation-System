#include "Ticket.hpp"

class Admin
{
    private:
    string Username;
    string AllUserInfo [70000];
    string NewTicketInfo [7];
    int PlacesCounter;
    string *place;
    string *time;
    double PriceMultplier;

    public:
    // Location Editor
    void addPlace(vector<string> &, string );
    void removePlace(vector<string> &, string );
    void writePlacesToFile(vector<string> &, string );
    vector<string> readPlacesFromFile(string );
    void editPlaces ();
    int editPlacesMenu();

    // Time Editor
    void addTime(vector<string> &, string);
    void removeTime(vector<string> &, string);
    void writeTimeToFile(vector<string> &, string);
    vector<string> readTimeFromFile(string );
    void editTimes ();
    int editTimesMenu();

    // Menu
    int AdminMenu();
    void AdminMainMenu(string);

    // Price Editor
    void editPrice();
    int editPriceMenu();
    void readPriceFile();
    void editPriceFile();

    //Ticket Editor
    void editTicket();
    int editTicketMenu();
    void addTicket();
    void deleteTicket();

    //Ticket Info Editor
    void readAllUserInfo();
    void writeUserInfo();

    //Confirmation
    int confirmationCheck();
};
