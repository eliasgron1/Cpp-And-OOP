#include <iostream>
#include <cstring>
using namespace std;


const int SIZE=5;
const int LEN=32;

void lower_str(char text[]){
for(int i=0; text[i]; i++)
     text[i]=tolower(text[i]);
}
void swap(char value1[], char value2[]){

         char temp[LEN];
         strncpy(temp, value1, LEN);
        strncpy(value1, value2, LEN);
        strncpy(value2, temp, LEN);
}


int main (void) {

char names[SIZE][LEN], names_copy[SIZE][LEN];
char temp[LEN];


for (int i=0; i<SIZE; i++){
cout<<"Enter "<<(i+1)<<". name: ";
cin.getline(names[i], LEN, '\n');

//Here we copy each name to the names_copy array
strncpy(names_copy[i], names[i], LEN);
//Here we convert the name to lower characters
lower_str(names_copy[i]);
}

for(int i=0; i<SIZE-1; i++){
for(int j=i+1; j<SIZE; j++){
    if(strcmp(names_copy[i], names_copy[j])>0){
            swap(names[i], names[j]);
            swap(names_copy[i], names_copy[j]);
    }
  }     
}
cout<<"Names sorted in ascending order:"<<endl;
    for (int i=0; i<SIZE; i++){
      cout<<names[i]<<endl;

}
return 0;
}