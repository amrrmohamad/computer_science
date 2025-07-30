#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt");

    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    std::string fileContents;
    std::string line;

    while (std::getline(inFile, line)) {
        fileContents += line + "\n";
    }

    inFile.close();

    std::cout << "Contents of example.txt:\n";
    std::cout << fileContents;

    return 0;
}
