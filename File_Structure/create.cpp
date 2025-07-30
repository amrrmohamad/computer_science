#include <iostream>
#include <fstream>

int main() {
     std::ofstream outFile("example.txt");

     if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }

    outFile << "Hello, World!";

    outFile.close();

    std::cout << "Text written to example.txt successfully!" << std::endl;

    return 0;
}
