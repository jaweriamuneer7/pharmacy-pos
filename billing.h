#ifndef BILLING_H
#define BILLING_H

#include "sqlite3.h"

void createBillingTables(sqlite3 *db);
void createBills(sqlite3 *db);

#endif



