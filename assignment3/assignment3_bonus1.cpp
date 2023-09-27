#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int ROW_SIZE = 10;
const int COLUMN_SIZE = 10;

void initialize(int [][10], int, int);
void display(int matrix[][10], int, int);
void sum(int matrix[][COLUMN_SIZE], int, int);

int main() {

    int matrix [ROW_SIZE][COLUMN_SIZE];

    initialize(matrix, ROW_SIZE, COLUMN_SIZE);

    display(matrix, ROW_SIZE,COLUMN_SIZE);

    sum(matrix, ROW_SIZE,COLUMN_SIZE);


    return 0;
}



void initialize(int matrix[][COLUMN_SIZE], int ROW_SIZE, int COLUMN_SIZE){
    for (int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            matrix[i][j] =  1 + rand() % 99;
        }
    }
}


void display(int matrix[][COLUMN_SIZE], int ROW_SIZE, int COLUMN_SIZE){
    for(int i = 0; i < ROW_SIZE; i++){
        for(int j = 0; j < COLUMN_SIZE; j++){
            cout<< setw(4)<<matrix[i][j]<< " ";
        }
         cout<< endl;
    }
}


void sum(int matrix[][COLUMN_SIZE], int ROW_SIZE, int COLUMN_SIZE){
    int sum_row;
    int sum_col;

    for(int i = 0; i < ROW_SIZE; i++){
        int sum_row = 0;
        for(int j = 0; j < COLUMN_SIZE; j++){
            sum_row = sum_row + matrix[i][j];
        }
    }

    for(int i = 0; i < ROW_SIZE; i++){
        int sum_col = 0;
        for(int j = 0; j < COLUMN_SIZE; j++){
            sum_col = sum_col + matrix[i][j];
        }
    }

    int sum = sum_row + sum_col;

    cout<<"The sum of the matrix is "<<sum<< endl;
}