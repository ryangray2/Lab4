/*
 * main.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Game.hpp"
#include "BSTB.hpp"
#include "NodeTB.hpp"
using namespace std;

int main() {
	Game * x = new Game();
	x->readTreeFromFile("testdict.txt");
	x->startGame();
}


