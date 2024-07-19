#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>
// #include <cstdlib>
using namespace std;
void fill_time(char [], int , int);
void fill_date(char [], int);
int print_menu();
void clear_screen();

int main(int argc, char const *argv[])
{
    int choice =print_menu();
    char time_buffer[50], date_buffer[100];
    while (1)
    {
        clear_screen();
        fill_time(time_buffer,choice, sizeof(time_buffer));
        fill_date(date_buffer,sizeof(date_buffer));
        sleep(1);
    }

    return 0;
}

void clear_screen(){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void fill_time(char time_buffer[], int choice, int size){
    time_t raw_time = time(NULL);
    tm *current_time = localtime(&raw_time);

     if (choice == 1)
    {
        strftime(time_buffer, size, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(time_buffer, size, "%I:%M:%S %p", current_time);
    }
    cout << "Current Time: " << time_buffer << endl;


}

void fill_date(char date_buffer[], int size){
    time_t raw_time = time(NULL);
    tm *current_time = localtime(&raw_time);

    strftime(date_buffer, size, "%A %B %d %Y", current_time);
    cout << "Date: " << date_buffer << endl;

}

int print_menu(){
    int choice;
    cout << "====================" << endl;
    cout << "Digital Clock" << endl;
    cout << "Choose the time format" << endl;
    cout << "1. 24 Hour format" << endl;
    cout << "2. 12 Hour format (default)" << endl;
    cout << "Make a choice (1/2)" << endl;
    cin >> choice;
    return choice;
}
