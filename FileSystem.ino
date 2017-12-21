#include "User.h"
#include "UserDatabaseFile.h"

UserDatabaseFile* myDBF = new UserDatabaseFile();

void setup() {
  // put your setup code here, to run once:
  SPIFFS.begin();
  Serial.begin(9600);
  //myDBF->initDatabase();
  myDBF->openDatabaseReadMode(); 
  Serial.print("Number of records in Database : ");
  Serial.println(myDBF->numberOfRecords());
  //User user = myDBF->getUser(0);
  myDBF->setDatabaseCursor(0);
  Serial.println(myDBF->readRecord());
  String temp;
  //String temp = user.getUserName();
  Serial.print("Username : ");
  //Serial.println(temp);
  Serial.print("Userpassword : ");
  //temp = user.getUserPassword();
  Serial.println(temp);
  myDBF->closeDatabase();
}

void loop() {
  // put your main code here, to run repeatedly:

}

