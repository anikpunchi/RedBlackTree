#include <iostream>
#include "RedBlackTree.h"
#include <stdexcept>
#include <string>
using namespace std;

//https://www.programiz.com/dsa/red-black-tree this website gave me a nice walkthrough which i used to learn how right rotation and left rotation should be implemented

RedBlackTree::RedBlackTree(){
    root = nullptr;
}
RedBlackTree::RedBlackTree(const RedBlackTree &tree){
    if (tree.root == nullptr){
        root = nullptr;
        numItems = 0;
        return;
    }
    root = copying(tree.root, nullptr);
    numItems = tree.numItems;
    

}
RedBlackTree::~RedBlackTree(){
    deconstructor_helper(root);
}
void RedBlackTree::deconstructor_helper(RBTNode* node){
    if (node == nullptr){
        return;
    }
    deconstructor_helper(node->left);
    deconstructor_helper(node->right);
    delete node;
   
}
RBTNode* RedBlackTree::copying(RBTNode* node, RBTNode* parentnode){
    if (node == nullptr){
        return  nullptr;
    }
    //we create a new node and set its attributes equal to our original node
    RBTNode* newNode = new RBTNode();
    newNode->key = node->key;
    newNode->color = node->color;
    newNode->parent = parentnode;

    //copy the left and right subtrees to get the properties of the left and right nodes

    newNode->left = copying(node->left, newNode);
    newNode->right = copying(node->right, newNode);
    return newNode; 
}
RBTNode* RedBlackTree::FindNode(int key){
    if (root == nullptr){
        return nullptr;
    }
    RBTNode* current = root;
   
    while (current != nullptr){
        if (current->key == key){
            
            return current;
        }
        else if (key > current->key){
            current = current->right;
            

        }
        else {
            current = current->left;
            
        }
    }
    return nullptr;
}
void RedBlackTree::Remove(int key){

    if (!Contains(key)){
        throw invalid_argument("error");
       
    }
    numItems--;
    RBTNode* node = FindNode(key);
    RBTNode* replacement = GetReplacement(node);
    
    bool IsDoubleBlack = (replacement == nullptr or replacement->color == COLOR_BLACK) && (node->color == COLOR_BLACK);
   

    RBTNode* Parent = node->parent;
    if (node->left && node->right){
        int temp = replacement->key;
        
        
        
        Remove(replacement->key);
        node->key = temp;
        //delete replacement;
        numItems++;
        return;


    }
    if (replacement == nullptr){ //the right subtree is null
        if (node == root){
            root = nullptr;
            
        }
        else{
            if (IsDoubleBlack){
                FixDoubleBlack(node);
            }
            else{
                if (GetSibling(node) != nullptr){
                    GetSibling(node)->color = COLOR_RED;
                }
            }
            if (node->parent->left == node){
                Parent->left = nullptr;
            }
            else{
                Parent->right = nullptr;
            }
        }
        delete node;
        return;
    }
    if (node->left == nullptr || node->right == nullptr){ //one child case
        if (node == root){
            node->key = replacement->key;
            node->left =nullptr;
            node->right = nullptr;
            delete replacement;
            
        }
        else{
            if (node->parent->left == node){
                Parent->left = replacement;
            }
            else{
                Parent->right = replacement;
            }
            delete node;
            replacement->parent = Parent;
            if (IsDoubleBlack){
                FixDoubleBlack(replacement);
            }
            else{
                replacement->color = COLOR_BLACK;
            }
        }
        

    }
    
   
    

 
}
void RedBlackTree::FixDoubleBlack(RBTNode* node){
    //case 1 if the double black node is the root node, just mark the root as black
    if (root == node){
        root->color = COLOR_BLACK;
        return;

    }
    RBTNode* sibling = GetSibling(node);
    RBTNode* Parent = node->parent;
    if (sibling == nullptr){
        FixDoubleBlack(Parent);
        return;

    }
    if (sibling->color == COLOR_BLACK){
         if ((sibling->left && sibling->left->color == COLOR_RED) || (sibling->right && sibling->right->color == COLOR_RED)){
            if (Parent->right == sibling){
               
                //right right case
                if (sibling->right && sibling->right->color == COLOR_RED){
                    leftRotate(Parent);
                    sibling->right->color = sibling->color;
                    sibling->color = Parent->color;
                    Parent->color = COLOR_BLACK;
                    node->color = COLOR_BLACK;

                }
                else{
                    
                    //right left case
                    rightRotate(sibling);
                    
                    leftRotate(Parent);
                    
                   
                    sibling->parent->color = Parent->color;
                    Parent->color = COLOR_BLACK;
                    sibling->parent->right->color = COLOR_BLACK;
                    node->color = COLOR_BLACK;

                }
            }
            else{
                if (sibling->left && sibling->left->color == COLOR_RED){
                    rightRotate(Parent);
                    sibling->left->color = sibling->color;
                    sibling->color = Parent->color;
                    Parent->color = COLOR_BLACK;
                    node->color = COLOR_BLACK;

                }
                else{
                    leftRotate(sibling);
                    
                    rightRotate(Parent);
                    
                    
                    sibling->parent->color = Parent->color;
                    Parent->color = COLOR_BLACK;
                    sibling->parent->left->color = COLOR_BLACK;
                    node->color = COLOR_BLACK;
                    

                }

            }

         }
         else{
            sibling->color = COLOR_RED;
            node->color = COLOR_BLACK;
            if (Parent->color == COLOR_RED){
                Parent->color = COLOR_BLACK;
            }
            else{
                FixDoubleBlack(Parent);
            }
         }

    }
    else{
        Parent->color = COLOR_RED;
        sibling->color = COLOR_BLACK;
        if (Parent->right == sibling){
            leftRotate(Parent);
        }
        else{
            rightRotate(Parent);
        }
       
        FixDoubleBlack(node);
        return;
    }

}
RBTNode* RedBlackTree::GetReplacement(RBTNode* node){
    if (node->left && node->right){ //two child case
        return InOrderSuccessor(node->right);
    }
    else if (node->left || node->right){ //one child case
        if (node->left){
            return node->left;
        }
        else{
            return node->right;
        }
    }
    else{ //no child case
        return nullptr;
    }
}
RBTNode* RedBlackTree::InOrderSuccessor(RBTNode* node){
    RBTNode* current = node;
    RBTNode* parent = nullptr;
    while (current != nullptr){
        parent = current;
        current = current->left;
    }
    return parent;
}
//this function gets the sibling node of a given node
RBTNode* RedBlackTree::GetSibling(RBTNode* node){
    //edge case: if the node is the root node, there should be no siblings
    if (root == node){
        return nullptr;
    }
    RBTNode* Parent = node->parent;
    //if the node is a left child the sibling will be the right child of the parent
    if (node == Parent->left){
        return Parent->right;
    }
    //right child case
    else{
        return Parent->left;
    }
}


