#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include "Header.h"


int checkString(char* string) {
    size_t inputLength = strlen(string);
    if (inputLength > 1 && string[0] != '\n') {
        return 1;
    }
    else if (inputLength == 1 && string[0] == '\n') {
        return 0;
    }
    else {
        return 0;
    }
}
void setData(struct Customer* customer) {
    int validfirstname = 0;
    do {
        char input[80];
        printf("Enter your first name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->firstName, input, sizeof(customer->firstName) - 1);
            validfirstname = 1;
        }
    } while (!validfirstname);
    int validlastname = 0;
    do {
        char input[80];
        printf("Enter your last name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->lastName, input, sizeof(customer->lastName) - 1);
            validlastname = 1;
        }
    } while (!validlastname);
    int validadress = 0;
    do {
        char input[80];
        printf("Enter your street address: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->streetAddress, input, sizeof(customer->streetAddress) - 1);
            validadress = 1;
        }
    } while (!validadress);
    int validCity = 0;
    do {
        char input[80];
        printf("Enter your city: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->city, input, sizeof(customer->city) - 1);
            validCity = 1;
        }
    } while (!validCity);
    int validýlce = 0;
    do {
        char input[80];
        printf("Enter your province: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->province, input, sizeof(customer->province) - 1);
            validýlce = 1;
        }
    } while (!validýlce);
    char temporaryoccupant[10];
    int validPostal = 0;
    do {
        printf("Enter your postal code: ");
        fgets(temporaryoccupant, sizeof(temporaryoccupant), stdin);
        size_t inputLength = strlen(temporaryoccupant);
        if (inputLength > 0 && temporaryoccupant[inputLength - 1] == '\n') {
            temporaryoccupant[inputLength - 1] = '\0';
            if (temporaryoccupant[0] == '\0') {
                printf("Invalid Entry: ");
            }
            else {
                int check = isValid(temporaryoccupant);
                if (check) {
                    validPostal = 1;
                    strcpy(customer->postalCode, temporaryoccupant);
                }
                else {
                    printf("Invalid Entry: ");
                    validPostal = 0;
                }
            }
        }
    } while (!validPostal);
}
int isValid(char* temporaryoccupant) {
    size_t length = strlen(temporaryoccupant);
    int isValidPostal = 0;
    if (length == 6) {
        if (isalpha(temporaryoccupant[0]) && isdigit(temporaryoccupant[1]) && isalpha(temporaryoccupant[2]) &&
            isdigit(temporaryoccupant[3]) && isalpha(temporaryoccupant[4]) && isdigit(temporaryoccupant[5])) {
            return 1;
            for (int i = 0; i < length; i++) {
                temporaryoccupant[i] = toupper(temporaryoccupant[i]);
            }
            temporaryoccupant[7] = '\0';
        }
    }
    else if (length == 7) {
        if (isalpha(temporaryoccupant[0]) && isdigit(temporaryoccupant[1]) && isalpha(temporaryoccupant[2]) &&
            temporaryoccupant[3] == ' ' && isdigit(temporaryoccupant[4]) && isalpha(temporaryoccupant[5]) &&
            isdigit(temporaryoccupant[6])) {
            return 1;
            for (int i = 0; i < length; i++) {
                temporaryoccupant[i] = toupper(temporaryoccupant[i]);
            }
            temporaryoccupant[8] = '\0';
        }
    }
    return 0;
}
int postIsValid(const char* temporaryoccupant) {
    return isValid(temporaryoccupant);
}
int stringIsValid(char* temporaryString) {
    int result = 0;
    int resBool = 0;
    result = checkString(temporaryString);
    if (result) {
        resBool = 1;
    }
    else {
        resBool = 0;
    }
    return resBool;
}
int main() {
    struct Customer customer;
    setData(&customer);
    printf("\nYou entered:\n");
    printf("%s %s\n", customer.firstName, customer.lastName);
    printf("%s,\n", customer.streetAddress);
    printf("%s, %s\n", customer.city, customer.province);
    printf("%s\n", customer.postalCode);
    return 0;
}