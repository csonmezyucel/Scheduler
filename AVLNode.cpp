// Code by Cevat Sonmez Yucel
#include <string>
#include <iostream>
#include "AVLNode.h"

//Constructor
AVLNode::AVLNode(int t, std::string a) {
    time = t;
    activity = a;
    left = NULL;
    right = NULL;
}

//Destructor
AVLNode::~AVLNode() {
    delete left;
    delete right;
}