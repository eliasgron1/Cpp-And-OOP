#ifndef CLASS_H
#define CLASS_H

class Admin;

class User{
    friend class Admin;
private:
    std::string name_first;
    std::string name_last;
    std::string phone_number;
    std::string username;
    std::string password;

public:
    std::string getInfo(void);
    User* Search(std::string);

    User(std::string, std::string, std::string);
    User();
    ~User();

};

class Admin{
private:
    static const std::string admin_password;
    static const std::string admin_username;

public:
    bool Authenticate(void);
    void setUsername(const std::string, User& );
    void setPassword(const std::string, User& );
};




#endif