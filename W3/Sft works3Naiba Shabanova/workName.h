#ifndef WORKNAME_H
#define WORKNAME_H

#include <string>
#include <iostream>

struct Customer {
    std::string m_firstname;
    std::string m_lastname;
    std::string m_address;
    std::string m_city;
    std::string m_province;
    std::string m_postalcode;
};

bool isNumber(const std::string& s);

bool isValidPostalCode(std::string& postalCode);

#endif // WORKNAME_H
