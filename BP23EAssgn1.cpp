//*****************************************************git
//* Program Name: Suggested Lottery Number Generator  *
//* Description: Generating lottery tickets based     *
//               on user input                        *
//* Date: 01/13/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int MAX_BALLS = 7;
const int MIN_BALLS = 3;
const int MAX_RANGE = 70;
const int MIN_RANGE = 45;
const int MAX_TICKETS = 100;
const int MIN_TICKETS = 1;

void Get_Num_Balls_From_User(int &number_of_balls);
void Get_Range_Num(int &max_number);
void Get_Num_Tickets(int &number_of_tickets);
void Generate_Lottery_Tickets(int number_of_balls , int max_number, int number_of_tickets);
bool Is_Duplicate(int number, const int used[], int size);

using namespace std;

int main() {
    int number_of_balls = 0;
    int max_number = 0;
    int number_of_tickets = 0;

    cout<<"\nEnter in the number of balls or numbers you wish to pick from ";
    Get_Num_Balls_From_User(number_of_balls);

    cout<<"\nEnter in the largest number in the lottery.";
    Get_Range_Num(max_number);

    cout<<"\nEnter the number of tickets 1-100 inclusive: ";
    Get_Num_Tickets(number_of_tickets);

    cout<<"\nYOUR LOTTERY SELECTIONS ARE: \n"<<endl;
    Generate_Lottery_Tickets(number_of_balls, max_number, number_of_tickets);
    cout<<"\nGOOD LUCK"<<endl;
    return 0;
}

//*****************************************************
//* Function Name: Get_Num_Balls_From_User            *
//* Description: Prompting the user for the number of *
//*              lottery balls, ensuring in range     *
//* Parameter Description:                            *
//*   number_of_balls: reference to store user input  *
//* Date: 01/16/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************
void Get_Num_Balls_From_User(int &number_of_balls){
    do {
        cin>>number_of_balls;
        if (number_of_balls < MIN_BALLS || number_of_balls > MAX_BALLS){
            cout<<"\nThe number must be between 3 and 7: ";
        }
    } while (number_of_balls < MIN_BALLS || number_of_balls > MAX_BALLS);
}

//*****************************************************
//* Function Name: Get_Range_Num                      *
//* Description: Get the range of numbers from the    *
//*              user                                 *
//* Parameter Description:                            *
//*   max_number: refernce to store user input        *
//* Date: 01/16/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************
void Get_Range_Num(int &max_number){
    do{
        cin>>max_number;
        if(max_number < MIN_RANGE || max_number > MAX_RANGE){
            cout<<"\nThe number must be between 45 - 70: ";
        }
    } while (max_number < MIN_RANGE || max_number > MAX_RANGE);
}

//*****************************************************
//* Function Name: Get_Num_Tickets                    *
//* Description: Get the number of lottery balls from *
//*              user, ensuring in range              *
//* Parameter Description:                            *
//*   number_of_tickets : number of tickets to        *
//*                       generate                    *
//* Date: 01/16/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************
void Get_Num_Tickets(int &number_of_tickets){
    do{
        cin>>number_of_tickets;
        if(number_of_tickets < MIN_TICKETS || number_of_tickets > MAX_TICKETS){
            cout<<"\nThe number must be between 45 - 70: ";
        }
    } while (number_of_tickets < MIN_TICKETS || number_of_tickets > MAX_TICKETS);
}

//*****************************************************
//* Function Name: Generate_Lotter_Tickets            *
//* Description: Generate a list of suggested lottery *
//*              numbers using random generation      *
//* Parameter Description:                            *
//*   number_of_balls: number of balls per ticket     *
//*   max_number: Maximum range for random numbers    *
//*   number_of_tickets: Number of tickets to generate*
//* Date: 01/16/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************
void Generate_Lottery_Tickets(int number_of_balls , int max_number, int number_of_tickets){
    srand(static_cast<unsigned>(time(0))); //seed random number generator

    for (int i = 0; i < number_of_tickets; ++i){
        int used[MAX_BALLS] = {0};
        for (int j = 0; j < number_of_balls; ++j){
            int num;
            do {
                num = rand() % max_number + 1;
            } while (Is_Duplicate(num, used, j));

            used[j] = num;
            cout<<num<< " ";
        }
        cout<<endl;
    }

}

//*****************************************************
//* Function Name: Is_Duplicate                       *
//* Description: Checks if the number has already     *
//*              been selected                        *
//* Parameter Description:                            *
//*   number:                                         *
//*   used:
//*   size:                                           *
//* Date: 01/17/25                                    *
//* Author: Betty Phipps                              *
//*****************************************************
bool Is_Duplicate(int number, const int used[], int size){
    //checks if the generated number is unique for this ticket
    for (int i =0; i < size; ++i){
        if (used[i] == number){
            return true;
        }
    }
    return false;
}