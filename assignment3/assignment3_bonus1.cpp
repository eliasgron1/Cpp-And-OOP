#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main(){ //main

int sizes[4];

srand(time(NULL));
for(int i=0;i<4;i++){
sizes[i] = rand() % 3 + 5;
cout << sizes[i] << " ";
}
cout << endl << endl;

int matrix1[sizes[1]][sizes[2]];
int matrix2[sizes[3]][sizes[3]];


for(int i=0; i<sizes[1];i++){
    for(int j=0; j<sizes[2];j++){
        matrix1[j][i] = rand() % 5;
    }
}



for(int i=0; i<sizes[1];i++){
    for(int j=0; j<sizes[2];j++){
        matrix2[j][i] = rand() % 5;
    }
}



for(int i=0; i<sizes[1];i++){
    for(int j=0; j<sizes[2];j++){
        cout << matrix1[j][i] << " ";
    }
    cout << endl;
}

}

void matrixSum(){

}