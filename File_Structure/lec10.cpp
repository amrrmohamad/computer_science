#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string inputFile, outputFile, line;
    int choice, shift = 3; // Default shift of 3 for Caesar cipher
    char confirm;

    cout << "Simple File Encryption/Decryption\n";
    cout << "1. Encrypt file\n";
    cout << "2. Decrypt file\n";
    cout << "3. Cancel\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 3) {
        cout << "Operation cancelled.\n";
        return 0;
    }

    cout << "Enter input filename: ";
    cin >> inputFile;
    cout << "Enter output filename: ";
    cin >> outputFile;
    cout << "Use shift value (default 3): ";
    cin >> shift;

    cout << "Confirm (y/n)? ";
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Operation cancelled.\n";
        return 0;
    }

    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cout << "Error opening input file!\n";
        return 1;
    }

    if (!outFile) {
        cout << "Error creating output file!\n";
        inFile.close();
        return 1;
    }

    while (getline(inFile, line)) {
        for (char &c : line) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                if (choice == 1) // Encrypt
                    c = base + (c - base + shift) % 26;
                else // Decrypt
                    c = base + (c - base - shift + 26) % 26;
            }
        }
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();

    cout << "Operation completed successfully!\n";
    
    if (choice == 2) { // Show decrypted content
        cout << "\nDecrypted content:\n";
        ifstream result(outputFile);
        while (getline(result, line))
            cout << line << "\n";
        result.close();
    }

    return 0;
}
