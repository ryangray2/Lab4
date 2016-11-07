/*
 * BSTB.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */

#include <iostream>
#include <stdlib.h>
#include "BSTB.hpp"
#include "Game.hpp"
#include "NodeTB.hpp"
#include <string>
using namespace std;

BSTB::BSTB() {
	root = NULL;
	count = 0;
}

BSTB::~BSTB() {
	delete root;
}

int BSTB::treeHeight(NodeTB *n) {
	int height = 0;
	if (n != NULL) {
		int leftHeight = treeHeight(n->left);
		int rightHeight = treeHeight(n->right);
		int tallest = max(leftHeight, rightHeight);
		height = tallest + 1;
	}
	return height;
}

int BSTB::nodeAVLValue(NodeTB *n) {
	int leftHeight = treeHeight(n->left);
	int rightHeight = treeHeight(n->right);
	int result = leftHeight - rightHeight;
	return result;
}

NodeTB *BSTB::rotateRight(NodeTB *n) {
	NodeTB *temp;
	temp = n->left;
	n->left = temp->right;
	temp->right = n;
	return temp;
}

NodeTB *BSTB::rotateLeft(NodeTB *n) {
	NodeTB *temp;
	temp = n->right;
	n->right = temp->left;
	temp->left = n;
	return temp;
}

void BSTB::adjustBalances(NodeTB *n) {
	int x = nodeAVLValue(n);
	if (x > 1) {
		if (nodeAVLValue(n->left) > 0) {
			n = rotateRight(n);
		}
		else {
			NodeTB *temp;
			temp = n->right;
			n->right = rotateLeft(temp);
			n = rotateRight(n);
		}
	}
	else if (x < -1) {
		if (nodeAVLValue(n->right) <= 0) {
			n = rotateRight(n);
		}
		else {
			NodeTB *temp;
			temp = n->left;
			n->left = rotateRight(temp);
			n = rotateLeft(n);
		}
	}
}

// n is root
NodeTB *BSTB::insert(string s, NodeTB *n) {
	if (n == NULL) {
		root = new NodeTB(s);
		return n;
	}
	else if (s.compare(n->data) == -1) {
		n->left = insert(s, n->left);
		adjustBalances(n);
	}
	else if (s.compare(n->data) == 1) {
		n->right = insert(s, n->right);
		adjustBalances(n);
	}
	else if (s.compare(n->data) == 0) {
		return n;
	}
	count++;
	return n;
}

void BSTB::printTreeio(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	printTreeio(n->left);
	cout << n->data << " ";
	printTreeio(n->right);
}

void BSTB::printTreePre(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	cout << n->data << " ";
	printTreePre(n->left);
	printTreePre(n->right);
}

void BSTB::printTreePost(NodeTB *n) {
	if (n == NULL) {
		return;
	}
	printTreePost(n->left);
	printTreePost(n->right);
	cout << n->data << " ";
}

bool BSTB::search(NodeTB *n, string x) {
	if (n == NULL) {
		return false;
	}
	else {
		if (x.compare(n->data) == -1) {
			search(n->left, x);
		}
		else if (x.compare(n->data) == 1) {
			search(n->right, x);
		}
		else {
			return true;
		}
	}
}

int BSTB::getScore(NodeTB *n, BSTB *dict) {
	// traverse through n
	// for each node, dict.search(dict->root, dict->data)
	// if true, count++
	int count = 0;
	if (n == NULL) {
		return count;
	}
	getScore(n->left, dict);
	if (dict->search(dict->root, n->data) == true) {
		count++;
	}
	getScore(n->right, dict);
}







