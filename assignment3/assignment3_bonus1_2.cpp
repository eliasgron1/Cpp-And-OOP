#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;


int getSizes(int *pSizesx, int *pSizesy);


int main(){ 
srand(time(NULL));


int sizesx[2];
int sizesy[2];

int *pSizesx = sizesx;
int *pSizesy = sizesy;
getSizes(pSizesx, pSizesy);



int matrix1[*(pSizesy+0)][*(pSizesx+0)];
int matrix2[*(pSizesy+1)][*(pSizesx+1)];


for(int i=0; i < *(pSizesy+0); i++){             //values for matrix1
    for(int j=0; j < *(pSizesx+0); j++){
        matrix1[i][j]=rand() % 5;
    }
}

for(int i=0; i < *(pSizesy+1); i++){             //values for matrix2
    for(int j=0; j < *(pSizesx+1); j++){
        matrix2[i][j]=rand() % 5;
    }
}



cout << endl << endl;
for(int i=0; i<sizesy[0]; i++){             //print values for matrix1
    for(int j=0; j<sizesx[0]; j++){
        cout << matrix1[i][j] << " ";
    }
    cout << endl;
}

cout << endl << endl;
for(int i=0; i<sizesy[1]; i++){             //print values for matrix2
    for(int j=0; j<sizesx[1]; j++){
        cout << matrix2[i][j] << " ";
    }
    cout << endl;
}


return 0;
}




int getSizes(int *pSizesx, int *pSizesy){
for(int i=0; i<2; i++){
    *(pSizesx + i) = 3;                                // add rand() here
    *(pSizesy + i) = *(pSizesx + i);
    cout << *(pSizesx + i)  << " ";
    cout << *(pSizesy + i)  << "   ";
}
cout << endl;

return 0;
}





