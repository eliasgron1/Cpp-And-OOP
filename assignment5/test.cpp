#include <iostream>
#include <string>

void printStrings(const std::string* strings, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << strings[i] << std::endl;
    }
}

int main() {
    int size;
    std::cout << "Enter the number of strings: ";
    std::cin >> size;

    // Create an array of strings based on user input
    std::string myStrings[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> myStrings[i];
    }

    // Pass the array to the function using a pointer
    printStrings(myStrings, size);

    return 0;
}