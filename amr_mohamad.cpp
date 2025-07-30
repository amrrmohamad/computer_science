#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Function prototypes
double polynomialEquation(double x);
double trigonometricEquation(double x);
double exponentialEquation(double x);
void getPolynomialCoefficients();
void printMenu();

// Global variables for equation parameters
double poly_a = 0, poly_b = 0, poly_c = 0, poly_d = 0; // Third degree poly
double trig_c = 0, trig_choice = 0;                    // Trig
double exp_c = 0, exp_a = 0, exp_choice = 0;           // Exp

int main()
{
    cout << "BISECTION METHOD EQUATION SOLVER\n";
    cout << "================================\n\n";

    int equationType;
    double a, b, error;
    double (*equation)(double) = nullptr;

    // Main menu
    printMenu();
    cin >> equationType;

    // Validate equation type input
    while (equationType < 1 || equationType > 3)
    {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
        cin >> equationType;
    }

    // Handle each equation type
    if (equationType == 1)
    { // Poly
        getPolynomialCoefficients();
        equation = polynomialEquation;

        cout << "\nYou selected polynomial equation: ";
        if (poly_a != 0)
        {
            cout << poly_a << "x^3";
        }

        if (poly_b != 0)
        {
            if (poly_a != 0)
            {
                cout << " + ";
            }
            cout << poly_b << "x^2";
        }
        if (poly_c != 0)
        {
            if (poly_a != 0 || poly_b != 0)
            {
                cout << " + ";
            }
            cout << poly_c << "x";
        }
        if (poly_d != 0)
        {
            if (poly_a != 0 || poly_b != 0 || poly_c != 0)
            {
                cout << " + ";
            }
            cout << poly_d;
        }
        cout << " = 0" << endl;
    }
    else if (equationType == 2)
    { // Trig
        cout << "\nChoose trigonometric function:\n";
        cout << "1. sin(x) - c = 0\n";
        cout << "2. cos(x) - c = 0\n";
        cout << "3. tan(x) - c = 0\n";
        cout << "Enter your choice (1-3): ";
        cin >> trig_choice;

        cout << "Enter the constant c: ";
        cin >> trig_c;

        equation = trigonometricEquation;

        cout << "You selected equation: ";
        switch ((int)trig_choice)
        {
        case 1:
            cout << "sin(x) - " << trig_c << " = 0";
            break;
        case 2:
            cout << "cos(x) - " << trig_c << " = 0";
            break;
        case 3:
            cout << "tan(x) - " << trig_c << " = 0";
            break;
        }
        cout << endl;
    }
    else if (equationType == 3)
    { // Exponential
        cout << "\nChoose exponential function:\n";
        cout << "1. e^x - c = 0\n";
        cout << "2. a^x - c = 0\n";
        cout << "Enter your choice (1-2): ";
        cin >> exp_choice;

        if (exp_choice == 1)
        {
            cout << "Enter the constant c: ";
            cin >> exp_c;
        }
        else
        {
            cout << "Enter base a: ";
            cin >> exp_a;
            cout << "Enter the constant c: ";
            cin >> exp_c;
        }

        equation = exponentialEquation;

        cout << "You selected equation: ";
        if (exp_choice == 1)
        {
            cout << "e^x - " << exp_c << " = 0";
        }
        else
        {
            cout << exp_a << "^x - " << exp_c << " = 0";
        }
        cout << endl;
    }

    // Get interval [a, b]
    cout << "\nEnter interval [a, b] where the root is to be found:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    // Get error tolerance
    cout << "Enter maximum allowed error: ";
    cin >> error;

    // Bisection method implementation
    if (equation(a) * equation(b) >= 0)
    {
        cout << "The function must have opposite signs at the endpoints.\n";
        cout << "f(" << a << ") = " << equation(a) << endl;
        cout << "f(" << b << ") = " << equation(b) << endl;
        return 1;
    }

    double c;
    int n = 0;
    const int max_iterations = 100;

    cout << "\nStarting bisection method...\n";
    cout << "    n     |    a     |     b    |     x    |    f(x)    |  Error  \n";
    cout << "-------------------------------------------------------------------\n";

    do
    {
        c = (a + b) / 2;
        n++;

        cout << setw(9) << n << " | "
             << setw(8) << setprecision(5) << fixed << a << " | "
             << setw(8) << setprecision(5) << fixed << b << " | "
             << setw(8) << setprecision(5) << fixed << c << " | "
             << setw(8) << setprecision(5) << scientific << equation(c) << " | "
             << setw(8) << setprecision(2) << scientific << (b - a) / 2 << endl;

        if (equation(c) == 0.0)
        {
            break;
        }
        else if (equation(c) * equation(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    } while (fabs(b - a) >= error && n < max_iterations);

    cout << "\nFinal Result:\n";
    cout << "Approximate root: " << setprecision(10) << c << endl;
    cout << "Function value at root: " << setprecision(10) << equation(c) << endl;
    cout << "Iterations: " << n << endl;
    cout << "Final error: " << setprecision(5) << scientific << (b - a) / 2 << endl;

    return 0;
}

void printMenu()
{
    cout << "Choose equation type:\n";
    cout << "1. Polynomial (e.g., x^3 - 2x + 1 = 0)\n";
    cout << "2. Trigonometric (e.g., sin(x) - 0.5 = 0)\n";
    cout << "3. Exponential (e.g., e^x - 5 = 0)\n";
    cout << "Enter your choice (1-3): ";
}

void getPolynomialCoefficients()
{
    cout << "\nEnter coefficients for polynomial (up to cubic):\n";
    cout << "For equation: ax^3 + bx^2 + cx + d = 0\n";
    cout << "Enter a (coefficient for x^3, 0 if not cubic): ";
    cin >> poly_a;
    if (poly_a == 0)
    {
        cout << "Equation is not cubic. Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'n')
        {
            cout << "Enter coeff again\n";
            getPolynomialCoefficients();
        }
    }
    cout << "Enter b (coefficient for x^2): ";
    cin >> poly_b;
    cout << "Enter c (coefficient for x): ";
    cin >> poly_c;
    cout << "Enter d (constant term): ";
    cin >> poly_d;
}

double polynomialEquation(double x)
{
    return poly_a * pow(x, 3) + poly_b * pow(x, 2) + poly_c * x + poly_d;
}

double trigonometricEquation(double x)
{
    switch ((int)trig_choice)
    {
    case 1:
        return sin(x) - trig_c;
    case 2:
        return cos(x) - trig_c;
    case 3:
        return tan(x) - trig_c;
    default:
        return 0;
    }
}

double exponentialEquation(double x)
{
    if (exp_choice == 1)
    {
        return exp(x) - exp_c;
    }
    else
    {
        return pow(exp_a, x) - exp_c;
    }
}