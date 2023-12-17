#include <iostream>
#ifndef _NODE_CPP__
#define _NODE_CPP__
using namespace std;

template<class Keys, class T>
class Node{
    Keys key;
    T elem;
   Node<K eys,T> *parent;
    Node<Keys,T> *left;
    Node<Keys,T> *right;
    public:
        Node() { parent = left = right = NULL; }
        Node<Keys,T> *getParent() { return parent; }
        Node<Keys,T> *getLeft() { return left; }
        Node<Keys,T> *getRight() { return right; }
        void setLeft(Node<Keys,T> *p) { left = p; }
        void setRight(Node<Keys,T> *p) { right = p; }
        void setParent(Node<Keys,T> *p) { parent = p; }
        int hasLeft() { return left != NULL; }
        int hasRight() { return right != NULL; }
        T getElem() { return elem; }
        void setElem(T e) { elem = e; }
        Keys getKey() { return key;}
        void setKey(Keys k) { key = k; }
}; 
#endif