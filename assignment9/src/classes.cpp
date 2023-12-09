#include"../headers/classes.hpp"

// PROFESSION METHODS

float Profession::getSalary(string title){
    if (this->title == title){
        return this->latest_salary;
    } 
    else{
        return 0;
    }
}

void Profession::setLatestSalary(float salary){
    this->latest_salary = salary;
}

void Profession::setTitle(string title){
    this->title = title;
}

string Profession::getTitle(){
    return this->title;
}

void Profession::setExperience(int exp){
    this->years_of_exp=exp; 
}

int Profession::getExperience(){
    return this->years_of_exp;
}

Profession::Profession(){
    this->title="title";
    this->latest_salary=0;
    this->years_of_exp=0;
}



// EMPLOYEE METHODS

string Employee::firm;

void Employee::print(){

    cout << "\n\n....................................";
    this->printPersonData();
    cout << "\nid: " << id;
    cout << "\nfirm: " << firm;
    cout << "\nnet salary: " << getNetSalary();
    cout << "\ntax rate: " << tax_rate;

    cout << "\nexperience: " << getExperience();
    cout << "\ntitle: " << getTitle();


}

float Employee::getNetSalary(){
    return this->salary - ((this->tax_rate/100) * this->salary);
}

string Employee::getFirm(){
    return Employee::firm;
}

void Employee::setFirm(string firm_name){
    Employee::firm = firm_name;
}

Employee::Employee(int id, float salary, float tax_rate, int years_of_exp, string title, string name_first, string name_last, string address){
    this->id=id;
    this->salary=salary;
    this->tax_rate=tax_rate;
    this->setExperience(years_of_exp);
    this->setTitle(title);
    this->setPersonData(name_first, name_last, address);
    this->setLatestSalary(salary);
}

Employee::Employee(){
    this->id=0;
    this->salary=0;
    this->tax_rate=0;
}




// PERSON METHODS

Person* Person::searchPerson(string name){
    if(name == this->name_last || name == this->name_first){
        return this;
    }
    else{
        return NULL;
    }
}

void Person::setPersonData(string name_first, string name_last, string address){
    this->name_first = name_first;
    this->name_last = name_last;
    this->address = address;
}

void Person::printPersonData(){
    cout << "\nfirst name: " << this->name_first;
    cout << "\nlast name: " << this->name_last;
    cout << "\naddress: " << this->address;
}

Person::Person(){
this->name_first="name_first";
this->name_last="name_last";
this->address="address;";
}