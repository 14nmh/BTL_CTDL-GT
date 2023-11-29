#include <iostream>
#include <math.h>
#include <fstream>
#include "node.cpp"
using namespace std;

class DaThuc {
    slist<node> L;
    int n;
public:
    DaThuc(){}
    DaThuc(slist<node> a){
        this->L = a;
    }
    void addNode(const node& tmp) {
        if(tmp.getHS() != 0) L.push_back(tmp);
    }

    void duyet() {
        for (slist_it<node> i = L.begin(); i != L.end(); ++i) {
            cout << *i;
        }
    }

    DaThuc operator+(DaThuc& p)  {
        DaThuc res;
        slist_it<node> it1 = L.begin();
        slist_it<node> it2 = p.L.begin();
        while (it1 != L.end() && it2 != p.L.end()) {
            int b1 = it1.getCur()->getElem().getBac();
            int hs1 = it1.getCur()->getElem().getHS();
            int b2 = it2.getCur()->getElem().getBac();
            int hs2 = it2.getCur()->getElem().getHS();
            if (b1 == b2) {
                node tmp(hs1 + hs2, b1);
                res.addNode(tmp);
                ++it1;
                ++it2;
            } else if (b1 > b2) {
                res.addNode(*it1);
                ++it1;
            } else {
                res.addNode(*it2);
                ++it2;
            }
        }
        while (it1 != L.end()) {
            res.addNode(*it1);
            ++it1;
        }
        while (it2 != p.L.end()) {
            res.addNode(*it2);
            ++it2;
        }
        return res;
    }

    DaThuc operator-(DaThuc& p)  {
        DaThuc res;
        slist_it<node> it1 = L.begin();
        slist_it<node> it2 = p.L.begin();

        while (it1 != L.end() && it2 != p.L.end()) {
            int b1 = it1.getCur()->getElem().getBac();
            int hs1 = it1.getCur()->getElem().getHS();
            int b2 = it2.getCur()->getElem().getBac();
            int hs2 = it2.getCur()->getElem().getHS();
            if (b1 == b2) {
                node tmp(hs1 - hs2, b1);
                res.addNode(tmp);
                ++it1;
                ++it2;
            } else if (b1 > b2) {
                res.addNode(*it1);
                ++it1;
            } else {
                res.addNode(node(-hs2, b2));  
                ++it2;
            }
        }
        while (it1 != L.end()) {
            res.addNode(*it1);
            ++it1;
        }
        while (it2 != p.L.end()) {
            res.addNode(node(-(it2.getCur()->getElem().getHS()), it2.getCur()->getElem().getBac()));  
            ++it2;
        }
        return res;
    }

    DaThuc operator*(DaThuc& p){
        DaThuc temp;
        for (slist_it<node> it1 = L.begin(); it1 != L.end(); ++it1) {
            for (slist_it<node> it2 = p.L.begin(); it2 != p.L.end(); ++it2) {
                int b1 = it1.getCur()->getElem().getBac();
                int hs1 = it1.getCur()->getElem().getHS();
                int b2 = it2.getCur()->getElem().getBac();
                int hs2 = it2.getCur()->getElem().getHS();
            temp.addNode(node(hs1 * hs2, b1 + b2));
            }
        }
        DaThuc res;
        for(int i = 0; i<= temp.L.size(); i++){
            float tmp = 0;
            for(slist_it<node> it = temp.L.begin(); it != temp.L.end(); ++it) {
                if(it.getCur()->getElem().getBac() == i){
                    tmp += it.getCur()->getElem().getHS();
                }
            }
            res.addNode(node(tmp, i));
        }
        return res;
    }


    friend istream& operator>>(istream& is, DaThuc& a) {
        cout << "\tNhap bac cua da thuc: ";
        is >> a.n;
        for (int i = 0; i <= a.n; i++) {
            float heso_moi;
            cout << "\tNhap he so cua bac " << i << " : ";
            is >> heso_moi; 
            if(heso_moi == 0) continue;
            node tmp(heso_moi, i);
            a.addNode(tmp);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os,  DaThuc& a) {
        if(a.L.empty()) os << 0;
        else a.duyet();
        return os;
    }

    void ghiFile(ofstream &fileout, DaThuc& a) {
        if(a.L.empty()){
            fileout << 0;
            return;
        }
        for (slist_it<node> i = L.begin(); i != L.end(); ++i) {
            fileout << *i;
        }
    }
};