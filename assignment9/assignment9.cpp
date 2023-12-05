#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"classes.hpp"

using namespace std;


void printMenu(void);


int main(){

vector<Person> person;

while(command != 'X'){

printMenu();
    cin >> command;
    command = toupper(command);

    switch(command){
        case 'A':
            createObject();
            break;

        case 'P':
            
            break;
        
        case 'S':
            
            break;
        
        case 'R':
            
            break;



    }
}

return 0;
}



// FUNCTIONS

void printMenu(){
cout << left << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add Person" << endl;
cout <<" P      " << setw(10) << "Print Data" << endl;
cout <<" S      " << setw(10) << "Search Person" << endl;
cout <<" R      " << setw(10) << "Remove Employee" << endl;
cout <<" X      " << setw(10) << "Exit Program" << endl;
cout << "**************************************************" << endl;
}