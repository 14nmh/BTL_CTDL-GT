#include <iostream>
using namespace std;

template<class T>
class Node{
    T elem; 
    Node *next;
    public:
        Node(){}
        Node(T x, Node<T> *N = NULL){
            elem = x;
            next = N;
        }
        void setElem(T x) { elem = x; }
        void setNext(Node <T> *N = NULL) { next = N; }
        T &getElem() { return elem; }
        Node <T> *getNext() { return next; }
};

template<class T>
class slist_it{
    Node<T> *cur;
    public:
    //    slist_it(){ cur = NULL; }
        slist_it(Node<T> *N = NULL){ cur = N; }
        Node <T> *getcur() { return cur; }
        slist_it<T> &operator = (slist_it<T> p){ 
            this->cur = p.getcur();
            return *this;
        }
        bool operator != (slist_it<T> p){
            return cur!=p.getcur();
        }
        slist_it<T> operator++(){ 
            cur = cur->getNext();
            return cur; 
        }
        slist_it<T> operator++(int){
            Node<T> *tmp = cur;
            cur = cur->getNext();
            return tmp;
        }

        T &operator*(){ return cur->getElem(); } 
};
template<class T>
class slist{
    Node<T> *head, *tail;
    int n;
    public:
        typedef slist_it<T> iterator;
        slist(){ 
            head = tail = nullptr; 
            n = 0;
        }
        slist(int k, T x){
            head = tail = NULL; 
            n = 0;
            for(int i=1; i<=k; i++) push_back(x);
        }
        iterator begin(){ return head;}
        iterator end(){ return NULL;}
        int size(){ return n;}
        bool empty(){ return n == 0; }
        T &front(){ return head->getElem(); }
        T &back(){ return tail->getElem(); }
        void push_front(T x){
            head = new Node<T>(x, head);
            if(n == 0) tail = head;
            n++;
        }
        void push_back(T x){
            if(n == 0) push_front(x);
            else{
                tail->setNext(new Node<T>(x, NULL));
                tail = tail->getNext();
                n++;
            }
        }
        void pop_front(){
            if(n == 0) return;
            if(n == 1){
                head = tail = NULL;
            }
            else{
                head = head->getNext();
            }
            n--;
        }
        void pop_back(){
            if(n == 0) return;
            if(n == 1){
                head = tail = NULL;
                n--; return;
            }
            Node<T> *p = head;
            while(p->getNext() != tail){
                p = p->getNext();
            }
            p->setNext(NULL);
            tail = p;
            n--;
        }
};
