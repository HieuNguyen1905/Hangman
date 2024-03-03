#include<bits/stdc++.h>

using namespace std;

string change(string secretWord){
	string guessedWord;
	for(int i = 0; i < secretWord.size(); i++){
		 guessedWord += "_ ";
	}
	return guessedWord;
}

int ranNum(int max){
	return rand() % max + 1;
}

int main(){

	change
	string secretWord = "dcm";
	string guessedWord = change(secretWord);
	cout << guessedWord;
	return 0;
	
}
