#include "Account.hpp"
#define LOCATION_TIME_MAX 10 


class Ticket
{
    private:
    string places[LOCATION_TIME_MAX];
    string times[LOCATION_TIME_MAX];
    int PlacesCounter = 0;
    int Train;
    string Username;
    string UserInfo[7];
    int Reference[100000];
    double Multiplier;
    public:
    Ticket() = default;

    // Function Declaration //

    // Ticket Menu
    void ticketMainMenu(string);
    int ticketMenu();

    //Buy
    void buyTicket();
    int startLocationMenu();
    int endLocationMenu(int);
    int endLocationMenu2(int,int);

    int generateReferenceNumber();
    void ticketsbought();

    //Refund
    void refundTicket();
    void removeTicket(int,int);

    void readLocationFromFile();
    void readTimeFromFile();
    
    double PriceCalculation(int,int,int);
    void readPriceFromFile();
    
    
    void writeReferenceToFile(int);
    void readReferenceFromFile();

    // To Edit Ticket_userInfo.txt
    void writeUserInfoToFile(int,int,int,double,int);
    void readUserInfoFromFile();

    int askAge();
    int TrainSelector(int);
    int arrivalTime(string,string,string);
    int departureTime(string,string);
    // Setters and Getters
    //void setLocation(string[]);
    //void setTime(string[][TIME_COL_MAX]);
    //void setUserInfo(string,string,string);
    string* getLocation();
    string* getTime();
    int getPlacesCounter();
    int getTrain();
    void setUserName(string);
    int* getReference();
    //string getUserInfo(string[5]);
    
    




};