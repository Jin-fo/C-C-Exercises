/* Jin Yuan Chen, ID: 115702978 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define Max 32
/*
Devise an interactive C program to play the hangman game. The word to be guessed is stored in 
a string (1 D array of characters), which is read from an input file. The player must guess the word. 
The program terminates when either all letters have been correctly guessed (the player wins), or 
when a specified number of incorrect guesses have been made (the computer wins). The 
maximum number of incorrect guesses is read from the keyboard.   
*/

int main() {

	FILE *inp;
	int i, live, check_corr = 0, check_wrog = 0;
	char word[Max], corr[Max], ler;
	
	inp = fopen("input_file.txt", "r");
	
	fscanf(inp, "%s", word); 
	
	for (i = 0; i < strlen(word); i++) { //building the blank correct guess word array
	    corr[i] = '*';
	}
	corr[i] = '\0'; 
	
	printf("[>]how many lives: "); 
	/*
	discussion: live, in this case has no limit, can be > 26 to go beyond just character letters(a -> z), 
	i.e. guess the password; otherwise pick a fair live <= 26 for just character letters
	*/
	scanf("%d", &live); getchar(); //get live
	char wrog[live]; //size fixed by live, i.e array size is live
	
	for (i = 0; i < sizeof(wrog); i++) { //building the blank wrong guess array
	    wrog[i] = '*';
	}
	wrog[i] = '\0';
	
	while(live > 0) {
		printf("---------------(live-%d)---------------\n", live);
    	printf("[o]the word is \"%s\"\n", corr);
	    printf("[>]guess a character in the word: ");
	    scanf("%c", &ler); getchar();  // get ler
	
		for (i = 0; i< strlen(word); i++) { //check each index-i letter of word if it be equal ler
	    	if (word[i] == ler) {
	            corr[i] = ler;  //set the index-i of the blank correct guess array to ler
	            check_corr = 1; //condition of ler being a letter in the word = True
	        } 
	    } 
	    
	    for (i = 0; i < strlen(wrog); i++) { //check each index-i letter of wrong geuess array if it be equal ler
	        if (wrog[i] == ler) { 
				check_wrog = 1; //condition of ler being a letter in the wrong guess = True
	        } 
	    } 
		
	    if (check_corr == 1) { //option(1,0) if ler is a correct guess(letter in word) *option(1,1) is never true, ler cant be a correct if it already in wrong guess array
			printf("[!]correct, the character \"%c\" is in the word\n", ler);
			check_corr = 0;

	    } else if(check_wrog == 1) { //option(0,1) if ler not a correct guess and is already in wrong guess array
			printf("[?]you already guess character %c\n", ler); 
			check_wrog = 0;
			
	    } else { //option: (0,0) if ler is not a correct guess(letter not in word) and not in wrong guess array
			wrog[sizeof(wrog)-live] = ler; //set the a blank index-i(left to right) of the wrong guess array to ler 
			printf("[!]incorrect, the character \"%s\" is NOT in the word\n", wrog);
			live--;
	    } 
	    
	    if (strcmp(word,corr) == 0) { //if correct guess array is the same by index of character with word array
	    	printf("[!!!]you win, the word is \"%s\"", word);
	    	break;
		} 
	}
	
	if (live == 0) { //after while break, check if live = 0; 
		printf("---------------(live-%d)---------------\n", live);
		printf("[???]you lose, the word is \"%s\"", word);
	}

}

