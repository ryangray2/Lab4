/*
 * Game.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "Game.hpp"

using namespace std;

Game::Game() {
	int numletters = 0;
	int totalwords = 0;
	int numright = 0;
	int totalscore = 0;
}

void Game::startGame() {
	string again = "yes";
	int highScore = 0;
	while (again == "yes" || again == "Yes") {
		cout << "How many letters would you like?" << endl;
		cin >> numletters;
		currletters = getLetters();
		getWords();
		checkWordsForScore();
		cout << "Score: " << totalscore;
		if (totalscore > highScore) {
			cout << "New High Score!" << endl;
			highScore = totalscore;
		}
		cout << "Play again? (yes or no): ";
		cin >> again;
	}
}

void Game::readTreeFromFile(string dictfile) {
	dict = new BSTB ();
	ifstream file(dictfile.c_str());
	string word;
	while (!file.eof()) {
		file >> word;
		if (!file.eof()) {
			dict->insert(word, dict->root);
		}
	}
	return;
}


char * Game::getLetters() {
	srand(time(NULL));
	int numvowels = (rand() % numletters) + 1;
	int numconsonants = numletters - numvowels;
	char vowels[] = "aeiou";
	char consonants[] = "bcdfghjklmnpqrstvwxyz";
	char letters[numletters];
	int x = numletters;
	while (numvowels > 0) {
		letters[x] = vowels[rand() % 5];
		x--;
		numvowels--;
	}
	while (numconsonants > 0) {
		letters[x] = consonants[rand() % 21];
		x--;
		numconsonants--;
	}
	return letters;
}

bool Game::checkWLetters(string s) {
	// returns true if s contains only valid letters
	int marker = 0;
	for (int i = s.size(); i > 0; i++) {
		for (int j = numletters; j > 0; j++) {
			if (s[i] == currletters[j]) {
				marker++;
			}
		}
	}
	if (marker == s.size()) {
		return true;
	}
	else {
		return false;
	}
}


void Game::getWords() {
	string s;
	while (s != "*") {
		cout << "Enter word: " << endl;
		cin >> s;
		if (checkWLetters(s) == false) {
			cout << "Invalid word" << endl;
		}
		else {
			wordlist->insert(s, wordlist->root);
			totalwords++;
		}
	}
	cout << "Done." << endl;
}

void Game::checkWordsForScore() {
	// gets count of number of words typed in that are in the dictionary; counts total score
	int x = wordlist->getScore(wordlist->root, dict);
	numright = x;
	int score = x * 3;
	int penalty = (totalwords - score) * -1;
	score += penalty;
	totalscore = score;
}








