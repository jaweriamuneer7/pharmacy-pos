#include<iostream>
#include"sqlite3.h"


void createMedicineTable(sqlite3 *db);

int main() {
    sqlite3 *db;
    int rc;


    rc = sqlite3_open("pharma.db", &db);

    if(rc){
        std::cout << "Database cannot open! Error occured!"<< std::endl;
    }
    else {
        std::cout << "Database opened successfully!!!" << std::endl;
    }
    createMedicineTable(db);
    sqlite3_close(db);
    return 0;

}

void createMedicineTable(sqlite3 *db) {
    

    const char *sql = "CREATE TABLE IF NOT EXISTS MEDICINE("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
    "NAME TEXT NOT NULL,"
    "PRICE REAL NOT NULL,"
    "STOCK INTEGER NOT NULL);";
    char *errorMessage = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errorMessage);

    if(rc!=SQLITE_OK) {
        std::cout<< "Facing an error creating"<< errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
    else {
        std::cout<<"Medicine Table Created Successfully!"<< std::endl;
    }


    

    
}