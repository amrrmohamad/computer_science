#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string DB_FILE = "database.txt";

struct Record
{
    int id;
    string name;
    int age;
    string city;
};

void addRecord()
{
    ofstream file(DB_FILE, ios::app);
    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    Record r;
    cout << "Enter ID: ";
    cin >> r.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, r.name);
    cout << "Enter Age: ";
    cin >> r.age;
    cout << "Enter City: ";
    cin.ignore();
    getline(cin, r.city);

    file << r.id << "|" << r.name << "|" << r.age << "|" << r.city << "\n";
    file.close();
    cout << "Record added!\n";
}

void viewRecords()
{
    ifstream file(DB_FILE);
    if (!file)
    {
        cout << "No records found!\n";
        return;
    }

    string line;
    cout << "\nID\tName\tAge\tCity\n";
    cout << "------------------------\n";
    while (getline(file, line))
    {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);

        cout << line.substr(0, pos1) << "\t"
             << line.substr(pos1 + 1, pos2 - pos1 - 1) << "\t"
             << line.substr(pos2 + 1, pos3 - pos2 - 1) << "\t"
             << line.substr(pos3 + 1) << "\n";
    }
    file.close();
}

void deleteRecord()
{
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    ifstream inFile(DB_FILE);
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;
    while (getline(inFile, line))
    {
        if (stoi(line.substr(0, line.find("|"))) != id)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove(DB_FILE.c_str());
    rename("temp.txt", DB_FILE.c_str());

    cout << (found ? "Record deleted!\n" : "Record not found!\n");
}

void updateRecord()
{
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    ifstream inFile(DB_FILE);
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;
    while (getline(inFile, line))
    {
        if (stoi(line.substr(0, line.find("|"))) == id)
        {
            Record r;
            r.id = id;
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, r.name);
            cout << "Enter new Age: ";
            cin >> r.age;
            cout << "Enter new City: ";
            cin.ignore();
            getline(cin, r.city);

            tempFile << r.id << "|" << r.name << "|" << r.age << "|" << r.city << "\n";
            found = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    inFile.close();
    tempFile.close();

    remove(DB_FILE.c_str());
    rename("temp.txt", DB_FILE.c_str());

    cout << (found ? "Record updated!\n" : "Record not found!\n");
}

int main()
{
    while (true)
    {
        cout << "\nFile Database System\n";
        cout << "1. Add Record\n";
        cout << "2. View Records\n";
        cout << "3. Delete Record\n";
        cout << "4. Update Record\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            updateRecord();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
