#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Employee
{
    int id;
    string name;
    int age;
    string department;
    double salary;
    Employee *next;
};

const string databaseFile = "company_database.txt";
Employee *head = nullptr;
int employeeCount = 0;

void loadDatabase()
{
    ifstream file(databaseFile);
    if (!file.is_open())
        return;

    Employee *current = nullptr;
    Employee temp;
    while (file >> temp.id >> temp.name >> temp.age >> temp.department >> temp.salary)
    {
        Employee *newEmp = new Employee;
        *newEmp = temp;
        newEmp->next = nullptr;

        if (head == nullptr)
        {
            head = newEmp;
        }
        else
        {
            current->next = newEmp;
        }
        current = newEmp;
        employeeCount++;
    }
    file.close();
}

void saveDatabase()
{
    ofstream file(databaseFile);
    Employee *current = head;
    while (current != nullptr)
    {
        file << current->id << " " << current->name << " " << current->age << " "
             << current->department << " " << current->salary << "\n";
        current = current->next;
    }
    file.close();
}

void addEmployee()
{
    Employee *newEmp = new Employee;
    cout << "\nEnter Employee Details:\n";
    cout << "ID: ";
    cin >> newEmp->id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newEmp->name);
    cout << "Age: ";
    cin >> newEmp->age;
    cout << "Department: ";
    cin.ignore();
    getline(cin, newEmp->department);
    cout << "Salary: ";
    cin >> newEmp->salary;
    newEmp->next = nullptr;

    if (head == nullptr)
    {
        head = newEmp;
    }
    else
    {
        Employee *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newEmp;
    }
    employeeCount++;
    cout << "Employee added successfully!\n";
}

void deleteEmployee()
{
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Employee *current = head;
    Employee *prev = nullptr;

    while (current != nullptr && current->id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Employee not found!\n";
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
    employeeCount--;
    cout << "Employee deleted successfully!\n";
}

void updateEmployee()
{
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    Employee *current = head;
    while (current != nullptr && current->id != id)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Employee not found!\n";
        return;
    }

    cout << "Enter new details:\n";
    cout << "Name (" << current->name << "): ";
    cin.ignore();
    getline(cin, current->name);
    cout << "Age (" << current->age << "): ";
    cin >> current->age;
    cout << "Department (" << current->department << "): ";
    cin.ignore();
    getline(cin, current->department);
    cout << "Salary (" << current->salary << "): ";
    cin >> current->salary;

    cout << "Employee updated successfully!\n";
}

void searchEmployee()
{
    int choice;
    cout << "Search by:\n1. ID\n2. Name\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int id;
        cout << "Enter Employee ID: ";
        cin >> id;

        Employee *current = head;
        while (current != nullptr)
        {
            if (current->id == id)
            {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << current->id << "\n";
                cout << "Name: " << current->name << "\n";
                cout << "Age: " << current->age << "\n";
                cout << "Department: " << current->department << "\n";
                cout << "Salary: " << current->salary << "\n";
                return;
            }
            current = current->next;
        }
    }
    else if (choice == 2)
    {
        string name;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);

        Employee *current = head;
        bool found = false;
        while (current != nullptr)
        {
            if (current->name == name)
            {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << current->id << "\n";
                cout << "Name: " << current->name << "\n";
                cout << "Age: " << current->age << "\n";
                cout << "Department: " << current->department << "\n";
                cout << "Salary: " << current->salary << "\n\n";
                found = true;
            }
            current = current->next;
        }
        if (!found)
        {
            cout << "No employees found with that name.\n";
        }
        return;
    }
    cout << "Employee not found!\n";
}

void displayAllEmployees()
{
    if (head == nullptr)
    {
        cout << "No employees in the database.\n";
        return;
    }

    cout << "\nEmployee List (" << employeeCount << " employees):\n";
    cout << "-------------------------------------------------\n";
    Employee *current = head;
    while (current != nullptr)
    {
        cout << "ID: " << current->id << "\n";
        cout << "Name: " << current->name << "\n";
        cout << "Age: " << current->age << "\n";
        cout << "Department: " << current->department << "\n";
        cout << "Salary: " << current->salary << "\n";
        cout << "-------------------------------------------------\n";
        current = current->next;
    }
}

void freeMemory()
{
    Employee *current = head;
    while (current != nullptr)
    {
        Employee *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    employeeCount = 0;
}

int main()
{
    loadDatabase();

    while (true)
    {
        cout << "\nEmployee Database Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Update Employee\n";
        cout << "4. Search Employee\n";
        cout << "5. Display All Employees\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            updateEmployee();
            break;
        case 4:
            searchEmployee();
            break;
        case 5:
            displayAllEmployees();
            break;
        case 6:
            saveDatabase();
            freeMemory();
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
