#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h> 
#include "hangmanheader.h"

int main(){
	// variable declaration
	char lista[49][30] = {{"awkward"},{"bagpipes"},{"banjo"},{"bungler"},{"croquet"},{"crypt"},{"dwarves"},{"fervid"},{"fishhook"},{"fjord"},{"gazebo"},{"gypsy"},{"haiku"},{"haphazard"},{"hyphen"},{"ivory"},{"jazzy"},{"jiffy"},{"jinx"},{"jukebox"},{"kayak"},{"kiosk"},{"klutz"},{"memento"},{"mystify"},{"numbskull"},{"ostracize"},{"oxygen"},{"pajama"},{"phlegm"},{"pixel"},{"polka"},{"quad"},{"quip"},{"rhythmic"},{"rogue"},{"sphinx"},{"squawk"},{"swivel"},{"toady"},{"twelfth"},{"unzip"},{"waxy"},{"wildebeest"},{"yacht"},{"zealous"},{"zigzag"},{"zippy"},{"zombie"}};
	int x, large, secretletters = 0, i, lifes = 5;
	char word[30], letter[100], repeatedletters[60];
	bool win = false, condition, wronganswer, guessCondition; 
	
	displayRules(); //self-explanatory
	
	// selects a random word every time the program is ran
	srand(time(NULL)); 
	x = rand() % 50;
	
   for (i = 0; lista[x][i] != '\0'; i++)
		
      word[i] = lista[x][i];
      
	large = lenghtstring(word);
	char secretword[large];
	
	for (i=0;i<large;i++)
	//the 'if' part is designed to handle multi-word entries (even tho they are not contained in the list provided)
		if (word[i] == ' '){ 
			secretword[i] = ' ';
		}
		else{
			secretword[i] = '*';
			secretletters++; //important variable in the future
		}
	
	printf("YOUR PROGRESS: %s", secretword);
	
	while (win == false){
		int repeatingletters = 0;
		printf("\t\tLife counter: %i \n", lifes);	
		printf("Input a letter: ");
		
		// asking for the letter, we use gets because it is a string
		gets(letter);
		
		// calling the function to check if the letter was input in the correct format
		condition = correctformat(letter);
		
		// verifying the format
		if(condition == false){
			printf("\nSomething is wrong in your format, try it again \n");
			lifes--;
		}
		else{
			int count = 0;
			//once we have verified the format, we check if there is a match between the letter input and every letter in the word we have to guess
			for (i=0;i<large;i++){
				//condition to check the match
				if(letter[0]==word[i]){
					secretword[i] = letter[0];
					if (secretword[i] == repeatedletters[i]){
					//condition that will tell us if the input letter match with one of the words that the user has input
					repeatingletters++;
					}
					else{
						//this is to make a string calling repeated letters that help us to know in the statement before, if a letter is repeated
						repeatedletters[i] = secretword[i];
						count++;
					}
				}	
			}	
			
			guessCondition = correctAnswer(count, repeatingletters);
			
			//condition to check if the user input a correct answer and if it is correct or not, make a rest or a sum
			guessCondition = correctAnswer(count, repeatingletters);
			if (guessCondition == true){
				//secretletters is the counter to check if we have guest all the letters
				printf("\nGreat! you have guest a letter \n");
				secretletters -= count;
			}
			else{
				//once we know the answer is incorrect, we check if it is because is a repeated letter or the user only failed
				lifes = repeatingcondition(lifes, repeatingletters);
			}
			
		}
		//cleaning the terminal
		printf("\n\n\n\n\n\n\nPress any key to continue");
		getch();
		system("cls");
		printf("YOUR PROGRESS: %s", secretword);

		//function to verify if the game has finished
		
		win = wincondition(secretletters, lifes);
		
	}
	return 0;
}

