#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>

using namespace std;


class Employee{
string name;
string job;
int id;
float salary;


public:
    void update (string, string, int, float);
    int* search (string, string, int);
    string to_string ();

};


int main(){



}

Employee::Employee(string name, string job, int id, float salary){
this->name = name;
this->job = job;
this->id = id;
this->salary = salary;
}
Employee::Employee(){
this->name = "name:not_known";
this->job = "job:not_known";
this->id = 0;
this->salary = 0;
}
