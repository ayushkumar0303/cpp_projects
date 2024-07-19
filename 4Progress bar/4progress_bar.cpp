#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include<ctime>

using namespace std;

static int BAR_LENGTH = 50;
static int MAX_TASKS = 5;

struct Task
{
    int id;
    int progress;
    int speed;
};

void print_bars(Task);
void clear_screen();

int main(int argc, char const *argv[])
{
    srand(time(0));
    int ll=3, hl=6;

    struct Task tasks[MAX_TASKS];
    for (int i = 0; i < MAX_TASKS; i++)
    {

        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].speed = rand()%(hl-ll+1)+ll;
    }
    bool task_incomplete = 1;
    while (task_incomplete)
    {
        task_incomplete = 0;
        clear_screen();

        for (int i = 0; i < MAX_TASKS; i++)
        {

            tasks[i].progress += tasks[i].speed;
            if (tasks[i].progress >100)
            {
                tasks[i].progress = 100;
            }
            else if (tasks[i].progress < 100)
            {
                task_incomplete = 1;
            }

            print_bars(tasks[i]);
        }
        sleep(1);
    }

    cout<<"All tasks completed!!!"<<endl;

    return 0;
}
void print_bars(Task tasks)
{
    int show_bar_length = (tasks.progress * BAR_LENGTH) / 100;
    cout << "Task" << " " << tasks.id << ": [";
    for (int i = 0; i < BAR_LENGTH; i++)
    {
        if (i < show_bar_length)
        {
            cout << "=";
        }
        else
        {
            cout << " ";
        }
    }
    cout << "]" << " " << tasks.progress << "%" << endl;
}

void clear_screen(){
    #ifdef _Win32
        system("cls");
    #else
        system("clear");
    #endif
}