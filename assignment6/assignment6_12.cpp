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

        void printCust();
        
    };

    void print(void);
    void createRoomObj(int, Hotel*, Hotel::Room*);
    void createCustObj(int i, Hotel*, Hotel::Customer*, int);
};


Hotel* createObj(void);
void printMenu(void);





// MAIN

int main(){
char command; 

vector <Hotel*> hotels_obj;


while (command != 'X'){

printMenu();
    cin >> command;
    command=toupper(command);


switch(command){

    case 'A':
        hotels_obj.push_back(createObj());
    break;

    case 'P':
        for(auto obj : hotels_obj){ obj->print(); }
    break;
    


}
}

return 0;
}





// METHODS

void Hotel::print(void){
cout << endl << endl << "Hotel: " << this->name << "   " << this->address << "   Stars: " << this->num_of_stars << "   Rooms: " << this->num_of_rooms << endl;
cout << "-----------------------------------------------------------------------" << endl;

// for(int i=0;i<HOTEL_AMOUNT;i++){
//     for(int j=0;j<this->num_of_rooms;j++){
//         roomsObj[j].printRoom();
//     }
//     for(int n=0;n<customer_amount;n++){
//         customersObj[n].printCust();
//     }

// }

}




// FUNCTIONS


Hotel* createObj(){

Hotel* hotel = new Hotel;

string name, address;
int num_of_stars, num_of_rooms;


cout << endl <<"Enter hotel name ";
    cin >> name;
cout << endl <<"Enter hotel address ";
    cin >> address;
cout << endl <<"Enter number of stars and rooms ";
    cin >> num_of_stars >> num_of_rooms;

*hotel=Hotel(name, address, num_of_stars, num_of_rooms);

return hotel;
}




void printMenu(){
cout << endl << "**************************************************" << endl;
cout <<" A      " << setw(10) << "Add hotel" << endl;
cout <<" P      " << setw(10) << "Print data" << endl;
cout <<" X      " << setw(10) << "Exit program" << endl;
cout << "**************************************************" << endl;
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
