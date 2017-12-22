# UserDatabaseFile

## Dev for : ESP8266

## This library helps you to store users's information then save it as .txt file in the flash memory.

### Table columns :
> ID | Username | UserPassword

### Each row is a record (a 83-byte-long string) that has format :

#### [ID] [UserPassword] [UserPassword][RS]

> ID : 2 bytes

> UserName : 40 bytes (If username's length is shorter than 40, fill it with blanks when writing. So we can use trim() after reading it) 

> UserPassword : 40 bytes

> RS : Record Separator character (ASCII : 30)

The default record is always "admin/d033e22ae348aeb5660fc2140aec35850c4da997" ("admin" in SHA-1)

## HOW TO USE

### Create new object
``
UserDatabaseFile* myDBF = new UserDatabaseFile();
``
> If the ``database.txt`` is empty, it will be initialize with "admin/d033e22ae348aeb5660fc2140aec35850c4da997" record

### Methods :
``openDatabaseReadMode();``     //Open database in read-mode, cursor is at the beginning of the file

``openDatabaseWriteMode();``    //Open database in write-mode, cursor is at the end of the file

``openDatabaseInitMode();``     //Truncate file to zero length, then initialize with default record

``closeDatabase();``            //Close file after read/write operations

``setDatabaseCursor(int index)``//Set the cursor position at the record's index (offset of each record is 83 bytes)

``readRecord()``                //Return a 82-byte-long record (auto remove the RS character of each record)

``makeRecord(String userName, String userPassword);`` //Return a 83-byte-long record contains username and password

``writeRecord(String record)``               //Write the record into the file

