#include <iostream>
#include <stdexcept>
#include <exception>
#include <cmath>

using namespace std;
void print_menu();

void Addition(double a, double b)
{
    cout << "Addition = " << a + b << endl;
}
void Subtraction(double a, double b)
{
    cout << "Subtraction = " << a - b << endl;
}
void Multiplication(double a, double b)
{
    cout << "Multiplication = " << a * b << endl;
}
void Division(double a, double b)
{
    try
    {
        if (b == 0)
        {
            throw runtime_error("Division by zero not allowed");
        }
        cout << "Divison = " << a / b << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception " << e.what() << endl;
    }
}
void Power(double a, double b)
{
    double result = 1;
    while (b != 0)
    {
        result *= a;
        b--;
    }
    cout << "Power = " << result << endl;
}
void Modulus(int a, int b)
{
    try
    {
        if (b == 0)
        {
            throw runtime_error("Modulus by zero not allowed");
        }

        cout << "Modulus = " << a % b << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception " << e.what() << endl;
    }
}
int main()
{
    while (true)
    {
        print_menu();
        int choice;
        cout << "Enter your choice" << endl;
        cin >> choice;
        double a, b;
        if (choice < 1 || choice > 7)
        {
            cout << "No choice matched!!! please make a choice from the given options" << endl;
            continue;
        }
        if (choice == 7)
        {
            break;
        }
        cout << "Enter first number" << endl;
        cin >> a;
        cout << "Enter second number" << endl;
        cin >> b;
        switch (choice)
        {
        case 1:
            Addition(a, b);
            break;
        case 2:
            Subtraction(a, b);
            break;
        case 3:
            Multiplication(a, b);
            break;
        case 4:
            Division(a, b);
            break;
        case 5:
            Modulus(a, b);
            break;
        case 6:
            Power(a, b);
            break;
        }
    }
}

void print_menu()
{
    cout << "=====================" << endl;
    cout << "\nCalculator!!!" << endl;
    cout << endl
         << endl;
    cout << "Enter your choice" << endl;
    cout << "1 Addition" << endl;
    cout << "2 Subtraction" << endl;
    cout << "3 Multiplication" << endl;
    cout << "4 Division" << endl;
    cout << "5 Modulus" << endl;
    cout << "6 Power" << endl;
    cout << "7 exit" << endl;
}