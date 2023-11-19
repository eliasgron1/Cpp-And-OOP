#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<cctype>


using namespace std;


class Employee{
private:
    string name;
    string job;
    float salary;


public:
    int id;
    Employee(string, string, int, float);
    Employee();

    void update(void);
    int* search(string, string, int);
    void toString(void);

};


void printMenu(void);
Employee* addEmployee(void);

// MAIN

int main(){
char command;
int employee_count = 0;

vector<Employee*> employee;


while(command != 'X'){
printMenu();
    cin >> command;
    command = toupper(command);


switch(command){
    case 'A':
        employee.push_back(addEmployee());
        employee_count++;
        break;


    case 'P':
        cout << "printing" << endl;
        for (auto it : employee){ it->toString(); }
        break;
}


}

return 0;
}




// CONSTRUCTORS

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




// METHODS

void Employee::update(){


}

void Employee::toString(){
cout << "- - - - - - - - - - - - - - - -" << endl;
cout << "Id: "     << this->id     << endl;
cout << "Name: "   << this->name   << endl;
cout << "Job: "    << this->job    << endl;
cout << "Salary: " << this->salary << endl;
cout << "- - - - - - - - - - - - - - - -" << endl;

}




// FUNCTIONS

Employee* addEmployee(){
Employee* employeeObj = new Employee;
string name;
string job;
int id;
float salary;

cout << "Enter employee id: ";
    cin >> id;

cout << "Enter employee name: ";
    cin >> name;

cout << "Enter employee job: ";
    cin >> job;

cout << "Enter employee salary: ";
    cin >> salary;

*employeeObj = Employee(name,job,id,salary);
return employeeObj;



}


void printMenu(){
cout << "**************************************************" << endl;
cout <<" A " << setw(10) << "Add employee" << endl;
cout <<" R " << setw(10) << "Remove employee" << endl;
cout <<" P " << setw(10) << "Print data" << endl;
cout <<" S " << setw(10) << "Search employee" << endl;
cout <<" X " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
}


