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
	numletters = 0;
	totalwords = 0;
	numright = 0;
	totalscore = 0;
}

void Game::startGame() {
	string again = "yes";
	int highScore = 0;
	while (again == "yes" || again == "Yes") {
		cout << "How many letters would you like?" << endl;
		cin >> numletters;
		currletters = getLetters();
		for (int i = 0; i < numletters; i++) {
			cout << currletters[i] << " ";
		}
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
	char v[] = {'a','e','i','o','u'};
	char c[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
//	char letters[numletters];
	int x = numletters;
	while (numvowels >= 0) {
		currletters[x] = v[rand() % 5];
		x--;
		numvowels--;
	}
	while (numconsonants > 0) {
		currletters[x] = c[rand() % 21];
		x--;
		numconsonants--;
	}
	return currletters;
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
	cout << "oh god";
	while (1) {
		cout << endl << "Enter word: " << endl;
		string s = " ";
		cin >> s;
		cout << "wtf";
		if (s.compare("*") == 0) {
			cout << "damn";
			break;
		}
		else if (checkWLetters(s) == false) {
			cout << "1";
			cout << "Invalid word" << endl;
			continue;
		}
		else {
			cout << "2";
			wordlist->insert(s, wordlist->root);
			totalwords++;
			continue;
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








