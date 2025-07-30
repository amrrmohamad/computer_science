#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    const string inputFile = "example.txt";
    const string outputFile = "sorted.txt";
    
    // Count number of lines first
    ifstream countFile(inputFile);
    if (!countFile.is_open()) {
        cerr << "Error: Could not open " << inputFile << endl;
        return 1;
    }

    int lineCount = 0;
    string temp;
    while (getline(countFile, temp)) {
        lineCount++;
    }
    countFile.close();

    // Allocate array dynamically
    string* lines = new string[lineCount];

    // Read file contents into array
    ifstream inFile(inputFile);
    for (int i = 0; i < lineCount; i++) {
        getline(inFile, lines[i]);
    }
    inFile.close();

    // Sort the array
    sort(lines, lines + lineCount);

    // Write sorted lines to output file
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "Error: Could not create " << outputFile << endl;
        delete[] lines;
        return 1;
    }

    for (int i = 0; i < lineCount; i++) {
        outFile << lines[i] << endl;
    }
    outFile.close();

    // Clean up
    delete[] lines;

    cout << "File sorted successfully. Output written to " << outputFile << endl;

    return 0;
}