void RedBlackTree::Insert(int key){
    if (root == nullptr){
        root = new RBTNode;
        root->key = key;
        root->color = COLOR_BLACK;
        root->parent = nullptr;
        numItems = 1;
        return;
    }
    if (Contains(key)){
         throw invalid_argument("No Duplicates allowed");
    }
    
    RBTNode* current = root;
    RBTNode* nodesparent = nullptr;
    RBTNode* newNode = new RBTNode();
    newNode->color = COLOR_RED;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    while (current != nullptr){
        nodesparent = current;
        if (newNode->key < current->key){
            current = current->left;
        }
        else if (newNode->key > current->key){
            current = current->right;
        }

    }
    newNode->parent = nodesparent;
    
    if (newNode->key < nodesparent->key){
        nodesparent->left = newNode;

    }
    else{
        nodesparent->right = newNode;
    }
        

    
    FixTree(newNode);
    numItems++;
    

}
void RedBlackTree::FixTree(RBTNode* node){
   
    // if parent of newNode is red 
    while (node->parent->color == COLOR_RED){
        
        //case 1 if the node is the left child of the grandparent
        
        if (node->parent == node->parent->parent->left){
            RBTNode* uncle = node->parent->parent->right;
            //case1a if the uncle is black
            if (uncle == nullptr||uncle->color == COLOR_BLACK){
                //if the node is a right child we need to left rotate and then right rotate
                if (node == node->parent->right){
                    node = node->parent;
                    leftRotate(node);
                }
                //if the node is a left child of the parent we just do the right rotation
                node->parent->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                rightRotate(node->parent->parent);
            }
            //case1b if the uncle is red we just recolor and repeat. The while loop will ensure the repeating steps
            else{ 
                uncle->color = COLOR_BLACK;
                node->parent->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                node = node->parent->parent; //move the node up and repeat

            }
        }
        
        //case 2 if the node is the right child of the grandparent. i didnt code this from scratch i copied my code from case 1 and changed very word that said 'left' ro 'right' and vice versa
        else{
            RBTNode* uncle = node->parent->parent->left;
            if (uncle == nullptr||uncle->color == COLOR_BLACK){
                //if the node is a left child we need to right rotate and then left rotate 
                if (node == node->parent->left){
                    node = node->parent;
                    rightRotate(node);
                }
                //if the node is a right child of the parent we just do the left rotation
                node->parent->color = COLOR_BLACK;
                node->parent->parent->color = COLOR_RED;
                leftRotate(node->parent->parent);
            }
            //case1b if the uncle is red we just recolor and repeat. The while loop will ensure the repeating steps
            else{ 
                uncle->color = COLOR_BLACK;
                node->parent->color = COLOR_BLACK;

                node->parent->parent->color = COLOR_RED;
                node = node->parent->parent; //move the node up and repeat

            }
        }
            if (node == root){
                break;
            }

        }
        root->color = COLOR_BLACK;
        
        
    }
    
    

