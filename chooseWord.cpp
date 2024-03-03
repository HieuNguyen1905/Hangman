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
	for(int i = 0; i < 84; i++){
		in >> secretWord;
		if(i == ranNumber) return secretWord;
	}
}

int main(){
	srand(time(0));
	const int MAX = 100;
	string secretWord = chooseWord(MAX);
	cout << secretWord;
	return 0;
	
}
