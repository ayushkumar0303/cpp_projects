#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int generate_number(){
    int lb =1, ub=100;
    return rand()%(ub-lb+1)+lb;
}

int main()
{
    srand(time(0));
    cout<<"\nWelcome in the world of Guessing Number Game!!!"<<endl;
    int number, guess,no_of_guess=0;
    number=generate_number();
    do
    {
        no_of_guess++;
        cout<<"Please enter your guess number between 1 to 100"<<endl;
        cin>>guess;
        if(guess>number){
            cout<<"Enter smaller number"<<endl;
        }else if((guess<number)){
            cout<<"Enter larger number"<<endl;
        }else{
            cout<<"Congratulations!!! you got the correct number in "<< no_of_guess << " attempts"<<endl;

        }

    } while (number!=guess);

    cout<<"Bye bye, Thanks for playing!!!"<<endl;
    return 0;
}
