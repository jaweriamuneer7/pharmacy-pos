#ifndef MEDICINE_H
#define MEDICINE_H

#include "sqlite3.h"

void createMedicineTable(sqlite3 *db);
void addMedicine(sqlite3 *db);
void viewMedicine(sqlite3 *db);
int printMedicine(void*, int, char**, char**);

#endif
