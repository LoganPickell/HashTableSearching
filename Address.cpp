// Address.cpp
#pragma once
#include "Address.h"

Address::Address() : latitude(0.0), longitude(0.0), houseNumber(0), streetName("") {}

Address::Address(double lat, double lon, int houseNum, const std::string& street) :
    latitude(lat), longitude(lon), houseNumber(houseNum), streetName(street) {}

Address::Address(const Address& other) :
    latitude(other.latitude), longitude(other.longitude),
    houseNumber(other.houseNumber), streetName(other.streetName) {}

Address::~Address() {}

double Address::getLatitude() const { return latitude; }
double Address::getLongitude() const { return longitude; }
int Address::getHouseNumber() const { return houseNumber; }
const std::string& Address::getStreetName() const { return streetName; }

void Address::setLatitude(double lat) { latitude = lat; }
void Address::setLongitude(double lon) { longitude = lon; }
void Address::setHouseNumber(int houseNum) { houseNumber = houseNum; }
void Address::setStreetName(const std::string& street) { streetName = street; }

void Address::printAddress() const {
    std::cout << "Latitude: " << latitude << ", Longitude: " << longitude
        << ", House Number: " << houseNumber << ", Street Name: " << streetName << std::endl;
}
