#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main(){ 
srand(time(NULL));

int sizesx[2];
int sizesy[2];

for(int i=0; i<2; i++){
sizesx[i] = rand() % 3 + 3;
sizesy[i] = rand() % 2 + 1;
cout << sizesx[i] << " ";
cout << sizesy[i] << "   ";
}
cout << endl;

int matrix1[sizesy[0]][sizesx[0]];
int matrix2[sizesy[1]][sizesx[1]];



for(int i=0; i<=sizesy[0]; i++){             //values for matrix1
    for(int j=0; j<sizesx[0]; j++){
        matrix1[i][j]=rand() % 5;
    }
}
for(int i=0; i<=sizesy[1]; i++){             //values for matrix2
    for(int j=0; j<sizesx[1]; j++){
        matrix2[i][j]=rand() % 5;
    }
}



cout << endl << endl;
for(int i=0; i<=sizesy[0]; i++){             //print values for matrix1
    for(int j=0; j<sizesx[0]; j++){
        cout << matrix1[i][j] << " ";
    }
    cout << endl;
}

cout << endl << endl;
for(int i=0; i<=sizesy[1]; i++){             //print values for matrix2
    for(int j=0; j<sizesx[1]; j++){
        cout << matrix2[i][j] << " ";
    }
    cout << endl;
}

return 0;
}

