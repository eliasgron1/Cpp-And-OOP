#ifndef CLASSES_HPP
#define CLASSES_HPP

using namespace std;

class Person{
private:
    string name_first;
    string name_last;
    string address;

public:
    Person(string, string, string);
    Person();

};

class Profession{
private:
    string title;
    int years_of_exp;
    float latest_salary;
public:
    Profession(string, int, float);
    Profession();

    float getSalary();
    string getFirm();
    float getNetSalary();
    int getExperience();
};

class Employee : private Profession, private Person{
private: 
    int id;
    float salary;
    float tax_rate;
    static string firm;
public:
    Employee(int, float, float, string);
    Employee();

    void setFirm();
    string getFirm();
    float getNetSalary();
    void print();


};

#endif