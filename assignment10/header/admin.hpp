#ifndef ADMIN_HPP
#define ADMIN_HPP

using namespace std;

class Admin : public Person{
private:
    static const string admin_password;
    static const string admin_username;

public:
    bool authenticate();
    void setUsername(const std::string, User&);
    void setPassword(const std::string, User&);
    void setPermissions(User, char*);
    void removePermissions(User, char*);
};

#endif