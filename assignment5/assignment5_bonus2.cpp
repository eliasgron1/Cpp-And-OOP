#include <iostream>
using namespace std;



int  getArrLength  (void);
void getArrData    (int *arr, int arr_length);    
int* getBiggestVal (int *arr, int arr_length);
int* getSmallestVal(int *arr, int arr_length);



int main(void){
int arr_length = getArrLength();
int arr[arr_length];
int *pbiggest_value, *psmallest_value;

getArrData(arr, arr_length);

pbiggest_value  = getBiggestVal (arr, arr_length);
psmallest_value = getSmallestVal(arr, arr_length); 

cout << endl << "biggest number is: " << *pbiggest_value;
cout << endl << "smallest number is: " << *psmallest_value;

return 0;    
}



int getArrLength(void){
int input;
    cout << "Give array length: ";
        cin >> input;
return input;
}



void getArrData(int *arr, int arr_length){
for(int i=0; i < arr_length; i++){
    cout << endl << "give number " << i+1 << ": ";
        cin >> arr[i];
}
}



int* getBiggestVal(int *arr, int arr_length){
int *memadd=&arr[arr_length-1],n=0;
    while(n < arr_length){
        if(arr[n] > *memadd) memadd = &arr[n];
    n++;
    }
return memadd;
}



int* getSmallestVal(int *arr, int arr_length){
int *memadd=&arr[arr_length-1], n=0;
    while(n < arr_length){
        if(arr[n] < *memadd) memadd = &arr[n];
    n++;
    }
return memadd;
}