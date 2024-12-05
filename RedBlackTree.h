#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_DOUBLE_BLACK 2
#include <string>
#include <iostream>
using namespace std;

struct RBTNode{
    int key;
    unsigned short int color;
    
    RBTNode* left = nullptr;
    RBTNode* right = nullptr;
    RBTNode* parent = nullptr;
    
};
class RedBlackTree{
    public:
        RedBlackTree();
        RedBlackTree(const RedBlackTree &tree);
        RBTNode* copypaste(RBTNode oldroot, RBTNode newroot);
        void Insert(int key);
        bool Contains(int key);
        int GetMin() const;
        int GetMax() const;
        int Size() const;
        string ToInfixString() const {return ToInfixString(root);};
        string ToPrefixString() const { return ToPrefixString(root);};
        string ToPostfixString() const { return ToPostfixString(root);};
        void Remove(int data);
        
        //~RedBlackTree();
        RBTNode* root;
         RBTNode* GetSibling(RBTNode* node);
         RBTNode* InOrderSuccessor(RBTNode* node);
        RBTNode* GetReplacement(RBTNode* node);
        RBTNode* FindNode(int key);
        
    private:

        
        unsigned long long int numItems = 0;
        void rightRotate(RBTNode* node);
        void leftRotate(RBTNode* node);
        void FixTree(RBTNode* node);
        void FixDoubleBlack(RBTNode* node);
        string ToInfixString(RBTNode* node) const;
        string ToPrefixString(RBTNode* node) const;
        string ToPostfixString(RBTNode* node) const;
        RBTNode* copying(RBTNode* node, RBTNode* parentnode);
        
       
        



};
#endif
