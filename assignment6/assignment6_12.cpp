#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
using namespace std;


class Hotel{
    string name;
    string address;
    int num_of_stars;
    int num_of_rooms;

public:
    Hotel(string, string, int, int);
    Hotel();
    
    class Room {
        string type;
        double price_per_night;
        int number;
        int size;
    public:

        Room(string, double, int, int);
        Room();

        void getRoom();

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

        
    };

    vector <Hotel::Room> rooms_obj;

    void setRoom(Hotel::Room room) { this->rooms_obj.push_back(room); }
    
    void getHotel();
    void createRoomObj(int, Hotel);
    // void createCustObj(int i, Hotel*, Hotel::Customer*, int);
};


Hotel createObj();
void printMenu(void);





// MAIN

int main(){
char command; 

vector <Hotel> hotels_obj;


while (command != 'X'){

printMenu();
    cin >> command;
    command=toupper(command);


switch(command){

    case 'A':
        hotels_obj.push_back(createObj());
    break;

    case 'P':
        for(auto obj : hotels_obj){ obj.getHotel(); }
    break;
    
}
}

return 0;
}





// METHODS

void Hotel::getHotel(){
cout << endl << endl << "Hotel: " << this->name << "   " << this->address << "   Stars: " << this->num_of_stars << "   Rooms: " << this->num_of_rooms << endl;
cout << "-----------------------------------------------------------------------" << endl;

for(auto obj : this->rooms_obj) obj.getRoom();

}


void Hotel::Room::getRoom(void){
cout << setw(30) <<left <<"Room Number: "              <<this->number << endl;
cout << setw(30) <<left <<"Room Type: "                <<this->type << endl;
cout << setw(30) <<left <<"Room price per night: "     <<this->price_per_night << endl;
cout << setw(30) <<left <<"Room size: "                <<this->size << endl;
cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

}




// FUNCTIONS


Hotel createObj(){

Hotel hotel;

string name, address;
int num_of_stars, num_of_rooms;


cout << endl <<"Enter hotel name ";
    cin >> name;
cout << endl <<"Enter hotel address ";
    cin >> address;
cout << endl <<"Enter number of stars and rooms ";
    cin >> num_of_stars >> num_of_rooms;

hotel=Hotel(name, address, num_of_stars, num_of_rooms);

for(int j=0;j<num_of_rooms;j++){
    Hotel::Room room;

    int size, number;
    string type;
    float price_per_night;

    cout << endl << "Enter hotel " << name << "'s room " << ". number. : ";
        cin >> number;
    cout << endl << "Enter hotel " << name << "'s room " << number << ". type. : ";
        cin >> type;
    cout << endl << "Enter hotel " << name << "'s room " << number << ". price/night. : ";
        cin >> price_per_night;
    cout << endl << "Enter hotel " << name << "'s room " << number << ". size. : ";
        cin >> size;
    room = Hotel::Room(type, price_per_night, number, size);
    hotel.setRoom(room);
}

return hotel;
}




void printMenu(){
cout << endl << "**************************************************" << endl;
cout << left <<" A      " << setw(10) << "Add hotel" << endl;
cout << left <<" P      " << setw(10) << "Print data" << endl;
cout << left <<" X      " << setw(10) << "Exit program" << endl;
cout << left <<"**************************************************" << endl;
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
