#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "main.h"

int main() {
    struct Customer customer;

    printf("Enter customer information:\n");
    customer = inputCustomerInfo();

    printf("\nYou entered:\n");
    printf("First Name: %s\n", customer.first_Name);
    printf("Last Name: %s\n", customer.last_Name);
    printf("Street Address: %s\n", customer.street_Address);
    printf("City: %s\n", customer.city);
    printf("Province: %s\n", customer.province);
    printf("Postal Code: %s\n", customer.postal_Code);

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool isValidProvince(const char* province) {
    int len = strlen(province);
    if (len != 2) {
        return false;
    }

    for (int i = 0; i < 2; i++) {
        if (!isalpha(province[i])) {
            return false;
        }
    }

    return true;
}

bool isValidPostalCode(const char* postalcode) {
    char formattedCode[50];
    int j = 0;

    for (int i = 0; postalcode[i] != '\0'; i++) {
        if (!isspace(postalcode[i])) {
            formattedCode[j++] = toupper(postalcode[i]);
        }
    }
    formattedCode[j] = '\0';

    if (strlen(formattedCode) != 6)
        return false;

    for (int i = 0; i < 6; i++) {
        if (!isalnum(formattedCode[i]))
            return false;
        if (i % 2 == 0 && !isalpha(formattedCode[i]))
            return false;
        if (i % 2 != 0 && !isdigit(formattedCode[i]))
            return false;
    }

    return true;
}

struct Customer inputCustomerInfo() {
    struct Customer customer;

    do {
        printf("Enter your first name: ");
        fgets(customer.first_Name, sizeof(customer.first_Name), stdin);
        customer.first_Name[strcspn(customer.first_Name, "\n")] = '\0';
        if (strlen(customer.first_Name) < 2) {
            printf("Invalid Entry: Enter your first name:\n");
        }
    } while (strlen(customer.first_Name) < 2);

    do {
        printf("Enter your last name: ");
        fgets(customer.last_Name, sizeof(customer.last_Name), stdin);
        customer.last_Name[strcspn(customer.last_Name, "\n")] = '\0';
        if (strlen(customer.last_Name) < 2) {
            printf("Invalid Entry: Enter your last name:\n");
        }
    } while (strlen(customer.last_Name) < 2);

    do {
        printf("Enter your street address: ");
        fgets(customer.street_Address, sizeof(customer.street_Address), stdin);
        customer.street_Address[strcspn(customer.street_Address, "\n")] = '\0';
        if (strlen(customer.street_Address) < 2) {
            printf("Invalid street address. Please enter at least 2 characters.\n");
        }
    } while (strlen(customer.street_Address) < 2);

    do {
        printf("Enter your city: ");
        fgets(customer.city, sizeof(customer.city), stdin);
        customer.city[strcspn(customer.city, "\n")] = '\0';
        if (strlen(customer.city) < 2) {
            printf("Invalid city. Please enter at least 2 characters.\n");
        }
    } while (strlen(customer.city) < 2);


    do {
        printf("Enter your postal code (e.g., A1B 2C3): ");
        fgets(customer.postal_Code, sizeof(customer.postal_Code), stdin);
        customer.postal_Code[strcspn(customer.postal_Code, "\n")] = '\0';
        if (!isValidPostalCode(customer.postal_Code)) {
            printf("Invalid Entry: Enter your postal code:\n");
        }
    } while (!isValidPostalCode(customer.postal_Code));

    return customer;
}