/*
 * NodeTB.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: ryangray
 */

#include "NodeTB.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

NodeTB::NodeTB(string k) {
	data = k;
	right = NULL;
	left = NULL;
} // NodeTB

NodeTB::~NodeTB() {
	delete left;
	delete right;
} // ~NodeTB

string NodeTB::getData() {
	return data;
}


