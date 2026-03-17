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
        std::cout << "2. to view Medicine" << std::endl;
        std::cout << "3. to search Medicine" << std::endl;
        std::cout << "4. to update Medicine data" << std::endl;
        std::cout << "5. to delete the record" << std::endl;
        std::cout << "6. To exit! " << std::endl;

        std::cin >> choice;

        switch(choice) {
            case 1:
                addMedicine(db);
                break;
            case 2:
                viewMedicine(db);
                break;
            case 3:
                searchMedicine(db);
                break;
            case 4:
                updateMedicine(db);
                break;
            case 5:
                deleteMedicine(db);
                break;
            case 6:
                std::cout << "Good Bye!!!" << std::endl;
                sqlite3_close(db);
                return 0;
        }
    }

    sqlite3_close(db);
    return 0;

}



    

    
