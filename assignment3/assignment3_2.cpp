#include <iostream>
#include <cstring>
using namespace std;

void sortArray(char *pchars);

const int MAX_CHAR = 20;

int main(){
char chars[MAX_CHAR] = "";
char *pchars = &chars[0];

cout << "Give a string of characters" << endl;
cin >> chars;

sortArray(pchars);

int i=1;
while(i < MAX_CHAR){
    cout << *(pchars + MAX_CHAR -i);
    i++;
}
cout << endl;


return 0;
}



void sortArray(char *pchars){
char temp;

for(int i = 0; i<MAX_CHAR; i++) {
    for(int j = i+1; j<MAX_CHAR; j++){
        if(*(pchars + j) < *(pchars + i)){
            temp = *(pchars + i);
            *(pchars + i) = *(pchars + j);
            *(pchars + j) = temp;
         }
    }
}

}