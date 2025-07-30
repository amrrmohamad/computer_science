#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "example.txt";
    std::ofstream outfile;
    
    outfile.open(filename, std::ios::app);
    
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    
    outfile << "This is a new line." << std::endl;
    outfile.close();
    
    std::cout << "Text appended successfully." << std::endl;
    
    return 0;
}

