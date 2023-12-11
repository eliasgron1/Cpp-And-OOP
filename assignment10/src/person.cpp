
using namespace std;

string Person::toString(User& user_obj){
std::stringstream stream;
stream << "--------------------------------------------\n"  
            << "Username: " << user_obj.getUsername()
            << "\nName: " << this->first_name << " " << this->last_name
            << "\nPhone: " << this->phone_number
            << "\n--------------------------------------------\n";

return stream.str();
}


void Person::setPersonInformation(string first_name, string last_name, string phone_number){
this->first_name=first_name;
this->last_name=last_name;
this->phone_number=phone_number;
}

Person::Person(){
this->first_name="first_name";
this->last_name="last_name";
this->phone_number="phone_number";
}