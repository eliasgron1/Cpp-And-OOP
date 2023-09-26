#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;



void matrixSum(int matrix1[][],int matrix2[][], int sumOfMatrix[][], int sizesx[0] int sizesy[0]);


int main(){ 
srand(time(NULL));

int sizesx[2];
int sizesy[2];

for(int i=0; i<2; i++){
sizesx[i] = rand() % 3 + 3;
sizesy[i] = sizesx[i];
cout << sizesx[i] << " ";
cout << sizesy[i] << "   ";
}
cout << endl;

int matrix1[sizesy[0]][sizesx[0]];
int matrix2[sizesy[1]][sizesx[1]];
int sumOfMatrix[sizesx[0]][sizesy[0]];


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
matrixSum(matrix1[][], matrix2[][], sumOfMatrix[][], sizesx[0], sizesy[0])

return 0;
}


void matrixSum(int matrix1[][],int matrix2[][], int sumOfMatrix[][], int sizesx[0] int sizesy[0]){
cout << endl;
for(int i=0; i<sizesx[0]; i++){
    for(int j=0; j<sizesy[0]; j++){
        sumOfMatrix[j][i]=(matrix1[j][i] + matrix2[j][i]);
        cout << sumOfMatrix[j][i] << " ";
    }
    cout << endl;
}
}