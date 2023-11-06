#include<iostream>
#include<iomanip>
#include<string>
#include <cstring>
using namespace std;

const int HOTEL_AMOUNT = 1;

class Hotel{
public:
    string name;
    string address;
    int num_of_stars;
    int num_of_rooms;

    Hotel(string, string, int, int);
    Hotel();
    ~Hotel();
    
    class Room {
        string type;
        double price_per_night;
        int number;
        int size;
    public:

        Room(string, double, int, int);
        Room();
        ~Room();
        void printRoom();

};

    class Customer{
        string name;
        string address;
        string arrival_date;
        int nights_stayed;
        int number;
    public:

        Customer(string, string, string, int, int);
        Customer();
        ~Customer();

        void printCust();
        
    };

    void print(Hotel::Room*, Hotel::Customer*, int);
    void createRoomObj(int, Hotel*, Hotel::Room*);
    void createCustObj(int i, Hotel*, Hotel::Customer*, int);
};


void createObj(Hotel *hotelsObj);




// MAIN

int main(){
int i=0;

Hotel *hotelsObj = new Hotel[HOTEL_AMOUNT];
createObj(hotelsObj);


Hotel::Room *roomsObj = new Hotel::Room[hotelsObj[i].num_of_rooms];
hotelsObj[i].createRoomObj(i, hotelsObj, roomsObj);


int customer_amount;
cout << endl << "Enter customer amount :";
    cin >> customer_amount;

Hotel::Customer *customersObj = new Hotel::Customer[customer_amount];
hotelsObj[i].createCustObj(i,hotelsObj,customersObj, customer_amount);

hotelsObj[i].print(roomsObj, customersObj, customer_amount);

hotelsObj=NULL;
roomsObj=NULL;
customersObj=NULL;

delete [] hotelsObj;
delete [] roomsObj;
delete [] customersObj;


return 0;
}




// CONSTRUCTORS

Hotel::Hotel(string name, string address, int num_of_stars, int num_of_rooms){
this->name = name;
this->address = address;
this->num_of_stars = num_of_stars;
this->num_of_rooms = num_of_rooms;
}
Hotel::Hotel(){
this->name = "name:not_known";
this->address = "address:not_known";
this->num_of_stars = 0;
this->num_of_rooms = 0;
}
Hotel::Room::Room(string type, double price_per_night, int number, int size){
this->type = type;
this->price_per_night=price_per_night;
this->number=number;
this->size=size;
}
Hotel::Room::Room(){
this->type = "type:not_known";
this->price_per_night=0;
this->number=0;
this->size=0;
}
Hotel::Customer::Customer(string name, string address, string arrival_date, int nights_stayed, int number){
this->name = name;
this->address = address;
this->arrival_date = arrival_date;
this->nights_stayed = nights_stayed;
this->number = number;
}
Hotel::Customer::Customer(){
this->name = "name:not_known";
this->address = "address:not_known";
this->arrival_date = "arrival_date:not_known";
this->nights_stayed = 0;
this->number = 0;
}




// DESTRUCTORS

Hotel::~Hotel(){
cout << endl << "freeing memory for " << this->name << endl;
}
Hotel::Room::~Room(){
cout << "freeing memory for room " << this->number << endl;
}
Hotel::Customer::~Customer(){
cout << "freeing memory for customer " << this->number << endl;
}




// FUNCTIONS

void createObj(Hotel *hotelsObj){
string name, address;
int num_of_stars, num_of_rooms;

for(int i=0;i<HOTEL_AMOUNT;i++){
cout << endl <<"Enter hotel " << i+1 << " name ";
    cin >> name;
cout << endl <<"Enter hotel " << i+1 << " address ";
    cin >> address;
cout << endl <<"Enter hotel " << i+1 << " number of stars and rooms ";
    cin >> num_of_stars >> num_of_rooms;

hotelsObj[i]=Hotel(name, address, num_of_stars, num_of_rooms);
}

}




// METHODS

void Hotel::createRoomObj(int i, Hotel *hotelsObj, Hotel::Room *roomsObj){
string type;
double price_per_night;
int number, size;


for(int j=0;j<hotelsObj[i].num_of_rooms;j++){
    number = j+1;
    cout << endl << "Enter hotel " << hotelsObj[i].name << "'s room " << number << ". type. : ";
        cin >> type;
    cout << endl << "Enter hotel " << hotelsObj[i].name << "'s room " << number << ". price/night. : ";
        cin >> price_per_night;
    cout << endl << "Enter hotel " << hotelsObj[i].name << "'s room " << number << ". size. : ";
        cin >> size;
    roomsObj[j] = Hotel::Room(type, price_per_night, number, size);
}

}

void Hotel::createCustObj(int i, Hotel *hotelsObj, Hotel::Customer *customersObj, int customer_amount){
string name;
string address;
string arrival_date;
int nights_stayed;
int number;

for(int j=0;j<customer_amount;j++){
    cout << endl << "Enter customer name: ";
        cin >> name;
    cout << endl << "Enter customer " << name << "'s address: ";
        cin >> address;
    cout << endl << "Enter customer " << name << "'s arrival date: ";
        cin >> arrival_date;
    cout << endl << "Enter customer " << name << "'s amount of nights stayed: ";
        cin >> nights_stayed;
    cout << endl << "Enter customer " << name << "'s room number: ";
        cin >> number;
    customersObj[j] = Hotel::Customer(name, address, arrival_date, nights_stayed, number);
}

}




void Hotel::print(Hotel::Room *roomsObj, Hotel::Customer *customersObj, int customer_amount){
cout << endl << endl << "Hotel: " << this->name << "   " << this->address << "   Stars: " << this->num_of_stars << "   Rooms: " << this->num_of_rooms << endl;
cout << "-----------------------------------------------------------------------" << endl;

for(int i=0;i<HOTEL_AMOUNT;i++){
    for(int j=0;j<this->num_of_rooms;j++){
        roomsObj[j].printRoom();
    }
    for(int n=0;n<customer_amount;n++){
        customersObj[n].printCust();
    }

}

}



void Hotel::Room::printRoom(){
cout << setw(30) << left <<"Room Number: "              <<this->number << endl;
cout << setw(30) << left <<"Room Type: "                <<this->type << endl;
cout << setw(30) << left <<"Room price per night: "     <<this->price_per_night << endl;
cout << setw(30) << left <<"Room size: "                <<this->size << endl;
cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}





void Hotel::Customer::printCust(){
cout << setw(30) << left <<"Customer Name: "            <<this->name << endl;
cout << setw(30) << left <<"Customer Address: "         <<this->address << endl;
cout << setw(30) << left <<"Customer Date Of Arrival: " <<this->arrival_date << endl;
cout << setw(30) << left <<"Customer Nights Stayed: "   <<this->nights_stayed << endl;
cout << setw(30) << left <<"Customer Assigned To Room: "<<this->number << endl;
cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

