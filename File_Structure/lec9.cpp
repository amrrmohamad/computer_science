#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "example.txt";
    string searchWord = "World";
    ifstream file(filename);
    string line;
    int lineNumber = 1;
    bool found = false;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    cout << "The word \"" << searchWord << "\" appears on line(s): ";
    
    while (getline(file, line)) {
        if (line.find(searchWord) != string::npos) {
            cout << lineNumber << " ";
            found = true;
        }
        lineNumber++;
    }

    if (!found) {
        cout << "(not found)";
    }

    cout << endl;
    file.close();
    return 0;
}
