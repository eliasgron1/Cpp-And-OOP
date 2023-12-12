#ifndef PERSON_HPP
#define PERSON_HPP

using namespace std;

class User;

class Person{
    private:
    string first_name;
    string last_name;
    string phone_number;

    public:

    string getPhoneNumber();
    void setPersonInformation(string, string, string);
    string toString(User&);
    Person* search(string);

    Person();
};

#endif