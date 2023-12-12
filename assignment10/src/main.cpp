#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include <cstring>

#include"../header/person.hpp"
#include"../header/user.hpp"
#include"../header/admin.hpp"

#include"person.cpp"
#include"user.cpp"
#include"admin.cpp"

using namespace std;

const string Admin::admin_username = "admin";
const string Admin::admin_password = "pass";


void printMenu(void);
void createUserObject(Admin*, vector<User>&);

void assignPermissions(Admin*, User&);
void removePermissions(Admin*, User&);

void printUserObjects(vector<User>);
void searchUserObject(Admin*, vector<User>&);



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
        searchUserObject(admin, user);
        break;


}
}

admin = NULL;
delete [] admin;

return 0;
}





// FUNCTIONS


void createUserObject(Admin* admin, vector<User> &user){
User user_obj;
string first_name, last_name, phone_number;
string username, password;


string input_perms;


    
cout << "\nEnter username: ";
    cin >> username;
    cout << username;
    admin->setUsername(username, user_obj);

cout << endl <<"Enter password: ";
    cin >> password;
    cout << password;
    admin->setPassword(password, user_obj);

    assignPermissions(admin, user_obj);



cout << "\nEnter first name: ";
    cin >> first_name;
cout << "\nEnter last name: ";
    cin >> last_name;
cout << "\nEnter phone number: ";
    cin >> phone_number;

user_obj.setPersonInformation(first_name, last_name, phone_number);

for(auto obj : user){
    if(obj.comparePhoneNumber(user_obj)){
        cout << "\nDuplicate phone number detected";
    }
}
user.push_back(user_obj);
}


void searchUserObject(Admin* admin, vector<User> &users){
string input;
char command;
bool user_found = false;

cout << "\nEnter user name, phone or surname: ";
    cin >> input;

for(auto &obj : users){
    if(obj.search(input) != NULL){
        user_found = true;
        cout << obj.toString(obj);
    }

    if(user_found){
        cout <<" A      " << setw(10) << "Add new Permissions" << endl;
        cout <<" B      " << setw(10) << "Remove Permissions" << endl;
            cin >> command;
        if(toupper(command) == 'A') assignPermissions(admin, obj);
        if(toupper(command) == 'B') removePermissions(admin, obj);
    }
}


if(!user_found) cout << "User Not Found!";
}




void removePermissions(Admin* admin, User &user){
char permissions_to_delete[3] = {'-','-','-'};
string input;


cout << "\nCurrent perms: " << user.getPermissions();
cout << "\nEnter permissions to remove: ";
cin >> input;

for(int i=0;i<3;i++){
    switch(toupper(input[i])){
        case 'R':
        permissions_to_delete[0] = 'r';
        break;

        case 'W':
        permissions_to_delete[1] = 'w';
        break;

        case 'X':
        permissions_to_delete[2] = 'x';
        break;


    }
}

admin->removePermissions(user, permissions_to_delete);

}





void assignPermissions(Admin* admin, User& user_obj){
char permissions[3] = {'-','-','-'}; 
string input;

cout << "\nEnter user permissions(rwx): ";
    cin >> input;

for(int i=0;i<3;i++){
    switch(toupper(input[i])){
        case 'R':
        permissions[0] = 'r';
        break;

        case 'W':
        permissions[1] = 'w';
        break;

        case 'X':
        permissions[2] = 'x';
        break;

    }
}
admin->setPermissions(user_obj, permissions);
}




void printUserObjects(vector<User> user){
    for(auto obj : user){
        cout << obj.toString(obj);
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
