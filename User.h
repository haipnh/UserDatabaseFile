#ifndef USER_H
#define USER_H

#include <Arduino.h>

class User{
  public:
    User();
    User(String userName, String userPassword);
    String getUserName();
    void setUserName(String userName);
    String getUserPassword();
    void setUserPassword(String userPassword);
  private:
    //uint8_t userID;
    String userName, userPassword;
    int priority;
    
};
#endif
