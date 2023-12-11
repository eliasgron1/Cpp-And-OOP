
using namespace std;

string User::getUsername(){
    return this->username;
}



User::User(string username, string password, string first_name, string last_name, string phone_number){
this->username=username;
this->password=password;
setPersonInformation(first_name, last_name, phone_number);
}

User::User(){
this->username="username:not_set";
this->password="password:not_set";
}
