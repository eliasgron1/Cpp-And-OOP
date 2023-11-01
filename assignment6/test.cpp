#include <iostream>
#include <cstring>
using namespace std;
const int LEN=52;


//Here we define class player
class Player {
  char name[LEN];
  char id[LEN];
  int rank;

 public:

//This is a constructor with three parameters
  Player(char*, char*, int);

//This is a constructor with two parameters
 Player(char*, char*);

 //This is a constructor with no parameter
 Player();


 //This is the destructor function
  ~Player();

  void set_rank(int rank) {this->rank = rank;}
  int get_rank() {return this->rank;}
  void print();
};

//This is the definition of the constructor with three parameters
 Player::Player(char *name, char *id, int rank){

  strcpy(this->name, name);
  strcpy(this->id, id);
  this->rank = rank;

  cout<<"Constructor for "<<this->name<<" called."<<endl;
 }


//This is the definition of the constructor with two parameters
 Player::Player(char *name, char *id){
  strcpy(this->name, name);
  strcpy(this->id, id);

//Here we decide to initialise rank with 0 if it is not
//explicitly initialised by the user.
  rank = 0;

    cout<<"Constructor for "<<this->name<<" called."<<endl;
 }



 //This is the definition of the constructor with no parameter
 Player::Player(){

//Here we decide to initialise name with "name_not_known"
  strcpy(this->name, "name:not_known");

  //Here we decide to initialise id with "id_not_known"
  strcpy(this->id, "id_not_Known");

//Here we decide to initialise rank with 0 if it is not
//explicitly initialised by the user.
  rank = 0;

    cout<<"Constructor for "<<this->name<<" called."<<endl;
 }



//Here we define the destructor function
//This function will be called whenever an object
//is removed
 Player::~Player() {
     cout<<"Destructor called for "<<this->name<<endl;
     cout<<"Freeing memory and quitting.."<<endl;
 }

 void Player::print() {
  cout<<this->name<<", "<<this->id<<" rank: "<<this->rank<<"\n";
 }



 //This is an independent function, which
 //demonstrates how constructors and destructors
 //are called
 void create_objects(int size) {

     cout<<"Creating "<<size<<" Player objects.."<<endl;
 Player* Players=new Player[size];


 //In the following lines we ask Players'
 //information from standard input
 char name[LEN], id[LEN];

 for (int i=0; i<size; i++) {
 cout<<"Enter "<<i+1<<". Player's name and id: ";
 cin>>name>>id;
 Players[i]=Player(name, id);
 }


 //Here we free memory
 Players=NULL;

 delete [] Players;
 }



int main() {

 Player playes_1((char*)"Katja", (char*)"P1", 5);
 Player player_2((char*)"OOna",(char*) "P2", 3);

//The rank for this Player will be 0.
 Player player_3((char*)"Laura", (char*)"P3");

//Here we print information of those Players whose ranks are not 0.
 cout<<"Trying to print information of p1:"<<endl;
 if(playes_1.get_rank()) playes_1.print();

 cout<<"Trying to print information of p2:"<<endl;
 if(player_2.get_rank()) player_2.print();

//The information for s3 won't be printed since the rank is 0.
 cout<<"Trying to print information of p3:"<<endl;
 if(player_3.get_rank()) player_3.print();

 int number_of_objects;

 cout<<"How many objects should be created? ";
 cin>>number_of_objects;
 cin.get();

 //Here we call function create_objects()
 //to see how constructors and destructors are called
   create_objects(number_of_objects);

return 0;
}
