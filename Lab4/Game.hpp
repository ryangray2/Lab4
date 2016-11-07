/*
 * Game.hpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */

#ifndef Game_HPP
#define Game_HPP
#include "BSTB.hpp"
#include "NodeTB.hpp"
#include <string>
#include <iostream>

class BSTB;

using namespace std;

class Game {
	friend class BSTB;
	friend class NodeTB;
	BSTB *dict;
	int numletters;
	char *currletters;
	int totalwords;
	BSTB *wordlist;
	int numright;
	int totalscore;
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile(string dictfile); // done
	char *getLetters(); // done
	void getWords(); // done
	bool checkWLetters(string s); // done
	void checkWordsForScore(); // done
};

#endif /* Game_HPP */
