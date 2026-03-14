#include<iostream>
#include"sqlite3.h"
#include "medicine.h"



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



    

    
