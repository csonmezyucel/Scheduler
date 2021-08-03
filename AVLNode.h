// Code by Cevat Sonmez Yucel
#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>

class AVLNode {
public:
    AVLNode(int t, std::string a);
    ~AVLNode();
    int time;
    std::string activity;
    AVLNode* left;
    AVLNode* right;
};

#endif