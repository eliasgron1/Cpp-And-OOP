#include <iostream>
#include <new>
#include <cstring>
#include <iomanip>
using namespace std;

const int LEN=20;

struct Customer{
char name[LEN];
int customer_id=0;
float total_cost=0.00;
};

int getCustomerAmount(void);
void getCustomerData(Customer*, int customer_amount);
void sortCustomerData(Customer*, int customer_amount);
void printCustomerData(Customer*, int customer_amount);




int main() {
Customer *customers;
int customer_amount = getCustomerAmount();



try{
    customers = new Customer[customer_amount];
}
catch(bad_alloc &xa){
    cout << "Memory allocation failed";
    return 1;
}


getCustomerData(customers, customer_amount);
sortCustomerData(customers, customer_amount);
printCustomerData(customers, customer_amount);

customers=NULL;

delete [] customers;

return 0;
}




//  FUNCTIONS

int getCustomerAmount(void){
int input;
cout << "Enter the amount of customers: ";
    cin >> input;
return input;
}



void getCustomerData(Customer customers[], int customer_amount){
for(int i=0; i<customer_amount; i++){
    cout << endl << "Enter customer " << i << " name: ";
        cin >> customers[i].name;
    cout << endl << "Enter customer " << i << " ID: ";
        cin >> customers[i].customer_id;
    cout << endl << "Enter customer " << i << " total purchase amount: ";
        cin >> customers[i].total_cost;
}
}



void sortCustomerData(Customer customers[], int customer_amount){
for(int i=0;i<customer_amount-1;i++){
    for(int j=0;j<customer_amount-1;j++){
        if(customers[j].total_cost < customers[j+i].total_cost){
            swap(customers[j], customers[j+i]);
        }
    }
}
}


void printCustomerData(Customer customers[], int customer_amount){
for(int i=0;i<customer_amount;i++){
    cout << endl << "-------------------------------------------------------------------------" << endl;
    cout << i << "." << " Customer name: " << setw(10) << left << customers[i].name
         << "ID: " << setw(5) << customers[i].customer_id << "Total purchase: "<< setw(10) << customers[i].total_cost;
}


cout << endl << "-------------------------------------------------------------------------" << endl;
}

