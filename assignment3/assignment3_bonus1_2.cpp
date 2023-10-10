#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;


const int MAX_COL=4, MAX_ROW=4;


void getSizes(int *pSizesx, int *pSizesy);
void getMatrix1Values(int matrix1[][MAX_COL], int, int, int*, int* );
void getMatrix2Values(int matrix2[][MAX_COL], int, int, int*, int* );
void printMatrix1Values(int matrix1[][MAX_COL], int, int, int*, int* );
void printMatrix2Values(int matrix2[][MAX_COL], int, int, int*, int* );

void calculateSum(int matrix1[][MAX_COL],int matrix2[][MAX_COL], int, int, int*, int* );


int main(){                                              // Main Function
srand(time(NULL));


int matrix1[MAX_ROW][MAX_COL];
int matrix2[MAX_ROW][MAX_COL];

int sizesx[2];
int sizesy[2];

int *pSizesx = sizesx;
int *pSizesy = sizesy;

getSizes(pSizesx, pSizesy);
getMatrix1Values(matrix1, MAX_ROW, MAX_COL, pSizesx, pSizesy);
getMatrix2Values(matrix2, MAX_ROW, MAX_COL, pSizesx, pSizesy);

printMatrix1Values(matrix1, MAX_ROW, MAX_COL, pSizesx, pSizesy);
printMatrix2Values(matrix2, MAX_ROW, MAX_COL, pSizesx, pSizesy);

calculateSum(matrix1, matrix2, MAX_ROW, MAX_COL, pSizesy, pSizesx);

return 0;
}




// Functions





void getSizes(int *pSizesx, int *pSizesy){
for(int i=0; i<2; i++){
    *(pSizesx + i) = 1;                                // add rand() here
    *(pSizesy + i) = *(pSizesx + i);
    cout << MAX_ROW-*(pSizesy+0)  << " ";
    cout << MAX_ROW-*(pSizesy+0)  << "   ";
}
cout << endl << endl;

}



void getMatrix1Values(int matrix1[][MAX_COL], int MAX_ROW, int MAX_COL, int* pSizesy, int* pSizesx ){
for(int i=0; i < MAX_ROW-*(pSizesy+0); i++){             //values for matrix1
    for(int j=0; j < MAX_COL-*(pSizesx+0); j++){
        matrix1[i][j]=rand() % 5;
    }
}

}



void getMatrix2Values(int matrix2[][MAX_COL], int MAX_ROW, int MAX_COL, int* pSizesy, int* pSizesx){
for(int i=0; i < MAX_ROW-*(pSizesy+1); i++){             //values for matrix2
    for(int j=0; j < MAX_COL-*(pSizesx+1); j++){
        matrix2[i][j]=rand() % 5;
    }
}

}


void printMatrix1Values(int matrix1[][MAX_COL], int MAX_ROW, int MAX_COL, int* pSizesy, int* pSizesx){
for(int i=0; i<MAX_ROW-*(pSizesy+0); i++){             //print values for matrix1
    for(int j=0; j<MAX_COL-*(pSizesx+0); j++){
        cout << matrix1[i][j] << " ";
    }
    cout << endl;
}
cout <<endl;
}

void printMatrix2Values(int matrix2[][MAX_COL], int MAX_ROW, int MAX_COL, int* pSizesy, int* pSizesx){
for(int i=0; i<MAX_ROW-*(pSizesy+1); i++){             //print values for matrix2
    for(int j=0; j<MAX_COL-*(pSizesx+1); j++){
        cout << matrix2[i][j] << " ";
    }
    cout << endl;
}
cout << endl;
}




void calculateSum(int matrix1[][MAX_COL],int matrix2[][MAX_COL], int MAX_ROW, int MAX_COL, int* pSizesy, int* pSizesx){
int matrixSum[MAX_ROW][MAX_COL];
cout << "Sum is" << endl;
for(int i=0; i<MAX_ROW-*(pSizesy+1); i++){
    for(int j=0; j<MAX_COL-*(pSizesx+1); j++){
        cout << matrix1[i][j] + matrix2[i][j] << " ";
    }
    cout << endl;
}


}

