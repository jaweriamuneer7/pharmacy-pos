#include<iostream>
#include"sqlite3.h"
#include<string>
#include"billing.h"

void createBillingTables(sqlite3 *db){
    const char *billSql = "CREATE TABLE IF NOT EXISTS BILL("
                           "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                           "CUSTOMER_NAME TEXT NOT NULL, "
                           "DATE TEXT NOT NULL, "
                           "TOTAL REAL DEFAULT 0, "
                           "CASH_RECEIVED REAL DEFAULT 0, "
                           "NET_RECEIVEABLE REAL DEFAULT 0);";

    const char *billItemsSql = "CREATE TABLE IF NOT EXISTS BILL_ITEMS("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "BILL_ID INTEGER NOT NULL, "
                                "MEDICINE_NAME TEXT NOT NULL, "
                                "QUANTITY INTEGER NOT NULL, "
                                "RATE REAL NOT NULL, "
                                "NET_AMOUNT REAL NOT NULL);";

    char *errorMessage1 = nullptr;
    char *errorMessage2 = nullptr;
    int rc = sqlite3_exec(db, billSql, nullptr, nullptr, &errorMessage1);
    int rc1 = sqlite3_exec(db, billItemsSql, nullptr, nullptr, &errorMessage2);

    if(rc!=SQLITE_OK || rc1!=SQLITE_OK) {
        std::cout << "error facing creating billTable and billItemsTable: " << errorMessage1 << errorMessage2 << std::endl;
        sqlite3_free(errorMessage1);
        sqlite3_free(errorMessage2);
    }
    else {
        std::cout << "Bill table and Bill Items Table created successfully !" << std::endl;
    }
    
}