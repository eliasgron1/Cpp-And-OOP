#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

#include"../header/person.hpp"
#include"../header/user.hpp"
#include"../header/admin.hpp"

#include"person.cpp"
#include"user.cpp"
#include"admin.cpp"

using namespace std;

const string Admin::admin_username = "a";
const string Admin::admin_password = "a";


void printMenu(void);
void createUserObject(Admin*, vector<User>&);

void printUserObjects(vector<User>);
//void searchUserObject(vector<User>);



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
        //searchUserObject(user);
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
bool authtenticate_failed = true;

cout << "\nEnter first name: ";
    cin >> first_name;
cout << "\nEnter last name: ";
    cin >> last_name;
cout << "\nEnter phone number: ";
    cin >> phone_number;




cout << "\nEnter username: ";
    cin >> username;
    admin->setUsername(username, user_obj);

cout << "\nEnter password: ";
    cin >> password;
    admin->setPassword(password, user_obj);




user_obj.setPersonInformation(first_name, last_name, phone_number);

user.push_back(user_obj);

}


void printUserObjects(vector<User> user){
    for(auto obj : user){
        cout << obj.toString(obj);
    }
}


// void searchUserObject(vector<User> user){
// string input;

// cout << "\nEnter username to be searched: ";
//     cin >> input;

// for(auto obj : user){
//     if(obj.search(input)) cout << obj.getInfo();
    
//     else cout << "User not found :C";

// }
// }

void printMenu(){
cout << left << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add user" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" S      " << setw(10) << "Search user" << endl;
cout <<" X      " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
}
