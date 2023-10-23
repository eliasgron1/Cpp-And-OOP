#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int LEN = 15;

int  getNameCount(void);
void getNames    (string *names,int name_count);
void sortNames   (string *names,int name_count);
void printNames  (string *names,int name_count);
void swap        (string *name1,string *name2, int);




// MAIN

int main() {
int name_count = getNameCount();
string names[name_count];

getNames(names, name_count);
// sortNames(names,name_count);
printNames(names, name_count);


return 0;
}




//  FUNCTIONS

int getNameCount(void){
int input;
cout << "Enter the amount of names: ";
    cin >> input;
return input;
}


void getNames(string *names, int name_count){
for(int i=0;i<name_count;i++){
    cout << endl << "Enter name " << i << ".  ";
        cin >> names[i];
}
}



// void sortNames(string *names, int name_count){
// for(int i=0;i<name_count-1;i++){
//     for(int j=0;j<name_count-1;j++){
//         if(names[j] < names[j+1]) swap(names[j], names[j+1]);   
//     }
// }
// }

// void swap(string* &name1, string* &name2){
// string temp[20];
//     strcpy(temp, name1);
//     strcpy(name1, name2);
//     strcpy(name2, temp);
// }


void printNames(string *names, int name_count){
    for(int i=0;i<name_count;i++){
        cout << names[i] << ", ";
    }


cout << endl << "-------------------------------------------------------------------------" << endl;
}

