#ifndef BSTB_HPP
#define BSTB_HPP
#include "Game.hpp"
#include "NodeTB.hpp"
#include <string>
#include <iostream>
using namespace std;

class NodeTB;

class BSTB {
	friend class Game;
	friend class NodeTB;
	NodeTB *root;
	int count;
public:
	BSTB(); // done
	~BSTB(); // done
	NodeTB *insert(string x, NodeTB *n); // done
	void printTreeio(NodeTB *n); // done
	void printTreePre(NodeTB *n); // done
	void printTreePost(NodeTB *n); // done
	bool search(NodeTB *n, string x); // done
	int treeHeight(NodeTB *n); // done
	int nodeAVLValue(NodeTB *n); // done
	void adjustBalances(NodeTB *n); // done
	NodeTB *rotateRight(NodeTB *n); // done
	NodeTB *rotateLeft(NodeTB *n); // done
	int getScore(NodeTB *n, BSTB *dict);
};

#endif /* BSTB_HPP */
