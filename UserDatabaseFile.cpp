#include "UserDatabaseFile.h"

UserDatabaseFile::UserDatabaseFile(){
    initDatabase();
}

int UserDatabaseFile::openDatabaseReadMode() {
  Database = SPIFFS.open("/database.txt", "r");
  //Open text file for reading.  The stream is positioned at the
  //beginning of the file.
  if (!Database) {
    Serial.println("Can't open Database");
    return 0;
  }
  else
    return 1;
}

int UserDatabaseFile::openDatabaseWriteMode() {
  Database = SPIFFS.open("/database.txt", "a"); 
  //Open for appending (writing at end of file).  The file is
  //created if it does not exist.  The stream is positioned at the
  //end of the file.
  if (!Database) {
    Serial.println("Can't open Database");
    return 0;
  }
  else
    return 1;
}

int UserDatabaseFile::openDatabaseInitMode(){
    Database = SPIFFS.open("/database.txt", "w");
    //Truncate file to zero length or create text file for writing.
    //The stream is positioned at the beginning of the file.
    if (!Database) {
        Serial.println("Can't open Database");
        return 0;
    }
    else{
        //String temp = makeRecord("admin","d033e22ae348aeb5660fc2140aec35850c4da997");
        return 1;
    }
}

void UserDatabaseFile::closeDatabase(){
    Database.close();
}

int UserDatabaseFile::sizeOfDatabase() {
  return Database.size();
}

void UserDatabaseFile::setDatabaseCursor(int index) {
   Database.seek(index * 83, SeekSet);
}

String UserDatabaseFile::readRecord() {
    return Database.readStringUntil(30);//Read until "Record Separator" character
}

String UserDatabaseFile::makeRecord(String userName, String userPassword){
    String record="";
    int index = numberOfRecords();
    if(index<100 && userName.length() <= 40){
        if(index<10){
            record.concat("0");
            record.concat(String(index));
        }
        else
            record.concat(String(index));
        record.concat(userName);            
        if(userName.length() < 40){            
            for(int i=0;i<40-userName.length();i++){
                record.concat(' ');    
            }
        }
        record.concat(userPassword);
        record.concat(char(30));
    }
    return record;
}

//void UserDatabaseFile::writeRecord(String userName, String userPassword){
//    int index = numberOfRecords();
//    if(index<100 && userName.length() <= 40){
//        if(index<10){
//            Database.print("0");
//            Database.print(String(index));
//        }
//        else
//            Database.print(String(index));
//        Database.print(userName);            
//        if(userName.length() < 40){            
//            for(int i=0;i<40-userName.length();i++){
//                Database.print(' ');    
//            }
//        }
//        Database.print(userPassword);
//        Database.print(char(30));
//    }
//}

//String UserDatabaseFile::makeRecord(User user){
//    String record="";
//    String userName = user.getUserName();
//    String userPassword = user.getUserPassword();
//    record = makeRecord(userName,userPassword);
//    return record;
//}

void UserDatabaseFile::writeRecord(String record){
    Database.print(record);
}

int UserDatabaseFile::numberOfRecords(){
    return sizeOfDatabase()/83;
}

void UserDatabaseFile::initDatabase(){
    openDatabaseReadMode();
    if(numberOfRecords()==0){
        closeDatabase();
        openDatabaseInitMode();
        String temp = makeRecord("admin","d033e22ae348aeb5660fc2140aec35850c4da997");    
        //writeRecord("admin","d033e22ae348aeb5660fc2140aec35850c4da997");
        writeRecord(temp);
        closeDatabase();
    }
    else
        closeDatabase();
}


//User UserDatabaseFile::getUser(int index) {
//  User pure;
//  setDatabaseCursor(index);
//  //READ A RECORD TO A STRING BUFFER
//  String temp = readRecord();
//  //GET USER INFORMATION RECORD FROM BUFFER
//  int i = 0;
//  String userID = "";
//  String userName = "";
//  String userPassword = "";
//  //GET USER ID
//  for (i=0; i < 2; i++) {
//    userID += temp.charAt(i);
//  }
//  //GET USERNAME
//  for (i=2; i < 42; i++) {
//    userName += temp.charAt(i);
//  }
//  userName.trim();
//  //GET PASSWORD
//  for (i=42; i < 82; i++) {
//    userPassword += temp.charAt(i);
//  }
//  pure.setUserName(userName);
//  pure.setUserPassword(userPassword);
//  return pure;
//}
//
//User UserDatabaseFile::getUser(String userName) {
//    
//}
