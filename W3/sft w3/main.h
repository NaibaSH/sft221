#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

struct Customer {
    char first_Name[50];
    char last_Name[50];
    char street_Address[100];
    char city[50];
    char province[50];
    char postal_Code[50];
};

bool isValidProvince(const char* province);
struct Customer inputCustomerInfo();
bool isValidPostalCode(const char* postalcode);

#endif /* MAIN_H */