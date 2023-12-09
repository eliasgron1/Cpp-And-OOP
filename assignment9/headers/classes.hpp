#ifndef CLASSES_HPP
#define CLASSES_HPP

using namespace std;

class Person{
private:
    string name_first;
    string name_last;
    string address;

public:
    Person();

    void setPersonData(string, string, string);
    void printPersonData(void);

    Person* searchPerson(string);

};


class Profession{
private:
    string title;
    int years_of_exp;
    float latest_salary;
public:
    Profession();

    string getTitle(void);
    void setTitle(string);
    float getSalary(string);
    void setLatestSalary(float);
    void setExperience(int);
    int getExperience();
};



class Employee : public Profession, public Person{
private: 
    int id;
    float salary;
    float tax_rate;
    static string firm;
public:
    Employee(int, float, float, int, string, string, string, string);
    Employee();

    static void setFirm(string);
    static string getFirm();
    float getNetSalary();
    void print();

};

#endif