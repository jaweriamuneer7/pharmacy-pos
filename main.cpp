#include<iostream>
#include"sqlite3.h"
#include "medicine.h"
#include<cstdlib>



int main() {
    sqlite3 *db;
    int rc;
    int choice;


    rc = sqlite3_open("pharma.db", &db);

    if(rc){
        std::cout << "Database cannot open! Error occured!"<< std::endl;
    }
    else {
        std::cout << "Database opened successfully!!!" << std::endl;
    }
    createMedicineTable(db);

    while(true) {
        std::cout << "Welcome to Shery Pharmacy" << std::endl;
        std::cout << "1. for adding Medicines" << std::endl;
        std::cout << "2. to search Medicine" << std::endl;
        std::cout << "3. to update Medicine" << std::endl;
        std::cout << "4. to delete Medicine" << std::endl;
        std::cout << "5. to exit()" << std::endl;

        std::cin >> choice;

        switch(choice) {
            case 1:
                addMedicine(db);
                break;
            case 2:
                std::cout << "Feature will be added later" << std::endl;
                break;
            case 3:
                std::cout << "Feature will be added later" << std::endl;
                break;
            case 4:
                std::cout << "Feature will be added later" << std::endl;
                break;
            case 5:
                std::cout << "Good Bye!!!" << std::endl;
                sqlite3_close(db);
                return 0;
        }
    }

    sqlite3_close(db);
    return 0;

}



    

    
