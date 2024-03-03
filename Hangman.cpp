#include<bits/stdc++.h>
using namespace std;

int ranNum(int max){
	return rand() % max + 1;
}

string chooseWord(int MAX){
	int ranNumber = ranNum(MAX);
	ifstream in;
	in.open("hangman.txt");
	string secretWord;
	for(int i = 1; i <= 100; i++){
		in >> secretWord;
		if(i == ranNumber) return secretWord;
	}
}

bool contains(const string secretWord, char guess){
	for(int i = 0; i < secretWord.size(); i++){
		if(guess == secretWord[i]) return true;
	}
	return false;
}
string change(const string secretWord){
	string guessedWord, guessedWord2;
	for(int i = 0; i < secretWord.size(); i++){
		 guessedWord += "_";
	} 
	return guessedWord;
}
string changeUpdate(const string secretWord){
	string guessedWord2;
	for(int i = 0; i < secretWord.size(); i++){
		guessedWord2 += "_ ";
	}
	return guessedWord2;
}
//void renderGame(string guessedWord, int badGuessCount)
//{
//	cout << FIGURE[badGuessCount] << endl;
//	cout << guessedWord << endl;
//	cout << "Number of wrong guesses: " << badGuessCount << endl;
//}

void lockWord(int size){
	if(size == 0) return;
	else cout << "_ ";
	return lockWord(size - 1);
}
//char readAGuess(char guess){
//	char guessed = guess + " ";
//	return guessed;
//}

void upDate(const string secretWord, string &guessedWord, char guess, string &guessedWord2){
	int j = 0;
	for(int i = 0; i < secretWord.size(); i++){
		if(secretWord[i] == guess) {
			guessedWord[i] = guess;
			guessedWord2[j] = guess;
		}
		j += 2;
	}
	cout << guessedWord2;
}

string update2(const string secretWord, string &guessedWord2, char guess){
}

void punish(int badGuessCount, string &guessedWord, const string secretWord, string &guessedWord2){
				switch (badGuessCount){
				case 1: {
					cout << "                         Dit\n";
					cout << guessedWord2 << endl; 
					break;
				}	
				case 2: {
					cout << "                         con\n";
					cout << guessedWord2 << endl;
					break;
				}
				case 3: {
					cout << "                         me\n";
					cout << guessedWord2 << endl;
					break;
				}
				case 4: {
					cout << "                         may\n";
					cout << guessedWord2 << endl;
					break;
				}
				case 5: {
					cout << "                         ngu\n";
					cout << guessedWord2 << endl;
					break;
				}
				case 6: {
					cout << "                         vl\n";
					cout << guessedWord2 << endl;
					break;
				}
				case 7: {
					guessedWord = secretWord;
					break;
				}				
			}
}

void playGame(){
do{
	srand(time(0));
	const int MAX = 100;
	string secretWord = chooseWord(MAX);
	string guessedWord = change(secretWord);
	string guessedWord2 = changeUpdate(secretWord);
	cout << endl;
	lockWord(secretWord.size());
	int badGuessCount = 0;
	cout << endl;
	do
	{
		cout << "Your guessed word is: ";
		char guess; cin >> guess;
//		char guessed = readAGuess;
		if(contains(secretWord, guess) == true){
				upDate(secretWord, guessedWord, guess, guessedWord2);
			}
		else {
			badGuessCount++;
			punish(badGuessCount,guessedWord,secretWord,guessedWord2);
		}
		
		
	} while(secretWord != guessedWord);
	if(secretWord == guessedWord && badGuessCount < 7) {
		cout << "Congratulations! You win!\n";
		cout << endl;
	}
	if(secretWord == guessedWord && badGuessCount >= 7) {
		cout << "\nYou are lose!\n" << "\nThe secretword is " << secretWord << endl;
		cout << "\nReplay?\n" << "\nYes or No (y/n)\n";
		char a; cin >> a; if(a == 'n') break;
	}
}while(true);
	return;
	
}
int main(){
	playGame();
}
