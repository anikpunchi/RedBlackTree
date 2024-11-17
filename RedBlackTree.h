#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#define COLOR_BLACK 0
#define COLOR_RED 1
#include <string>
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
        RedBlackTree(const RedBlackTree&);
        RBTNode* copypaste(RBTNode oldroot, RBTNode newroot);
        void Insert(int key);
        bool Contains(int key);
        int GetMin() const;
        int GetMax() const;
        int Size() const;
        string ToInfixString() const {return ToInfixString(root);};
        string ToPrefixString() const { return ToPrefixString(root);};
        string ToPostfixString() const { return ToPostfixString(root);};
    private:
        RBTNode* root;
        unsigned long long int numItems = 0;
        void rightRotate(RBTNode* node);
        void leftRotate(RBTNode* node);
        void FixTree(RBTNode* node);
        string ToInfixString(RBTNode* node) const;
        string ToPrefixString(RBTNode* node) const;
        string ToPostfixString(RBTNode* node) const;



};
#endif
