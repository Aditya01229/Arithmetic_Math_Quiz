#include <stdio.h>                        // Standard Input - Output header file which holds all the basic impportant functions of C.
#include <stdlib.h>                       // Functions used from this header file - srand()
#include <time.h>                         // Functions used from this header file - clock_t, clock()
#include <unistd.h>                       // Functions used from this header file - getpid()
#include "basicfunc.c"                    // This source contains all the user-defined basic functions we used for making this program.
#include "operators/multiplication.c"     // This source contains all the user-defined functions required for multiplication operation.
#include "operators/division.c"           // This source contains all the user-defined functions required for division operation.
#include "operators/add.c"                // This source contains all the user-defined functions required for addition operation.
#include "operators/sub.c"                // This source contains all the user-defined functions required for substraction operation.
#include "operators/square.c"             // This source contains all the user-defined functions required for square operation.

int main()
{
    // Defined variables for correct answers, taking level and operator input, again doing operations, choice for tasks.
    int crt, lvl, optr, again, choice, sure;

    // Here we have used srand for seeding. By seeding the program generates different random number instead of the same number.
    srand(getpid());

    do
    {
        printf("\n\nWelcome to Arithmetic Adventure!\nWhat would you like to do?\n1) Play the quiz.\n2) Load recent leaderboard history.\n3) Delete Leaderboard History.\nInput:");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("This is a Maths quiz!\nHere you will be asked 10 questions according to operator and level you select!\nLet's check your results..\n\n");

            printf("Select the operator\n\n1\t-\tAddition\n2\t-\tSubstraction\n3\t-\tMultiplication\n4\t-\tDivision\n5\t-\tSquare\nInput: ");
            // Taking input for operator.
            scanf("%d", &optr);
            printf("\nSelect the level from 1, 2 and 3!\nInput: ");
            // Taking input for level.
            scanf("%d", &lvl);

            switch (optr)
            {
            case 1:
                crt = printadd(lvl);
                break;
            case 2:
                crt = printsub(lvl);
                break;
            case 3:
                crt = printmult(lvl);
                break;
            case 4:
                crt = printdiv(lvl);
                break;
            case 5:
                crt = printsquare(lvl);
                break;
            }
            break;

        case 2:
            printf("Which operator history You would like to see?\nInput:");
            printf("Select the operator\n\n1\t-\tAddition\n2\t-\tSubstraction\n3\t-\tMultiplication\n4\t-\tDivision\n5\t-\tSquare\nInput: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                addhistory();
                break;
            case 2:
                subhistory();
                break;
            case 3:
                multhistory();
                break;
            case 4:
                divhistory();
                break;
            case 5:
                squarehistory();
                break;

            default:
                break;
            }
            break;
        case 3:
            printf("\nAre you sure you want to delete the history?\n1 for Yes\n0 for No.\nInput: ");
            scanf("%d", &sure);
            if(sure == 1){
            addreset();
            subreset();
            multreset();
            divreset();
            squarereset();
            break;
            }
            else{
                printf("\nRedirecting to menu!");
                break;
            }

        default:
            printf("Enter a valid number!");
            break;
        }
        printf("\n\nDo you want to go to menu again?\nPress 1 for yes:\nand 0 for No:");
        scanf("%d", &again);
    } while (again == 1);
    printf("THANK YOU!");
    return 0;
}
