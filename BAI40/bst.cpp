#include <bits/stdc++.h>
#ifndef _BST_CPP
#define _BST_CPP
using namespace std;

template<class Keys, class T>
class Node{
    Keys key;
    T elem;
    Node<Keys,T> *parent;
    Node<Keys,T> *left;
    Node<Keys,T> *right;
    public:
        Node(){
            parent = left = right = NULL;
        }
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
        Keys getKey(){ return key;}
        void setKey(Keys k){ key = k; }
}; 

template<class Keys, class T>
class BST{
    Node<Keys,T> *root;
    int count;
    void remove(Node<Keys,T> *&v){
        Node<Keys, T> *p;
        if(!v->hasLeft() && !v->hasRight()){
            p = v->getParent();
            if(p != NULL)
                if(v == p->getLeft()) p->setLeft(NULL);
                else p->setRight(NULL);
            else root = NULL;
        }
        if(v->hasLeft() && !v->hasRight()){
            p = v->getParent();
            v->getLeft() -> setParent(p);
            if(p->getLeft() == v)
                p->setLeft(v->getLeft());
            else 
                p->setRight(v->getLeft());
        }
        if(!v->hasLeft() && v->hasRight()){
            p = v->getParent();
            v->getRight() -> setParent(p);
            if(p->getLeft() == v)
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
        int size(){ return count;}
        int isEmpty(){ return root == NULL; } 
        int isInternal(Node<Keys, T>* p){
            return p->hasLeft() || p->hasRight();
        }
        int isExternal(Node<Keys, T>* p){
            if(!p->hasLeft() || !p->hasRight()) return 1;
            else return 0;
        }
        int isRoot(Node<Keys, T>* p){
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
                if(p->getKey() > key)
                    return search(key, p->getLeft());
                else  
                    if(p->getKey() < key)
                        return search(key, p->getRight());
                    else 
                        return p;
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
			        if(key< p->getKey())
				        if(p->getLeft()==NULL){
					        q->setParent(p);
					        p->setLeft(q);
					        count++;
					        p = NULL; 
				        }
				        else
					        p = p->getLeft();
			        else
				        if(key> p->getKey())  // nam ben cay con ben phai
						    if(p->getRight()== NULL){
							    q->setParent(p);
							    p->setRight(q);
							    count++;
							    p = NULL;
						    }   
						    else
							    p = p->getRight();
				        else{
						    delete q;
						    p=NULL;
				        }
		            }
                }
            return q;    
        }
        void remove(Keys key){
            Node<Keys, T> *v = search(key, root);
            if(v == NULL) return;
            if(v-> hasLeft() && v->hasRight()){
                Node<Keys, T> *leftest;
                leftest = getLeftest(v->getRight());
                v->setKey(leftest->getKey());
                v->setElem(leftest->getElem());
                remove(leftest);
            }
            else remove(v);
            count--;
        }
};
#endif
// int main(){
// 	BST<int,char*> tree;
// 	Node<int,char*> *p;
// 	//BNode<int,float> *p;
// //	system("cls");
// 	tree.insert(100,"100-1");
// 	tree.insert(80,"80a");
// 	tree.insert(25,"25x");
// 	tree.insert(105,"105");
// 	tree.insert(13,"13");
// 	tree.insert(120,"120");
// 	tree.insert(175,"175");
// 	tree.insert(30,"30x");
// 	tree.insert(46,"46");
// 	//tree.preOrder(tree.getRoot(),visit);
// 	cout<<"\nDuyet cay theo thu tu giua:";	
// 	tree.inOrder(tree.getRoot());
	
// 	tree.remove(25);
// 	cout<<"\n";
// 	cout<<"\nDuyet cay theo thu tu dau:";	
// 	tree.preOrder(tree.getRoot());
// 	   	cout<<"\n";
//     tree.postOrder(tree.getRoot());
//     tree.remove(150);
//     cout<<"\n";
// 	p = tree.search(120, tree.getRoot());
// 	if(p!=NULL)
// 	  cout<<"Tim thay khoa 120, Co gia tri "<<p->getElem();
// 	else
// 	  cout<<"Khong tim thay khoa 120.";
	  
//     tree.remove(120);
//     //tree.remove(100);
//     tree.remove(70);    
// 	return 0;
// }
