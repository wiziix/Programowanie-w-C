#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum Move { 
    ROCK = 1, 
    PAPER = 2, 
    SCISSORS = 3
};

int getRandomMove() {
    return (rand() % (3 - 1 + 1)) + 1;
}

int main()
{
    enum Move userInput = 0;
    int roundCounter = 0, computerInput = 0, computerPoint = 0, userPoint = 0;
    char * scores[100][2];
    srand(time(NULL));

    printf(" ###### Welcome to Rock Paper Scissors Game ######\n");
    printf(" ### Rules: \n"
        " ### Press 1 for Rock \n" 
        " ### Press 2 for Paper \n"
        " ### Press 3 for Scissors \n"
        " ### Press 4 to View Score\n"
        " ### First one to reach 3 points will win. \n");

    while (computerPoint < 3 && userPoint < 3) {
        
        printf("Input your move : ");
        scanf("%d", &userInput);
        
        computerInput = getRandomMove();

        switch (userInput) {
        case ROCK:
            if (computerInput == PAPER) {
                printf("You picked Rock. Computer picked paper. Computer got 1 point(s).\n");
                computerPoint++;
                scores[roundCounter][0] = "lost";
                scores[roundCounter][1] = "rock";
            }
            else if (computerInput == SCISSORS) {
                printf("You picked rock. Computer picked scissors. You got 1 point(s).\n");
                userPoint++;
                scores[roundCounter][0] = "won";
                scores[roundCounter][1] = "rock";
            }
            else {
                printf("It's draw.\n");
                scores[roundCounter][0] = "drawn";
                scores[roundCounter][1] = "rock";
            }
            break;

        case PAPER:
            if (computerInput == ROCK) {
                printf("You picked paper. Computer picked Rock. You got 1 point(s).\n");
                userPoint++;
                scores[roundCounter][0] = "won";
                scores[roundCounter][1] = "paper";
            }
            else if (computerInput == SCISSORS) {
                printf("You picked paper. Computer picked scissors. Computer got 1 point(s).\n");
                computerPoint++;
                scores[roundCounter][0] = "lost";
                scores[roundCounter][1] = "paper";
            }
            else {
                printf("It's draw.\n");
                scores[roundCounter][0] = "drawn";
                scores[roundCounter][1] = "paper";
            }
            break;

        case SCISSORS:
            if (computerInput == ROCK) {
                printf("You picked Scissors. Computer picked Rock. Computer got 1 point(s).\n");
                computerPoint++;
                scores[roundCounter][0] = "lost";
                scores[roundCounter][1] = "scissors";
            }
            else if (computerInput == PAPER) {
                printf("You picked Scissors. Computer picked Paper. You got 1 point(s).\n");
                userPoint++;
                scores[roundCounter][0] = "won";
                scores[roundCounter][1] = "scissors";
            }
            else {
                printf("It's draw.\n");
                scores[roundCounter][0] = "drawn";
                scores[roundCounter][1] = "scissors";
            }
            break;

        case 4:
            printf("You've gotten %d points and the Computer has gotten %d points.\n", userPoint, computerPoint);
            printf("\n");

            for (int i = 0; i < roundCounter; i++) {
                printf("Round %d. You had played %s and you %s.\n", i+1, scores[i][1], scores[i][0]);
            }
            continue;

        default:
            break;

        }

        if (computerPoint == 3 || userPoint == 3)
        {
            printf("You got %d points and the Computer got %d points\n", userPoint, computerPoint);

            if (computerPoint == 3)
            {
                printf("You lost\n");
            }
            else
            {
                printf("You won!\n");
            }
        }

        roundCounter ++;
    }


}


