
using namespace std;


void User::setPermissions(char* permissions){
this->permissions[0]=permissions[0];
this->permissions[1]=permissions[1];
this->permissions[2]=permissions[2];
}


void User::removePermissions(char* permissions_to_delete){
for(int i=0;i<3;i++){
    switch(toupper(permissions_to_delete[i])){
        case 'R':
        if(this->permissions[i]=='r'){
            this->permissions[0]='-';
            cout << "\ndeleted read permission";
        }
        else cout << "\nuser doesnt have permission: read";
        break;
        
        case 'W':
        if(this->permissions[i]=='w'){
            this->permissions[1]='-';
            cout << "\ndeleted write permission";
        }
        else cout << "\nuser doesnt have permission: write";
        break;
        
        case 'X':
        if(this->permissions[i]=='x'){
            this->permissions[2]='-';
            cout << "\ndeleted execute permission";
        }
        else cout << "\nuser doesnt have permission: execute";
        break;
    }
}
}

bool User::comparePhoneNumber(User user_obj){
    if(this->getPhoneNumber() == user_obj.getPhoneNumber()){
    return true;
    }
    return false;
}


string User::getPermissions(){
string perms_string(this->permissions,3);
return perms_string;
}

string User::getUsername(){
    return this->username;
}



User::User(){
this->username="username:not_set";
this->password="password:not_set";
this->permissions[0]='-';
this->permissions[1]='-';
this->permissions[2]='-';
}
