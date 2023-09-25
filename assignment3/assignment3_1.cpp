#include <iostream>
using namespace std;


int main(){

double numbers[5];
double sum = 0;
double *pnum;


cout << "Give five numbers" << endl;

for (int i=0; i<5; i++){
    cin >> numbers[i];

    pnum = &numbers[i];
    sum += *pnum;
}

cout << sum << endl;


return 0;
}