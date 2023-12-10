#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"../headers/classes.hpp"
#include"classes.cpp"

using namespace std;


void printMenu(void);
void printObjects(vector<Employee>);
void createObject(vector<Employee>&);
void searchPerson(vector<Employee>);
void removeEmployee(vector<Employee>&);

int main(){
char command;


vector<Employee> employee;

while(command != 'X'){

printMenu();
    cin >> command;
    command = toupper(command);

    switch(command){
        case 'A':
            createObject(employee);
            break;

        case 'P':
            printObjects(employee);
            break;
        
        case 'S':
            searchPerson(employee);
            break;
        
        case 'R':
            removeEmployee(employee);
            break;

    }
}

return 0;
}



// FUNCTIONS


void removeEmployee(vector<Employee> &employee){
string name_search;
bool name_found=false;

    cout << "\nEnter name of employee to be deleted: "; 
        cin >> name_search;

    for(int i=0; i<employee.size(); i++){
        if((employee[i].searchPerson(name_search)) !=NULL ) {
            cout << "\nDELETED" << endl;
            employee[i].print();
            employee.erase(employee.begin()+i);
            name_found=true;
            }
    }
    if(!name_found){
        cout << "\nName Not Found";
    }


}


void searchPerson(vector<Employee> employee){
string name_search;
bool name_found=false;

    cout << "\nEnter name to be searched: "; 
        cin >> name_search;

    for(auto obj : employee){
        if(obj.searchPerson(name_search) != NULL){
            cout << "\nPerson found!\n";
            obj.searchPerson(name_search)->printPersonData();
            name_found=true;
        }
    }
    if(!name_found){
        cout << "\nPerson Not Found\n"; 
    }

}


void printObjects(vector<Employee> employee){
    for(auto obj : employee){
        obj.print();

    }
}


void createObject(vector<Employee> &employee){

Employee employee_obj;
Person person_obj;  
Profession profession_obj;

int id;
int years_of_exp;
float salary;
float tax_rate;
string firm;
string title;
string name_first;
string name_last; 
string address;


if(employee_obj.getFirm() == ""){            
    cout << "\nEnter firm: ";
        cin >> firm;
        employee_obj.setFirm(firm);         // set firm if not already set
}
else{
    cout << "\nfirm is " << employee_obj.getFirm();
}


cout << "\nEnter first name: ";
    cin >> name_first;
cout << "\nEnter last name: ";
    cin >> name_last;
cout << "\nEnter address: ";
    cin >> address;
    

cout << "\nEnter profession title: ";
    cin >> title;


for(auto obj : employee){                   // check if latest salary exists
    if(obj.getSalary(title) != 0){
        cout << "\nLatest Salary Is " << obj.getSalary(title);  
    }
}


cout << "\nEnter profession years of exp: ";
    cin >> years_of_exp; 
cout << "\nEnter salary: ";
    cin >> salary;


cout << "\nEnter employee id: ";
    cin >> id;
cout << "\nEnter employee tax rate: ";
    cin >> tax_rate;


employee_obj = Employee(id, salary, tax_rate, years_of_exp, title, name_first, name_last, address); // employee object
employee.push_back(employee_obj);

}



void printMenu(){
    cout << left << endl << "\n\n\n**************************************************" << endl;
    cout <<" A      " << setw(10) << "Add Person" << endl;
    cout <<" P      " << setw(10) << "Print Data" << endl;
    cout <<" S      " << setw(10) << "Search Person" << endl;
    cout <<" R      " << setw(10) << "Remove Employee" << endl;
    cout <<" X      " << setw(10) << "Exit Program" << endl;
    cout << "**************************************************" << endl;
}