//this function takes a node as an input and doeas rightrotate on it
void RedBlackTree::rightRotate(RBTNode* node){
    RBTNode* newparent = node->left;
    node->left = newparent->right;
    if (newparent->right != nullptr){
        newparent->right->parent = node;
    }
    newparent->parent = node->parent;
    if (node->parent == nullptr){
        root = newparent;
    }
    else if (node == node->parent->right){
        node->parent->right = newparent;
    }
    else{
        node->parent->left = newparent;
    }
    newparent->right = node;
    node->parent = newparent;
    
}
//this function does the left rotate. I didnt really code it from scratch i just copied my code from rightrotate and switched every word that says 'left' to 'right' and hope that worked
void RedBlackTree::leftRotate(RBTNode* node){ 
    RBTNode* newparent = node->right;
    node->right = newparent->left;
    if (newparent->left != nullptr){
        newparent->left->parent = node;

    }
    newparent->parent = node->parent;
    if (node->parent == nullptr){
        root = newparent;
    }
    else if (node == node->parent->left){
        node->parent->left = newparent;
    }
    else{
        node->parent->right = newparent;
    }
    newparent->left = node;
    node->parent = newparent;
}

bool RedBlackTree::Contains(int key){
    RBTNode* curr = root;
    while (curr != nullptr){
        if (key < curr->key){
            curr = curr->left;
        }
        else if (key > curr->key){
            curr = curr->right;
        }
        else{
            return true;
        }
    }
    return false;

}

string RedBlackTree::ToInfixString(RBTNode* node) const{
    if (node == nullptr){
        return "";
    }
    string color = "";
    if (node->color == COLOR_BLACK){
        color = " B";
    }
    else{
        color = " R";
    }
    
    string left = ToInfixString(node->left);
    string right = ToInfixString(node->right);
    return left + color + to_string(node->key) + " " + right;

}
string RedBlackTree::ToPostfixString(RBTNode* node) const{
    if (node == nullptr){
        return "";
    }
    string color = "";
    if (node->color == COLOR_BLACK){
        color = " B";
    }
    else{
        color = " R";
    }
    
        string left = ToPostfixString(node->left);
    
    
    
    
        string right = ToPostfixString(node->right);
    
    return left + right + color + to_string(node->key)+ " ";

}
string RedBlackTree::ToPrefixString(RBTNode* node) const{
    if (node == nullptr){
        return "";
    }
    string color = "";
    if (node->color == COLOR_BLACK){
        color = " B";
    }
    else{
        color = " R";
    }
    
    string left = ToPrefixString(node->left);
    string right = ToPrefixString(node->right);
    
    return color+ to_string(node->key) + " " + left + right;

}
int RedBlackTree::Size() const{
    return numItems;
}
int RedBlackTree::GetMax() const{
    RBTNode* current = root;
    while (current != nullptr && current->right != nullptr){
        current = current->right;
    }

    if (current == nullptr){
        throw runtime_error("Tree is empty");
    }
    return current->key;
}
int RedBlackTree::GetMin() const{
    RBTNode* current = root;
    while (current != nullptr && current->left != nullptr){
        current = current->left;
    }

    if (current == nullptr){
        throw runtime_error("Tree is empty");
    }
    return current->key;
}

