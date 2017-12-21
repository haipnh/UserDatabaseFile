#include "User.h"

User::User(){
  
}

User::User(String userName, String userPassword){
    setUserName(userName);  
    setUserPassword(userPassword);
}

String User::getUserName(){
    //if(this->userName!="") 
        return this->userName;    
    //else 
        //return "Not Found";
}
void User::setUserName(String userName){
    this->userName = userName;
//    if(this->userName == userName)
//        return 1;
//    else
//        return 0;
}
String User::getUserPassword(){
    return this->userPassword;
}
void User::setUserPassword(String userPassword){
    this->userPassword = userPassword;
//    if(this->userPassword == userPassword)
//        return 1;
//    else
//        return 0;    
}

