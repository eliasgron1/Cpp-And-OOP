#ifndef USER_HPP
#define USER_HPP

using namespace std;


class User : public Person{
    friend class Admin;
private:

    char permissions[3];
    string username;
    string password;

    void setPermissions(char*);
    void removePermissions(char*);


public:

    bool comparePhoneNumber(User);

    string getPermissions();
    string getUsername();

    User();

};

#endif