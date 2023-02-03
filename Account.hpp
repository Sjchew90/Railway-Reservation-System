#include "main.hpp"

struct Account
{
    private:
    string username;
    string password;
    string ReadName;
    string ReadPass;
    string ReadAdminName;
    // Function Declaration
    void readAccountFromFile();
    int verification();
    void writeAccountToFile();
    
    public:
    Account() = default;
    // Function Declaration

    // Setters and Getters
    void setName(string);
    void setPass(string);
    string getName();
    string getPass();
    

    // Login 
    void login();
    
    // Create Acount
    void signUp();
    
    // Check for admin
    bool readAdminNameFromFile();
};