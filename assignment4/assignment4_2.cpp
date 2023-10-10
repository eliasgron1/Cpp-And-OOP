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
bool is_free;
double price_per_night;
};

struct Customer{
char customer_name[LEN];
int room_id=0;
int number_of_nights;
};


void getRoomData(Room rooms[ROOM_AMOUNT]);
void getCustomerData(Room rooms[ROOM_AMOUNT], Customer customers[CUSTOMER_AMOUNT]);
void printAssignments(Room rooms[ROOM_AMOUNT], Customer customers[CUSTOMER_AMOUNT]);




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
cout << "Enter room id" << endl;
    cin >> rooms->room_id;
cout << "Is the room free (1/0)" << endl;
    cin >> rooms->is_free;
cout << "What is the room type" << endl;
    cin >> rooms->room_type;
cout << "Enter room price per night" << endl;
    cin >> rooms->price_per_night;
rooms++;
}
rooms -= ROOM_AMOUNT;
}




void getCustomerData(Room rooms[ROOM_AMOUNT], Customer customers[CUSTOMER_AMOUNT]){

for(int i=0;i<CUSTOMER_AMOUNT;i++){
int desired_room_id=0;
cout << "Enter Name" << endl;
    cin >> customers[i].customer_name;
cout << "Enter desired room id" << endl;
    cin >> desired_room_id;
    
    for(int j=0; j<ROOM_AMOUNT; j++){
        if(desired_room_id == rooms[j].room_id){
            if(rooms[j].is_free==true){
                customers[i].room_id = desired_room_id;
                rooms[j].is_free = false;

                cout << "Enter number Of nights" << endl; 
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
cout <<"Room id: " << rooms[i].room_id << "   Room type:   "<< rooms[i].room_type <<"   Price Per Night:   " << rooms[i].price_per_night;
    
for(int j=0; j<CUSTOMER_AMOUNT;j++){
    if(rooms[i].room_id==customers[j].room_id){
        cout << "   Assigned to: " << customers[j].customer_name << " For " << customers[j].number_of_nights << " Nights";
        cout << "   Total cost: " << (customers[j].number_of_nights * rooms[i].price_per_night);
    }
}

cout << endl << "-----------------------------------------------------------------------------------------------------------------" << endl;
}
}
