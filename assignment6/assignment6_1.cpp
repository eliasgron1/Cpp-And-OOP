#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const int HOTEL_AMOUNT = 1;
const int ROOM_AMOUNT = 5;
const int CUST_AMOUNT = 5;


class Hotel{
public:
    string name;
    string address;
    int num_of_stars;
    int num_of_rooms;

    class Room {
        string type;
        double price_per_night;
        int number;
        int size;
    public:

};

    class Customer{
        string name;
        string address;
        string arrival_date;
        int nights_stayed;
        int number;
    public:
        
    };

};




int main(int argc, char **argv){


try{
    Hotel hotel[HOTEL_AMOUNT];
}
catch(bad_alloc &xa){
    cout << "Memory allocation failed";
    return 1;
}




return 0;
}