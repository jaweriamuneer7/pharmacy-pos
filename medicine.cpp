#include<iostream>
#include "sqlite3.h"
#include"medicine.h"

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