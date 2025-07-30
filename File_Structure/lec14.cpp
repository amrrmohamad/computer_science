#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    const string filename = "data.bin";
    int originalArray[] = {10, 20, 30, 40, 50};
    const int size = sizeof(originalArray) / sizeof(originalArray[0]);

    // Write array to binary file
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile.write(reinterpret_cast<const char*>(originalArray), sizeof(originalArray));
    outFile.close();

    cout << "Array written to binary file successfully." << endl;

    // Read array back from binary file
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Get file size
    inFile.seekg(0, ios::end);
    streampos fileSize = inFile.tellg();
    inFile.seekg(0, ios::beg);

    // Calculate number of elements
    int numElements = fileSize / sizeof(int);
    int* readArray = new int[numElements];

    inFile.read(reinterpret_cast<char*>(readArray), fileSize);
    inFile.close();

    cout << "Array read from binary file:" << endl;
    for (int i = 0; i < numElements; ++i) {
        cout << readArray[i] << " ";
    }
    cout << endl;

    delete[] readArray;
    return 0;
}
