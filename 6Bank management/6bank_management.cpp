#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

struct Account
{
    char name[100];
    int account_no;
    float money;
};

Account acc;

// Account acc[MAX_CUSTOMER]={}; // initialize each variable with 0
// Account acc[MAX_CUSTOMER];

int main()
{
    int choice;
    bool running = true;
    while (running)
    {
        cout << "\n*** Bank Management System ***" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            create_account();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            check_balance();
            break;
        case 5:
            running = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}

void create_account()
{
    int account;
    fstream file;
    file.open("account.dat", ios::in | ios::out | ios::binary | ios::app);

    if (file.is_open() == false)
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    cout << "Enter your name" << endl;
    cin.getline(acc.name, 100);
    cout << "Enter your account number" << endl;
    cin >> account;
    // cin.ignore();
    file.seekg(0, ios::beg);
    while (file.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        if (acc.account_no == account)
        {
            cerr << "Account number already existed. Please choose a different account number" << endl;
            file.close();
            return;
        }
    }
    file.clear(); // clear EOF flag and any other error flags
    file.seekp(0, ios::end);
    acc.account_no = account;
    acc.money = 0;
    file.write(reinterpret_cast<const char *>(&acc), sizeof(acc));
    file.close();
    cout << "Account created successfully" << endl;
}

void deposit_money()
{
    int account;
    cout << "Enter your account number" << endl;
    cin >> account;
    float deposit;
    cout << "Enter amount to deposit: ";
    cin >> deposit;
    fstream file;
    file.open("account.dat", ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    while (file.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        if (acc.account_no == account)
        {

            acc.money += deposit;
            file.seekp(-sizeof(acc), ios::cur);
            file.write(reinterpret_cast<const char *>(&acc), sizeof(acc));
            file.close();
            cout << fixed << setprecision(2) << "Successfully deposit: " << deposit << ". New Balance is: " << acc.money << endl;
            return;
        }
    }
    cout << "Account not found" << endl;
    file.close();
}

void withdraw_money()
{
    int account;
    cout << "Enter your account number" << endl;
    cin >> account;
    float withdraw;
    cout << "Enter amount to withdraw: ";
    cin >> withdraw;
    fstream file;
    file.open("account.dat", ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    while (file.read(reinterpret_cast<char *>(&acc), sizeof(acc)))
    {
        if (acc.account_no == account)
        {
            if (acc.money >= withdraw)
            {
                acc.money -= withdraw;
                file.seekp(-sizeof(acc), ios::cur);
                file.write(reinterpret_cast<const char *>(&acc), sizeof(acc));
                cout << fixed << setprecision(2) << "Successfully withdrawn: " << withdraw << ". Remaining Balance is: " << acc.money << endl;
            }
            else
            {

                cout << "Insufficient balance" << endl;
            }
            file.close();
            return;
        }
    }
    cout << "Account not found" << endl;
    file.close();
}
void check_balance()
{
    float account;
    cout << "Enter your account number" << endl;
    cin >> account;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile.is_open())
    {
        cerr << "Unable to open file" << endl;
        return;
    }
    while (!inFile.eof())
    {
        inFile.read(reinterpret_cast<char *>(&acc), sizeof(acc)); // or we can directly pass this line as an argument in the while loop without using !inFile.eof()
        if (acc.account_no == account)
        {
            inFile.close();
            cout << fixed << setprecision(2) << "Availabe balance is: " << acc.money << endl;
            return;
        }
    }
    cout << "Account not found" << endl;
    inFile.close();
}
