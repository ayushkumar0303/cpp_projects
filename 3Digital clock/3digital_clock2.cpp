#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

string weekDay(int);
string month(int);
void clear_screen();

void hour12_format()
{
    // first method
    // while(true){
    //     system("clear");
    //     time_t tt = time(NULL);
    //     // cout<<tt<<endl;
    //     tm *ti = localtime(&tt);
    //     cout<<asctime(ti)<<endl;
    //     sleep(1);
    // }

    // second method
    // while(true){
    //     system("clear");
    //     time_t tt = time(NULL);
    //     cout<<ctime(&tt)<<endl;
    //     sleep(1);
    // }

    // third methode
    while (true)
    {
        clear_screen();
        time_t tt = time(NULL);
        tm *timePtr = localtime(&tt);

        int min = timePtr->tm_min;
        int sec = timePtr->tm_sec;
        int hr = timePtr->tm_hour;
        int day = timePtr->tm_wday;
        int date = timePtr->tm_mday;
        int year = timePtr->tm_year;
        int mnt = timePtr->tm_mon;

        string timeStr = (hr >= 12) ? "PM" : "AM";
        hr = (hr % 12 == 0) ? 12 : hr % 12;

        cout << "Current Time: " << setfill('0') << setw(2) << hr << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << " " << timeStr << endl;
        cout << "Date: " << weekDay(day) << " " << month(mnt) << " " << date << " " << year + 1900 << endl;

        sleep(1);
    }
}

void hour24_format()
{
    while (true)
    {
        clear_screen();
        time_t tt = time(NULL);
        tm *timePtr = localtime(&tt);

        int min = timePtr->tm_min;
        int sec = timePtr->tm_sec;
        int hr = timePtr->tm_hour;
        int day = timePtr->tm_wday;
        int date = timePtr->tm_mday;
        int year = timePtr->tm_year;
        int mnt = timePtr->tm_mon;

        cout << "Current Time: " << setfill('0') << setw(2) << hr << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << sec << " " << endl;
        cout << "Date: " << weekDay(day) << " " << month(mnt) << " " << date << " " << year + 1900 << endl;

        sleep(1);
    }
}

int main()
{
    int choice;
    cout << "====================" << endl;
    cout << "\nDigital Clock" << endl;
    cout << "Choose the time format" << endl;
    cout << "1. 24 Hour format" << endl;
    cout << "2. 12 Hour format (default)" << endl;
    cout << "Make a choice (1/2)" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        hour24_format();
        break;
    default:
        hour12_format();
        break;
    }

    return 0;
}

void clear_screen()
{

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
string weekDay(int n)
{
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[n];
}

string month(int n)
{
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[n];
}