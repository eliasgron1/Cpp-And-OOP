#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;



int  getNameCount(void);
void getNames    (char *names,int name_count);
void sortNames   (char *names,int name_count);
void printNames  (char *names,int name_count);
void swap        (char name1, char name2);




// MAIN

int main() {
int name_count = getNameCount();
char names[name_count]  ;

getNames(names, name_count);
sortNames(names,name_count);
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


void getNames(char *names, int name_count){
for(int i=0;i<name_count;i++){
    cout << endl << "Enter name " << i << ".  ";
        cin >> names[i];
}
}



void sortNames(char *names, int name_count){
for(int i=0;i<name_count-1;i++){
    for(int j=0;j<name_count-1;j++){
        if(strcmp(names[j], names[j+1])>0) swap(names[j], names[j+i]);   
    }
}
}


void printNames(char *names, int name_count){
for(int i=0;i<name_count;i++){

}


cout << endl << "-------------------------------------------------------------------------" << endl;
}

