// Code by Cevat Sonmez Yucel
#ifndef AVLTREE_H
#define AVLTREE_H
#include "AVLNode.h"
#include <string>
#include <vector>

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int time, std::string activity);
    void remove(int time);
    std::string find(int time);
    void printTree();
    std::vector<std::string> returnSchedule();

private:
    AVLNode* insert(AVLNode* root, int time, std::string activity);
    AVLNode* remove(AVLNode* root, int time);
    AVLNode* find(AVLNode* root, int time);
    std::vector<std::string> returnSchedule(AVLNode* root, std::vector<std::string> schedule);
    void balance();
    int height(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* root);
    AVLNode* rotateRight(AVLNode* root);
    AVLNode* root;
    AVLNode* lowestUnbalanced;
};

#endif