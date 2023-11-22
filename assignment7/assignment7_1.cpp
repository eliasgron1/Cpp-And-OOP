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

    Employee* search(int, string, string);
    void toString(void);
    void update(void);

};



void deleteEmployee(vector<Employee>&);
void searchEmployee(vector<Employee>&);
void printMenu(int);
void addEmployee(vector<Employee>&);


// MAIN

int main(){
char command;

vector<Employee> employee;

while(command != 'X'){

printMenu(employee.size());
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

    case 'R':
        deleteEmployee(employee);
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

Employee* Employee::search(int id, string name, string job){
if(this->id   == id)  { return this; }
if(this->name == name){ return this; }
if(this->job  == job) { return this; }

return NULL;
}

void Employee::update(){
string name;
string job;
int id;
float salary;

cout << "Enter new employee id: ";
    cin >> id;
    this->id = id;

cout << "Enter new employee name: ";
    cin >> name;
    this->name = name;

cout << "Enter new employee job: ";
    cin >> job;
    this->job = job;

cout << "Enter new employee salary: ";
    cin >> salary;
    this->salary = salary;

}





// FUNCTIONS

void deleteEmployee(vector<Employee> &employee){
    int id_search;
    cout << "Enter the employee ID to delete: ";
    cin >> id_search;

    for(int i=0; i<employee.size(); i++){
        
        if((employee[i].search(id_search, " ", " ")) !=NULL ) {
            cout << "DELETED" << endl;
            employee[i].toString();
            employee.erase(employee.begin()+i);
        }
    }
}






void searchEmployee(vector<Employee> &employee){
int id_search = 0, input = 0;
char update;
string name_search= " ";
string job_search = " ";

cout << "1: Search by id" << endl;
cout << "2: Search by name" << endl;
cout << "3: Search by job" << endl; 
    cin >> input;

switch(input){
    case 1:
        cout << "Enter employee id: ";
            cin >> id_search;
    break;

    case 2:
        cout << "Enter employee name: ";
            cin >> name_search;
    break;

    case 3:
        cout << "Enter employee job: ";
            cin >> job_search;
    break;

    default:
        cout << "Incorrect input";
    break;
}

    for(auto& obj : employee){
        if((obj.search(id_search, name_search, job_search)) !=NULL ){
            obj.toString();

            cout << "Type 'U' to update employee data" << endl; 
                cin >> update;
                update = toupper(update);
                if(update=='U') obj.update();
        }
    }
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



void printMenu(int employee_count){
cout << endl << "**************************************************" << endl;
cout << " " <<employee_count << "      Employees saved in DB" << endl << endl;
cout <<" A      " << setw(10) << "Add employee" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" R      " << setw(10) << "Remove data" << endl;
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
