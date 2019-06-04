#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Forward declare all functions.
void printBoard(int board[], int playerA, int playerB);
int requestValidInput(int board[], int playerA, int playerB);
int checkForWinner(int board[], int playerA, int playerB);
bool checkForDraw(int board[]);




int main()
{
    // Initialize game board and player integers.
    int gameBoard[9] = {1,2,3,4,5,6,7,8,9};
    int plyrA, plyrB, gameWinner;
    int plyrInput;
    bool gameOver = false;
    plyrA = 10; 
    plyrB = 11;
    
    while (!gameOver){
        
    // Display board.
    printf("The current state of the Tic-tac-toe Board:\n");
    printf("\n");
    
    printBoard(gameBoard, plyrA, plyrB);
    
    // Determine current player.
    if (plyrA%2 == 0){
        printf("It is player A's turn.\n");
     } else {
        printf("It is player B's turn.\n");
        }
    printf("Please enter a valid position to play.\n");
    
    // Receive user input.
    plyrInput = requestValidInput(gameBoard, plyrA, plyrB);
    
    if (plyrA % 2 == 0){
        gameBoard[plyrInput] = 65;
    } else {
        gameBoard[plyrInput] = 66;
    } 
    
    // Check for winner of game.
    gameWinner = checkForWinner(gameBoard, plyrA, plyrB);
    
    // Determine winner or draw.
    if(gameWinner == plyrA){
        printf("Player A wins!\n");
        printBoard(gameBoard, plyrA, plyrB);
        gameOver = true;
    } else if(gameWinner == plyrB){
        printf("Player B wins!\n");
        printBoard(gameBoard, plyrA, plyrB);
        gameOver = true;
    } else if(gameWinner == 0){
        gameOver = checkForDraw(gameBoard);
        if(gameOver == true){
            printf("It's a draw!\n");
            printBoard(gameBoard, plyrA, plyrB);
        } else {
            gameOver = false;
        }
    }
    
    plyrA--;
    }
    
    return 0;
    }
    

// Function to print current state of board.
void printBoard(int board[], int playerA, int playerB){
    int i, count;
    
    count = 0;
    
    
    printf("\n");
    
    for(i=0; i<9; i++){
        if(board[i] == 'A' || board[i] == 'B'){
            printf(" %c ", board[i]);
            count++;
        } else {
            printf(" %d ", board[i]);
            count++;
        } if(count == 3){
            printf("\n");
            count = 0;
        }
    }
    
    printf("\n");
    
    return ;
}

// Function to receive valid user input.
int requestValidInput(int board[], int playerA, int playerB){
    int userInput;
    
    do {
        scanf("%d", &userInput);
        if(userInput < 1 || userInput > 9){
            printf("Invalid input, please try again.\n");
        } else if(board[userInput -1] == 'A' || board[userInput -1] == 'B'){
            printf("That position has already been played, please try again.\n");
        } 
    } while (userInput < 1 || userInput > 9 || board[userInput -1] == 65 || board[userInput -1] == 66);
        
    
    return userInput - 1;
}

// Function to check for winner of game.
int checkForWinner(int board[], int playerA, int playerB){ // use 2 if/else statements coded w/ letter, return plyrA, return plyrB
    if(board[0]==65 && board[1]==65 && board[2]==65){
        return playerA;
    } else if(board[3]==65 && board[4]==65 && board[5]==65){
        return playerA;
    } else if(board[6]==65 && board[7]==65 && board[8]==65){
        return playerA;
    } else if(board[0]==65 && board[3]==65 && board[6]==65){
        return playerA;
    } else if(board[1]==65 && board[4]==65 && board[7]==65){
        return playerA;
    } else if(board[2]==65 && board[5]==65 && board[8]==65){
        return playerA;
    } else if(board[0]==65 && board[4]==65 && board[8]==65){
        return playerA;
    } else if(board[2]==65 && board[4]==65 && board[6]==65){
        return playerA;
    } else if(board[0]==66 && board[1]==66 && board[2]==66){
        return playerB;
    } else if(board[3]==66 && board[4]==66 && board[5]==66){
        return playerB;
    } else if(board[6]==66 && board[7]==66 && board[8]==66){
        return playerB;
    } else if(board[0]==66 && board[3]==66 && board[6]==66){
        return playerB;
    } else if(board[1]==66 && board[4]==66 && board[7]==66){
        return playerB;
    } else if(board[2]==66 && board[5]==66 && board[8]==66){
        return playerB;
    } else if(board[0]==66 && board[4]==66 && board[8]==66){
        return playerB;
    } else if(board[2]==66 && board[4]==66 && board[6]==66){
        return playerB;
    } else {
        return 0;
    }
}

// Function to check for draw. 
bool checkForDraw(int board[]){
    int i;
    for(i=0; i<9; i++){
        if(board[i] != 65 && board[i] != 66){
            return false;
        } 
    }
    
    return true;
}