#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;
 
//Here we use keyword class to create 
//a new data type
class Employee
{
//These are private member variables
int id;
string name;
float salary;

//Here we declare public member functions
public:
void set_info (int, string, float);
string search (int);
string to_string ();
};
 
 



 
//This is the definition of function set_info()
void
Employee::set_info (int id, string name, float salary)
{

this->id = id;
this->name = name;
this->salary = salary;
} 
 
string Employee::search (int id)
{
   return this->id == id ? this->to_string () : string ("");
}
 
string Employee::to_string () 
{
 stringstream stm;
stm<< fixed<< setprecision (2)<<salary;
string salary_str = stm.str ();
return std::to_string (id) + " " + name + " " + salary_str;
}
 
 
 
int main ()
{

int id;
string type, name;
float salary;
int counter, size;

//Here we declare an object of type Employee
Employee* employee;
cout<<"How many employees? ";
cin>>size;

try {
employee=new Employee[size];
} catch(bad_alloc &ex){
cout<<"Memory allocation failed!"<<endl;
return 1;
}
 
 
//Here we bypass the Enter key
//cin.ignore();

for(int counter=0; counter<size; counter++){
cout<<"Enter the Employee id: ";
cin >> id;

cin.ignore ();
cout<<"Enter the Employee name: ";
getline (cin, name);

cout<<"Enter the Employee salary: ";
cin >> salary;

 
//Here we call functions set_info() and print() of object e
employee->set_info (id, name, salary);
 //Here we call functionse.to_string() to get employee info as text
cout<<"Employee info: "<<employee->to_string ()<<endl;
employee++;

 }
 
 

cout<<"Enter the Employee id to search: ";
cin >> id;

employee-=size;

cout<<"Employee info: ";
for(counter=0; counter<size; counter++ ){
 //Here we call functionse.to_string() to get employee info as text
 cout<<employee[counter].search (id)<<endl;
 
 //employee++;
}

delete [] employee;
 
return 0;
}