/*
* Name: Naiba Shabanova
* StudentEmail: nshabanova@myseneca.ca
* StudentID: 164598229
* 
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "workName.h"

using namespace std;

int main() {
    Customer c;

    // Get first name
    cout << "Enter your first name: ";
    cin >> c.m_firstname;

    do {
        cout << "Enter your last name: ";
        cin.ignore(); // Clear the newline character left in the buffer
        getline(cin, c.m_lastname);

        if (c.m_lastname.empty() || isNumber(c.m_lastname)) {
            cout << "Invalid Entry: Last name cannot be empty or a number." << endl;
        }
    } while (c.m_lastname.empty() || isNumber(c.m_lastname));

    // Get street address
    cout << "Enter your street address: ";
    cin.ignore(); // Clear the newline character left in the buffer
    getline(cin, c.m_address);

    // Get city
    cout << "Enter your city: ";
    getline(cin, c.m_city);

    // Get province
    cout << "Enter your province: ";
    cin >> c.m_province;

    // Get postal code with validation
    do {
        cout << "Enter your postal code: ";
        cin >> c.m_postalcode;
        if (!isValidPostalCode(c.m_postalcode)) {
            cout << "Invalid Entry: Postal code is not valid." << endl;
        }
    } while (!isValidPostalCode(c.m_postalcode));

    // Display the entered information
    cout << "You entered:" << endl;
    cout << c.m_firstname << " " << c.m_lastname << endl;
    cout << c.m_address << "," << endl;
    cout << c.m_city << ", " << c.m_province << "," << endl;
    cout << c.m_postalcode << endl;

    return 0;
}
