
using namespace std;


bool Admin::authenticate(){
string admin_password, admin_username;
cout << "\nEnter Admin Username: ";
    cin >> admin_username;
cout << "\nEnter Admin Password: ";
    cin >> admin_password;

if(this->admin_password==admin_password && this->admin_username==admin_username) return true;
cout << "\nWrong password or username";
return false;
}


void Admin::setUsername(const string new_username, User &user_obj){
bool authentication_passed = false;

while(authentication_passed == false){
    if (this->authenticate()==true){
        user_obj.username=new_username;
        authentication_passed=true;
    }
    else{
        authentication_passed=false;
    }
}
// cout << "\ndebug: " <<user_obj.username << "\n";
// cout << "\ndebug: " <<user_obj.password << "\n";
}


void Admin::setPassword(const string new_password, User &user_obj){
bool authentication_passed = false;

while(authentication_passed == false){
    if (this->authenticate()==true){
        user_obj.password=new_password;
        authentication_passed=true;
    }
    else{
        authentication_passed=false;
    }
}
// cout << "\ndebug: " <<user_obj.username << "\n";
// cout << "\ndebug: " <<user_obj.password << "\n";
}


void Admin::setPermissions(User &user, char* permissions){
    if(authenticate() == true){
        user.setPermissions(permissions);
    }
    else{
        cout << "permissions not set";
    }
}

void Admin::removePermissions(User &user, char* permissions_to_delete){
    if(authenticate() == true){
        user.removePermissions(permissions_to_delete);
    }
    else{
        cout << "permissions not set";
    }
}