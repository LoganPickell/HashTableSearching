#include <iostream>
#include <fstream>
#include "Address.h"
#include "HashTable.h"


using namespace std;

// Function to read addresses from a file and insert them into the hash table
void readAddressesFromFile(const string& filename, HashTable& hashTable) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << "address.txt" << endl;
        return;
    }

    double latitude, longitude;
    int houseNumber;
    string streetName;

    while (file >> latitude >> longitude >> houseNumber) {
        file.ignore(1);
        getline(file, streetName); // Read the rest of the line as the street name

        Address address(latitude, longitude, houseNumber, streetName);
        hashTable.insertAddress(address);
    }

    file.close();
}

int main() {
    HashTable addressTable;

    // Read addresses from the file and insert into the hash table
    readAddressesFromFile("address.txt", addressTable);


        while (true) 
    {
            string streetName{};
            int houseNumber{};
        cout << "Enter street name (or 'exit' to quit): ";
        if (!(getline(cin, streetName)))
        {
            // Handle invalid input or end-of-file
            break;
        }

        if (streetName == "exit") {
            break;
        }

        cout << "Enter house number: ";
        if (!(cin >> houseNumber)) {
            // Handle invalid input or end-of-file
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        const Address* result = addressTable.searchAddress(houseNumber, streetName);

        // If no address found, try nearby house numbers
        if (result == nullptr) {
            for (int offset = 1; offset <= 2; ++offset) {
                result = addressTable.searchAddress(houseNumber + offset, streetName);
                if (result != nullptr) {
                    break;
                }

                result = addressTable.searchAddress(houseNumber - offset, streetName);
                if (result != nullptr) {
                    break;
                }
            }
        }

        // Print the result
        if (result != nullptr) {
            cout << "Address found: ";
            result->printAddress();
        }
        else {
            cout << "No address found for the given input." << endl;
        }

    }

    return 0;
}