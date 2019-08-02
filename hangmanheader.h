#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h> //main & modu

//prototypes
void displayRules(); /*prototype*/
bool wincondtion(int secretletters, int lifes), correctAnswer(int count, int repeatingletters), correctformat(char* letter);  /*prototype*/
int repeatingcondition(int lifes, int repeatingletters), lenghtstring(char word[20]); /*prototype*/


char abecedario[60] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


/*function to get the lenght of the word*/
int lenghtstring(char word[20])
{
	int letters=0;
	while (word[letters]!='\0') letters++;
	return letters;
}

/* function to verify if it is the correct format*/
bool correctformat(char* letter){
	/*strlen is used to get the len of the string*/
	int i, counter = 0, a = strlen(letter);
	/*condition to verify if it is only one letter*/
	if (a != 1){
		return false;
	}
	else{
		/*condition to verify if it is in the abecedario*/
		for (i=0;i<=52;i++){
			if(letter[0] == abecedario[i]){
				//we use a counter, because if the letter is in the abecedario, the counter will detect it.
				counter++;
			}
		}
		//This counter will tell us if the letter of the user was in the abecedario
		if (counter > 0){
			return true;
		}
		else{
			return false;
		}
	}
	
	
}
//function to verify if the answer is correct
bool correctAnswer(int count, int repeatingletters){
	
	if ((count>0) && (repeatingletters == 0)){
		return true;
		
	}		
	//secretletters is the counter to check if we have guest all the letters
		
}

//function to verify if the user is repeating letters
repeatingcondition(int lifes, int repeatingletters){
	if (repeatingletters==0){
	
		printf("\nWrong! try it again \n");
		//life is to check if we have lost or not
		return lifes - 1;
	}
	else{
		printf("\nYou've already used this letter previously \n");
		return lifes - 1;
	
	}
}

//function to verify if the user has won
wincondition(int secretletters, int lifes){
	//condtion to check if the user has won
		if (secretletters == 0){
			printf("Congratulations! You have won!!");
			return true;
			
		}
		else{
			//condition to check if the user has lost the game
			if(lifes == 0){
				printf("Sorry, you have lost :(");
				return true;
			}
			//condition to check if the game has not finished
			else{
				return false;
			}
		}
}

//function to display the rules
void displayRules(){

	printf("Welcome to the hangman_game!! \n");
	printf("These are the rules for the game: \n");
	printf("1. The purpose of this game is to enter a letter, trying to match with a letter of the secretword \n");
	printf("2. You win until you have matched all the letter of the secretword \n");
	printf("3. You lost if you lose your lifes \n");
	printf("4. You have 5 lifes, and you lose one life if you don't match the letter \n");
	printf("5. If you have matched a letter and you repeat this letter, you will lose a life \n");
	printf("6. You cannot enter nothing unless it is in the alphabet \n");
	printf("7. The word does not have capital letter, if you input one, you will lose a life \n");
	printf("8. Input only one letter, if you input more than one, you will lose a life \n \n");
	
	printf("Enojoy the game! \nPress any key to continue");
	
	getch();
	
	system("cls");
	
}
