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
    int id;


public:
    Employee(string, string, int, float);
    Employee();
    ~Employee();

    Employee* search(int);
    void toString(void);
    void update(void);

};



void deleteEmployee(vector<Employee>);
void searchEmployee(vector<Employee>);
void printMenu(void);
void addEmployee(vector<Employee>&);


// MAIN

int main(){
char command;

vector<Employee> employee;

while(command != 'X'){
printMenu();
    cout << employee.size() << endl;
    cin >> command;
    command = toupper(command);

switch(command){
    case 'A':
        addEmployee(employee);
        break;

    case 'P':
        for (auto obj : employee){ {obj.toString(); }}
        break;
    
    case 'S':
        searchEmployee(employee);
        break;


}
}
return 0;
}





// METHODS

void Employee::toString(){
cout << "- - - - - - - - - - - - - - - -" << endl;
cout << "Id: "     << this->id     << endl;
cout << "Name: "   << this->name   << endl;
cout << "Job: "    << this->job    << endl;
cout << "Salary: " << this->salary << endl;

}


Employee* Employee::search(int id){
if(this->id == id){ return this; }

return NULL;
}





// FUNCTIONS



void searchEmployee(vector<Employee> employee){
int id_search;

cout << "Enter employee id: ";
    cin >> id_search;


    for(auto obj:employee)if((obj.search(id_search)) !=NULL ) obj.toString(); 


}




void addEmployee(vector<Employee> &employee){
Employee employeeObj;
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

employeeObj = Employee(name,job,id,salary);
employee.push_back(employeeObj);

}



void printMenu(){
cout << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add employee" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" S      " << setw(10) << "Search employee" << endl;
cout <<" X      " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
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
Employee::~Employee(){
    

}