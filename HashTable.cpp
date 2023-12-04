// HashTable.cpp
#pragma once
#include "HashTable.h"

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr; // Initialize all pointers to nullptr
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete table[i]; // Delete each Address object
    }
}

int HashTable::hashFunction(int houseNumber) const {
    return houseNumber % TABLE_SIZE; // Simple hash function using modulo
}

void HashTable::insertAddress(const Address& address) {
    int index = hashFunction(address.getHouseNumber());

    // Linear probing until an empty slot is found
    while (table[index] != nullptr) {
        index = (index + 1) % TABLE_SIZE;
    }

    // Insert the Address object
    table[index] = new Address(address);
}

const Address* HashTable::searchAddress(int houseNumber, const std::string& street) const {
    int index = hashFunction(houseNumber);

    // Linear probing until the desired item is found or an empty slot is encountered
    while (table[index] != nullptr) {
        if (table[index]->getHouseNumber() == houseNumber && table[index]->getStreetName() == street) {
            return table[index]; // Return the matching Address object
        }

        index = (index + 1) % TABLE_SIZE;
    }

    return nullptr; // Address not found
}
