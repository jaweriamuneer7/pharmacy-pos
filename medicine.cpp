#include<string>
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

void addMedicine(sqlite3 *db) {
    std::string medicineName;
    double medicinePrice;
    int medicineStock;

    std::cout<< "Enter Name of Medicine: " << std::endl;
    std::cin.ignore();                                  
    std::getline(std::cin, medicineName);

    
    std::cout<< "Enter price: " << std::endl;
    std::cin >> medicinePrice;

    
    std::cout<< "Enter Medicine stock: " << std::endl;
    std::cin >> medicineStock;

    // build the SQl insert statement 
    std::string sql = "INSERT INTO MEDICINE (NAME, PRICE, STOCK) VALUES ('"
                    + medicineName + "', "
                    + std::to_string(medicinePrice) + ", "
                    + std::to_string(medicineStock) + ");";

    char *errorMessage = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

    if(rc!=SQLITE_OK){
        std::cout << "Facing an error adding medicine: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
    else {
        std::cout << "Medicine added succesfully!" << std::endl;
    }

}
int printMedicine(void *data, int cols, char **colValues, char **colNames) {
    /*std::cout << "ID: " << colValues[0] << std::endl;
    std::cout << "NAME: " << colValues[1] << std::endl;
    std::cout << "PRICE: " << colValues[2] << std::endl;
    std::cout << "STOCK: " << colValues[3] << std::endl;*/
     for(int i = 0; i < cols; i++) {
        std::cout << colNames[i] << ": " << (colValues[i] ? colValues[i] : "NULL") << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    return 0;
    }
 
void viewMedicine(sqlite3 *db) {
    const char *sql = "SELECT * FROM MEDICINE";
    char *errorMessage = nullptr;

    int rc = sqlite3_exec(db, sql, printMedicine, nullptr, &errorMessage);

    if (rc!=SQLITE_OK) {
        std::cout << "Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
}

void searchMedicine(sqlite3 *db) {
    std::string name;
    std::cout << "Enter Medicine name to search: " << std::endl;
    std::cin >> name; 

    std::string sql = "SELECT * FROM MEDICINE WHERE NAME LIKE '%" + name + "%';";

    char *errorMessage = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), printMedicine, nullptr, &errorMessage);
    if(rc!=SQLITE_OK) {
        std::cout << "Error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
   
}