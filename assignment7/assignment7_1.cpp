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



void deleteEmployee(vector<Employee*>);
void searchEmployee(vector<Employee*>);
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
        for (auto obj : employee){ obj->toString(); }
        break;
    
    case 'S':
        searchEmployee(employee);
        break;

    case 'R':
        deleteEmployee(employee);
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
Employee::~Employee(){
    cout << "Deleted employee id: " << this->id << ", name: " << this->name << endl;

// this->name = "name:not_known";
// this->job = "job:not_known";
// this->id = 0;
// this->salary = 0;

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

}

Employee* Employee::search(int id){
if(this->id == id){ return this; }

return NULL;
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


void searchEmployee(vector<Employee*> employee){
int id_search;

cout << "Enter employee id: ";
    cin >> id_search;

for (auto obj : employee){ 
    if(obj->search(id_search) != NULL){
        (obj->search(id_search))->toString(); 
    }
}
}


void deleteEmployee(vector<Employee*> employee){
int id_search;

cout << "Enter the employee id to be deleted: ";
    cin >> id_search;

for (auto obj : employee){ 
    if(obj->search(id_search) != NULL){

        for(int i=0; i<employee.size(); i++){ 

            if(obj->search(id_search)==employee[i]){
                employee.erase(employee.begin()+i);
                cout << "deleting: " << obj << endl;
            }
        }
        
        delete obj; 
    }
}
}


void printMenu(){
cout << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add employee" << endl;
cout <<" R      " << setw(10) << "Remove employee" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" S      " << setw(10) << "Search employee" << endl;
cout <<" X      " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
}


