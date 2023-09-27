#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;


const int MAX_COL1=5, MAX_ROW1=5;
const int MAX_COL2=5, MAX_ROW2=5;

void getSizes(int *pSizesx, int *pSizesy);
void getMatrix1Values(int matrix1[][MAX_COL1], int, int, int*, int* );
void getMatrix2Values(int matrix2[][MAX_COL2], int, int, int*, int* );


int main(){ 
srand(time(NULL));


int matrix1[MAX_ROW1][MAX_COL1];
int matrix2[MAX_ROW2][MAX_COL2];

int sizesx[2];
int sizesy[2];

int *pSizesx = sizesx;
int *pSizesy = sizesy;

getSizes(pSizesx, pSizesy);
getMatrix1Values(matrix1, MAX_ROW1, MAX_COL1, pSizesx, pSizesy);
getMatrix2Values(matrix2, MAX_ROW2, MAX_COL2, pSizesx, pSizesy);



for(int i=0; i<MAX_ROW1-*(pSizesy+0); i++){             //print values for matrix1
    for(int j=0; j<MAX_ROW1-*(pSizesx+0); j++){
        cout << matrix1[i][j] << " ";
    }
    cout << endl;
}
cout << endl << endl;
for(int i=0; i<MAX_ROW2-*(pSizesy+1); i++){             //print values for matrix2
    for(int j=0; j<MAX_ROW2-*(pSizesx+1); j++){
        cout << matrix2[i][j] << " ";
    }
    cout << endl;
}

cout << endl << "ROWS " << MAX_ROW1-*(pSizesy+0);

return 0;
}


void getSizes(int *pSizesx, int *pSizesy){
for(int i=0; i<2; i++){
    *(pSizesx + i) = 1;                                // add rand() here
    *(pSizesy + i) = *(pSizesx + i);
    cout << *(pSizesx + i)  << " ";
    cout << *(pSizesy + i)  << "   ";
}
cout << endl << endl;

}



void getMatrix1Values(int matrix1[][MAX_COL1], int MAX_ROW1, int MAX_COL1, int* pSizesy, int* pSizesx ){
for(int i=0; i < MAX_ROW1-*(pSizesy+0); i++){             //values for matrix1
    for(int j=0; j < MAX_COL1-*(pSizesx+0); j++){
        matrix1[i][j]=rand() % 5;
    }
}

}



void getMatrix2Values(int matrix2[][MAX_COL2], int MAX_ROW2, int MAX_COL2, int* pSizesy, int* pSizesx){
for(int i=0; i < MAX_ROW2-*(pSizesy+1); i++){             //values for matrix2
    for(int j=0; j < MAX_COL2-*(pSizesx+1); j++){
        matrix2[i][j]=rand() % 5;
    }
}

}






