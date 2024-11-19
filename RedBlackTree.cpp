#include <iostream>
#include "RedBlackTree.h"
#include <stdexcept>
#include <string>
using namespace std;

//https://www.programiz.com/dsa/red-black-tree this website gave me a nice walkthrough which i used to learn how right rotation and left rotation should be implemented

RedBlackTree::RedBlackTree(){
    root = nullptr;
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
         throw runtime_error("No Duplicates allowed");
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

