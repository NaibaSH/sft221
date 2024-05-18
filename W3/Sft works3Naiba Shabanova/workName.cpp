#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "workName.h"

using namespace std;



// Function definition
bool isNumber(const std::string& s) {
    std::istringstream iss(s);
    double num;
    return iss >> num >> std::ws && iss.eof(); // Check if the entire string is a valid number
}

bool isValidPostalCode(std::string& postalCode) {
    // Convert to uppercase
    std::transform(postalCode.begin(), postalCode.end(), postalCode.begin(), ::toupper);

    // Remove spaces
    postalCode.erase(std::remove_if(postalCode.begin(), postalCode.end(), ::isspace), postalCode.end());

    // Check if the postal code is valid
    if (postalCode.length() == 6 &&
        isalpha(postalCode[0]) && isdigit(postalCode[1]) &&
        isalpha(postalCode[2]) && isdigit(postalCode[3]) &&
        isalpha(postalCode[4]) && isdigit(postalCode[5])) {

        // Format postal code with a space
        postalCode.insert(3, " ");
        return true;
    }

    return false;
}


