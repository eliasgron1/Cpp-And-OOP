#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"class.h"


using namespace std;

const string Admin::admin_username = "a";
const string Admin::admin_password = "a";


void printMenu(void);
void createUserObject(Admin*, vector<User>&);
void printUserObjects(vector<User>);


// MAIN

int main(){
char command;

Admin *admin = new Admin;

vector<User> user;


while(command != 'X'){

printMenu();
    cin >> command;
    command = toupper(command);

switch(command){
    case 'A':
        createUserObject(admin, user);
        break;

    case 'P':
        printUserObjects(user);
        break;
    
    case 'S':
        
        break;


}
}

admin = NULL;
delete [] admin;

return 0;
}



// METHODS

bool Admin::Authenticate(){
string password, username;

cout << "\nEnter Admin username: ";
    cin >> username;
cout << "\nEnter Admin password: ";
    cin >> password;

if(this->admin_password==password && this->admin_username==username) return true;
cout << "\nWrong password or username";
return false;
}


void Admin::setUsername(const string new_username, User &user_obj){
if(this->Authenticate()) user_obj.username=new_username;
cout << "\ndebug: " <<user_obj.username << "\n";
cout << "\ndebug: " <<user_obj.password << "\n";
}
void Admin::setPassword(const string new_password, User &user_obj){
if(this->Authenticate()) user_obj.password=new_password;
cout << "\ndebug: " <<user_obj.username << "\n";
cout << "\ndebug: " <<user_obj.password << "\n";
}



string User::getInfo(){
std::stringstream user_stream;


user_stream << "Username: " << this->username << "\nName: " << this->name_first << " " << this->name_last
            << "\nPhone: " << this->phone_number;
 
return user_stream.str();

}



// FUNCTIONS

void createUserObject(Admin* admin, vector<User> &user){
User user_obj;
string name_first, name_last, phone_number;
string username, password;

cout << "\nEnter first name: ";
    cin >> name_first;
cout << "\nEnter last name: ";
    cin >> name_last;
cout << "\nEnter phone number: ";
    cin >> phone_number;


user_obj=User(name_first,name_last,phone_number);


cout << "\nEnter username: ";
    cin >> username;
    admin->setUsername(username, user_obj);
cout << "\nEnter password: ";
    cin >> password;
    admin->setPassword(password, user_obj);


user.push_back(user_obj);

}


void printUserObjects(vector<User> user){
for(auto obj : user){
cout <<"--------------------------------------------\n";
cout << obj.getInfo();
cout <<"\n--------------------------------------------";
}
}


void printMenu(){
cout << left << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add user" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" S      " << setw(10) << "Search user" << endl;
cout <<" X      " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
}



// CONSTRUCTORS AND DESTRUCTORS

User::User(string name_first, string name_last, string phone_number){
this->name_first=name_first;
this->name_last=name_last;
this->phone_number=phone_number;
}
User::User(){
this->username="username:not_set";
this->password="password:not_set";
this->name_first="name_first:not_set";
this->name_last="name_last:not_set";
this->phone_number="phone_number:not_set";
}
User::~User(){
cout << endl << this->username<< " " << this->password <<" user deconstructed";
}