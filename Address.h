// Address.h
#pragma once

#include <iostream>
#include <string>

class Address {
private:
    double latitude;
    double longitude;
    int houseNumber;
    std::string streetName;

public:
    Address();
    Address(double lat, double lon, int houseNum, const std::string& street);
    Address(const Address& other);
    ~Address();

    double getLatitude() const;
    double getLongitude() const;
    int getHouseNumber() const;
    const std::string& getStreetName() const;

    void setLatitude(double lat);
    void setLongitude(double lon);
    void setHouseNumber(int houseNum);
    void setStreetName(const std::string& street);

    void printAddress() const;
};