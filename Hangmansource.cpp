#include <iostream>
#include <cstring>
#include <cctype>
void PlayGame();
bool WantToPlayAgain();
int GetSecretPhrase(char* phrase, int lenght);
const int IGNORECHARS = 256;
const char* ERRORMESSAGE = "Input error pls try again";
char* MakeHiddenPhrase(const char*secretPhrase, int secretphraselnght);
void DrawBoard(int numguessleft,const  char*noptrhiddenPhrase);
char GetCharacter(const char* prompt, const char* error);
char GetCharachter(const char* prompt, const char* error, const char validInput[], int validInputlenght);
char GetGuess();
void UpdateBoard(char guess,  char* hiddenphrase, char secretphrase[], int secretphraselength,int &numberofguessesleft);
char Guess;
bool IsGameOver(int numberofguessesleft, char* optrhiddenphrase, int secretphraselenght);
void DisplayResult(const char* secretPhrase, int numberofguessesleft);
bool failure;
int main() {
	do {
		PlayGame();

	} while (WantToPlayAgain());
}
bool WantToPlayAgain() {
	const char validinputs[] = { 'y','n' };
	char response = GetCharachter("Would you like to play again(y,n)", ERRORMESSAGE, validinputs, 2);
	return response == 'y';
}
void PlayGame() {
	const int MAX_LENGHT=256;
	const int MAX_NUMBEROFGUESSES = 6;
	char secretPhrase[MAX_LENGHT];
	char* noptrhiddenPhrase = nullptr;
	int numguessleft = MAX_NUMBEROFGUESSES;
	int secretphraselnght=GetSecretPhrase(secretPhrase, MAX_LENGHT);
	char GetCharacter(const char* prompt, const char* error);
	noptrhiddenPhrase = MakeHiddenPhrase(secretPhrase, secretphraselnght);
	DrawBoard(numguessleft, noptrhiddenPhrase);
	char guess;
	do {
		guess = GetGuess();
		UpdateBoard(guess, noptrhiddenPhrase, secretPhrase, secretphraselnght,numguessleft);
		DrawBoard(numguessleft, noptrhiddenPhrase);

	} while (!IsGameOver(numguessleft, noptrhiddenPhrase, secretphraselnght));
	DisplayResult(secretPhrase, numguessleft);
	delete[]noptrhiddenPhrase;
}

int GetSecretPhrase(char* phrase, int lenght) {
	int checklenght;
	do{
		failure = false;
		std::cout << "Please enter the secret phrase: " << std::endl;
		std::cin.get(phrase, lenght);
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORECHARS, '\n');
			std::cout << ERRORMESSAGE << std::endl;
			failure = true;

		}
		else {
			 checklenght = strlen(phrase);
			if (lenght == 0) {
				std::cout << "Please enter a word that's longer than 0" << std::endl;
				failure = true;
			}
		}

	} while (failure);
	return checklenght;

}

char* MakeHiddenPhrase(const char* secretPhrase, int secretphraselnght) {
	char* hiddenphrase = new char[secretphraselnght + 1];

	for (int i=0; i < secretphraselnght; i++) {
		if (secretPhrase[i] != ' ') {
			hiddenphrase[i] = '-';
		}
		else {
			hiddenphrase[i] = ' ';
		}
	}
	hiddenphrase[secretphraselnght] = '\0';
	return hiddenphrase;
}
char GetGuess() {
	return GetCharacter("Please input your guess: ", ERRORMESSAGE);
}
void DrawBoard(int numguessleft, const  char* optrhiddenPhrase) {
	switch (numguessleft) {
		case 0:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|  /|\\" << std::endl;
			std::cout << "|  / \\" << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;
		}
		break;
		case 1: {
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|  /|\\" << std::endl;
			std::cout << "|  / " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;


		}
		break;
		case 2:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|  /|\\" << std::endl;
			std::cout << "|  " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;
		}
		break;
		case 3:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|  /|" << std::endl;
			std::cout << "|  " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;
		}
		case 4:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|  " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;

		}
		break;
		case 5:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   O" << std::endl;
			std::cout << "|   " << std::endl;
			std::cout << "|  " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;
		}
		break;
		case 6:
		{
			std::cout << "+---+" << std::endl;
			std::cout << "|   |" << std::endl;
			std::cout << "|   " << std::endl;
			std::cout << "|   " << std::endl;
			std::cout << "|  " << std::endl;
			std::cout << "-+-" << std::endl<<std::endl;

		}
		break;
		default:
			break;

	}
	std::cout << "SecretPhrase is " << optrhiddenPhrase << std::endl;
}

void UpdateBoard(char guess,  char* hiddenphrase, char secretphrase[], int secretphraselength,int &numberofguessesleft) {
	bool found = false;
	for (int i = 0; i < secretphraselength; i++) {
		if (tolower(secretphrase[i]) == guess) {
			hiddenphrase[i] = secretphrase[i];
			found = true;
		}
	}
	if (!found) {
		numberofguessesleft--;
	}


}
bool IsGameOver(int numberofguessesleft, char* optrhiddenphrase, int secretphraselenght) {
	bool hasDash = false;
	for (int i = 0; i < secretphraselenght; i++) {
		if (optrhiddenphrase[i] == '-') {
			hasDash = true;
			break;

		}
	}
	return numberofguessesleft == 0 || !hasDash;
}
void DisplayResult(const char* secretPhrase, int numberofguessesleft) {
	if (numberofguessesleft > 0) {
		std::cout << "You got it word was " << secretPhrase << std::endl;

	}
	else {
		std::cout << "You didn't get it " << std::endl;
	}
}

/*
* Step 1
* Main
* -----
* do{
* PlayGame
* }while(WantToPlayAgain)
* Step 2
* PlayGame
* --------
* SecretPhrase=GetSecretPhrase()
* hiddenPhrase=MakeHiddenPhrase(secretphrase)
* numberofguessesleft=6
* DrawBoard(hiddenphrase)
* do{
* guess=GetGuess()
* wasAGoodGuess=UpdateBoard(guess,SecretPhrase,hiddenPhrase,numberofguessesLeft)
* DrawBoard(hiddenPhrase)

* }while(!Gameisover)
* DisplayResult(secretPhrase,numberofguessesLeft)
*  Step 3
* GetSecretPhrase
* ----------------
* prompt the user for the secret phrase
* get the secret phrase
* 
* return secret phrase
* MakeHiddenPhrase(secretPhrase)
* ------------------------------
* hiddenPhrase=make new cstring given the length of the secret
* for(length of the secret phrase)
* {
* hiddenPhrase[i]='-'
* 
* }
* return hiddenPhrase
* 
* UpdateBoard(guess,secretPhrase,hiddenPhrase,numberofGuessesLeft)
* -------------------------------------------------------------------
* bool found=false
* for(length of the secretPhrase)
* {
* if(
* 
* 
*/
