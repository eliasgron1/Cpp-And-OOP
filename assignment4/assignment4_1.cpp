#include <iostream>
using namespace std;


int main() {

int num  = 4;
int *p = &num;
int &ref = *p;

cout << "Reference: " << ref << endl << "Pointer: " << *p;  

}