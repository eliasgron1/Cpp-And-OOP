#include <iostream>
#include <new>
#include <cstring>
using namespace std;


const int CUSTOMER_AMOUNT = 2;
const int ROOM_AMOUNT = 2;
const int LEN=20;


struct Room {
int room_id;
char room_type[LEN];
bool is_free = true;
double price_per_night;
};

struct Customer{
char customer_name[LEN];
int room_id=0;
int number_of_nights;
};


void getRoomData(Room*);
void getCustomerData(Room*, Customer*);
void printAssignments(Room*, Customer*);




int main() {
Room *rooms;
Customer *customers;

try{
    rooms = new Room[ROOM_AMOUNT];
    customers = new Customer[CUSTOMER_AMOUNT];
}
catch(bad_alloc &xa){
    cout << "Memory allocation failed";
    return 1;
}

getRoomData(rooms);
getCustomerData(rooms, customers);
printAssignments(rooms, customers);

rooms=NULL;
customers=NULL;

delete [] rooms;
delete [] customers;

return 0;
}




//  FUNCTIONS

void getRoomData(Room rooms[ROOM_AMOUNT]){
for(int i=0;i<ROOM_AMOUNT;i++){
cout << endl << "Enter room id: " ;
    cin >> rooms->room_id;
cout << endl << rooms->room_id << ". What is the room type: ";
    cin >> rooms->room_type;
cout << endl << rooms->room_id<< ". Enter room price per night: ";
    cin >> rooms->price_per_night;
rooms++;
}
rooms -= ROOM_AMOUNT;
}




void getCustomerData(Room rooms[ROOM_AMOUNT], Customer customers[CUSTOMER_AMOUNT]){

for(int i=0;i<CUSTOMER_AMOUNT;i++){
int desired_room_id=0;
cout << endl << "Enter Name: " ;
    cin >> customers[i].customer_name;
cout << endl << "Enter desired room id: " ;
    cin >> desired_room_id;
    
    for(int j=0; j<ROOM_AMOUNT; j++){
        if(desired_room_id == rooms[j].room_id){
            if(rooms[j].is_free==true){
                customers[i].room_id = desired_room_id;
                rooms[j].is_free = false;

                cout << endl << "Enter number Of nights: ";
                cin >> customers[i].number_of_nights;
            }
            else if(rooms[j].is_free==false) cout << "!!room occupied!!" <<endl;
        }
    }
}
}



void printAssignments(Room rooms[ROOM_AMOUNT],Customer customers[CUSTOMER_AMOUNT]){
cout << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;

for(int i=0;i<ROOM_AMOUNT;i++){
cout <<"Room id: " << rooms[i].room_id << "   Room type:  "<< rooms[i].room_type <<"   Price Per Night:   " << rooms[i].price_per_night;
   
for(int j=0; j<CUSTOMER_AMOUNT;j++){
    if(rooms[i].room_id==customers[j].room_id){
        cout << "   Assigned to: " << customers[j].customer_name << " For " << customers[j].number_of_nights << " Nights";
        cout << "   Total cost: " << (customers[j].number_of_nights * rooms[i].price_per_night) ;
    }
}
cout << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
}
