#include <iostream>
#include <cstring>
using namespace std;

int main(){
char str1[] = "Hello";
char str2[] = "jallo";

char *pstr1 = &str1[0];
char *pstr2 = &str2[0];

int counter = 0, i=0;

while(*(pstr1+i) != '\0' && *(pstr2+i) != '\0' ){
    if (*(pstr1+i) != *(pstr2+i)){
        cout << *(pstr1+i) << " and " << *(pstr2+i) <<" does not match" << endl;
    }
    i++;
}

return 0;
}
