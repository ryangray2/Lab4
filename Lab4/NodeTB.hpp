/*
 * NodeTB.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */

#ifndef NodeTB_HPP
#define NodeTB_HPP
#include "Game.hpp"
#include "BSTB.hpp"
#include <string>
#include <iostream>

class Game;

using namespace std;

class NodeTB {
	friend class Game;
	friend class BSTB;
	string data;
	NodeTB *right;
	NodeTB *left;
public:
	NodeTB(string k);
	~NodeTB();
	string getData();
};

#endif /* NodeTB_HPP */
