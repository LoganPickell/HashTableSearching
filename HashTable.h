// HashTable.h
#pragma once
#include "Address.h"

class HashTable {
private:
    static const int TABLE_SIZE = 1000;  // Size of the hash table
    Address* table[TABLE_SIZE];       // Array of pointers to Address objects

    int hashFunction(int houseNumber) const;  // Private method to calculate the hash index

public:
    HashTable();  // Constructor
    ~HashTable(); // Destructor

    void insertAddress(const Address& address);  // Method to insert an Address object
    const Address* searchAddress(int houseNumber, const std::string& street) const;  // Method to search for an Address object
};
