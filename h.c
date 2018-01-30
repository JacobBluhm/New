#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "variables.h"
/* 
	I dette kryds og bolle kan man spille 2 og 2 og 1 mod computeren.
	Computerens træk er 100 procent tilfældige.
	desværre er C's random-function ret dårlig, så det er altid de samme
	tal den gennerer.

*/
int main()
{
	init();
	int m = menu();
	
		// run 2player code
		while(o < boardSize && finish == false){	
		printGameboard();
		if(m == true){	
		scanf("%d", &move);
		}
		else{
			if(o % 2 == 0)	
				scanf("%d", &move);
			else
				move = rand() % 9;
		}
		move--;
		valid = validate(move);
		if(valid == true){
			if(o % 2 == 0){
				gameBoard[move] = 'X';
			}
			else
		 		gameBoard[move] = 'O';
		o++;
		
		
		}
		else if(valid == false)
			printf("Invalid move\n");
		finish = win();
	
		}	
		printGameboard();		
}

void init(){
//init the gameboard values

	for(int i = 0; i  < boardSize; i++){
	
		gameBoard[i] = '_';
		
	}		
}
void printGameboard()	{
// Prints the game board
	
	if(o % 2 == 0)
		printf("X, enter a number(1/9):\n");
	else
		
		printf("O, enter a number(1/9):\n");	
	    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", gameBoard[0], gameBoard[1], gameBoard[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", gameBoard[3], gameBoard[4], gameBoard[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", gameBoard[6], gameBoard[7], gameBoard[8]);

    printf("     |     |     \n\n");
		printf("\n");	
		
	if(finish == true){
		if(o % 2 == 0)
			printf("O won!\n");
		else
			printf("X won!\n");
	}
		

}
bool validate(int x)	{
	return gameBoard[move] == '_'; 
}
bool win()	{
	//	Vandret
	check1 = (gameBoard[0] + gameBoard[1] + gameBoard[2]);
	check2 = (gameBoard[3] + gameBoard[4] + gameBoard[5]);
	check3 = (gameBoard[6] + gameBoard[7] + gameBoard[8]);
	//	Lodret
	
	check4 = (gameBoard[0] + gameBoard[3] + gameBoard[6]);
	check5 = (gameBoard[1] + gameBoard[4] + gameBoard[7]);
	check6 = (gameBoard[2] + gameBoard[5] + gameBoard[8]);
	
	// Kryds
	check7 = (gameBoard[0] + gameBoard[4] + gameBoard[8]);
	check8 = (gameBoard[2] + gameBoard[4] + gameBoard[6]);
	
		
	if(  (check1 == 264 || check1 == 237)|| (check2 == 264 || check2 == 237)||
		 (check3 == 264 || check3 == 237)|| (check4 == 264 || check4 == 237)||
		 (check5 == 264 || check5 == 237)|| (check6 == 264 || check6 == 237)||
		 (check7 == 264 || check7 == 237)|| (check8 == 264 || check8 == 237)) {
		
	   	return true;
	   }
	return false;
}
bool menu(){
	printf("Press 0 for 2 player\n");
	printf("Press 1 for vs. computer\n");
	scanf("%d", &valg);

	return valg == 0;
}
