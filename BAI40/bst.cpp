#include <iostream>
#include "node.cpp"
#ifndef _BST_CPP__
#define _BST_CPP__
using namespace std;

template<class Keys, class T>
class BST{
    Node<Keys,T> *root;
    int count;
    void remove(Node<Keys,T> *&v){
        Node<Keys, T> *p;
        if(!v->hasLeft() && !v->hasRight()){ // khong co nut con
            p = v->getParent();
            if(p != NULL)
                if(v == p->getLeft()) p->setLeft(NULL);
                else p->setRight(NULL);
            else root = NULL;
        }
        if(v->hasLeft() && !v->hasRight()){ // co nut con trai
            p = v->getParent();
            v->getLeft()->setParent(p);
            if(v == p->getLeft()) 
                p->setLeft(v->getLeft());
            else 
                p->setRight(v->getLeft());
        }
        if(!v->hasLeft() && v->hasRight()){ // co nut con phai
            p = v->getParent();
            v->getRight()->setParent(p);
            if(v == p->getLeft())
                p->setLeft(v->getRight());
            else 
                p->setRight(v->getRight());
        }
        delete v;   
    }

    Node<Keys, T> *getLeftest(Node<Keys, T> *v){
        Node<Keys, T> *p = v;
        while (p->getLeft() != NULL){
            p = p->getLeft();
        }
        return p;
    }
    public:
        BST(){ root = NULL; count = 0;}
        Node<Keys, T> *getRoot(){ return root; }
        int size(){ return count; }
        int isEmpty(){ return root == NULL; } 
        int isInternal(Node<Keys, T>* p){ // nut trong
            return p->hasLeft() || p->hasRight();
        }
        int isExternal(Node<Keys, T>* p){ // nut ngoai
            if(!p->hasLeft() || !p->hasRight()) return 1;
            else return 0;
        }
        int isRoot(Node<Keys, T>* p){ // nut goc
            return p->getParent() == NULL;
        }
        void preOrder(Node<Keys, T>* p){
            if(p != NULL){
                cout << p->getKey() << " ";
                preOrder(p->getLeft());
                preOrder(p->getRight());
            }
        }
        void inOrder(Node<Keys, T>* p){
            if(p != NULL){
                inOrder(p->getLeft());
                cout << p->getKey() << " ";
                inOrder(p->getRight());
            }
        }
        void postOrder(Node<Keys, T>* p){
            if(p != NULL){
                postOrder(p->getLeft());
                postOrder(p->getRight());
                cout << p->getKey() << " ";
            }
        }

        Node<Keys, T>* search(Keys key, Node<Keys, T>* p){
            if(p != NULL){
                if(p->getKey() > key) return search(key, p->getLeft());
                else if(p->getKey() < key) return search(key, p->getRight());
                else return p;
            }
            else return NULL;
        }
        
        Node<Keys,T>* insert(Keys key, T elem){
	        Node<Keys, T>*p;
	        Node<Keys, T>*q = new Node<Keys, T>(); 
	        q->setKey(key);
	        q->setElem(elem);
	        if(root==NULL){
		        root = q;
		        count++;
	        }
	        else{
		        p = root;
		        while(p != NULL){
                    if(key == p->getKey()){ 
                        delete q;
                        p = NULL;
                    }
			        else if(key < p->getKey()){ 
				        if(p->getLeft() == NULL){
					        q->setParent(p);
					        p->setLeft(q);
					        count++;
					        p = NULL; 
				        }
				        else p = p->getLeft();
                    }
			        else{  
						if(p->getRight() == NULL){
							q->setParent(p);
							p->setRight(q);
							count++;
							p = NULL;
						}   
						else p = p->getRight();
                    }
		        }
            }
            return q;    
        }

        void remove(Keys key){
            Node<Keys, T> *v = search(key, root);
            if(v == NULL) return;
            if(v-> hasLeft() && v->hasRight()){ // co ca 2 nut con
                Node<Keys, T> *leftEst; 
                leftEst = getLeftest(v->getRight()); // tim cay trai nhat cua cay con ben phai
                v->setKey(leftEst->getKey());
                v->setElem(leftEst->getElem());
                remove(leftEst);
            }
            else remove(v);
            count--;
        }
};
#endif
