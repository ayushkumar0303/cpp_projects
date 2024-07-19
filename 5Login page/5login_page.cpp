#include <iostream>
#include<string>
#include<unistd.h>
#include<termios.h>

using namespace std;

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 15

struct User
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
};

User users[MAX_USERS];

void user_registration();
int user_login();
void fgets_change(char *);
void login_credential(char *, char *);
void input_password(char *);

int user_count = 0;
int main(int argc, char const *argv[])
{
    int user_index;
    int choice;
    while (1)
    {

        cout << "\n1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        // getc(stdin);
        // or getchar() is equivalent to getc(stdin);
        // or
        cin.ignore(); // clear newline character from input buffer

        switch (choice)
        {
        case 1:
            user_registration();
            break;
        case 2:
            user_index = user_login();
            if (user_index >= 0)
            {
                cout << "\nLogin successfull !!! welcome " << users[user_index].username << "!" << endl;
            }
            else
            {
                cout << "\nLogin faild !!! Incorrect username or password" << endl;
            }
            break;
        case 3:
            cout << "\nExiting..."<<endl;
            // exit(0);
            // or
            return 0;
        default:
            cout<<"\nInvalid choice..."<<endl;
            break;
        }
    }
    // return 0;
}

void user_registration()
{
    if (user_count >= MAX_USERS)
    {
        cout << "\nMax user limit exceeded" << endl;
        return;
    }
    int user_index = user_count;
    cout << "\nRegister new user" << endl;
    login_credential(users[user_index].username,users[user_index].password);
    
    user_count++;
    cout << "\nRegistration successful!!!" << endl;
}

int user_login()
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    login_credential(username,password);
    for (int i = 0; i < MAX_USERS; i++)
    {

        if (strcmp(users[i].username, username) == 0 and strcmp(users[i].password, password) == 0)
        {
            // if(users[i].username==username and users[i].password==password){
            return i;
        }
    }

    return -1;
}
void login_credential(char * username, char* password){
    cout << "Enter username: ";
    fgets(username, CREDENTIAL_LENGTH, stdin);
    // or
    // cin.getline(username, CREDENTIAL_LENGTH);
    fgets_change(username);
    input_password(password);
}

void input_password(char * password){
    cout << "Enter password (masking enabled): ";
    fflush(stdout);
    termios old_props, new_props;
    tcgetattr(STDIN_FILENO, &old_props);
    new_props=old_props;
    new_props.c_lflag= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO,TCSANOW,&new_props);

    // fgets(password, CREDENTIAL_LENGTH, stdin);
    // fgets_change(password);

    char ch;
    int i=0;
    while((ch=getchar())!='\n' and ch!=EOF){
        if(ch!='\b' and ch!=127){ // 127 is ASCII for DEL
            password[i++]=ch;
            cout<<"*";
        }else{
            if(i>0){
                i--;
                cout<<"\b \b";

            }
        }

    }
    password[i]='\0';
    
    tcsetattr(STDIN_FILENO,TCSANOW,&old_props);


}
void fgets_change(char *str)
{
    int index = strcspn(str, "\n");
    // int index = str.find("\n") //str is a type of string based on c style
    str[index] = '\0';
}