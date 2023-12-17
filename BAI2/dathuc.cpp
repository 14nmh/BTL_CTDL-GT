#include <iostream>
#include <math.h>
#include <fstream>
#include "node.cpp"
using namespace std;

class DaThuc {
    slist<donthuc> L;
    int n;
public:
    DaThuc(){}
    DaThuc(slist<donthuc> a){
        this->L = a;
    }
    void addNode(const donthuc& tmp) {
        if(tmp.getHS() != 0) L.push_back(tmp);
    }

    void duyet() {
        for(slist_it<donthuc> i = L.begin(); i != L.end(); ++i) {
            cout << *i;
        }
    }

    DaThuc operator+(DaThuc& p)  {
        DaThuc res;
        slist_it<donthuc> it1 = L.begin();
        slist_it<donthuc> it2 = p.L.begin();
        while(it1 != L.end() && it2 != p.L.end()) {
            int b1 = it1.getCur()->getElem().getBac();
            int hs1 = it1.getCur()->getElem().getHS();
            int b2 = it2.getCur()->getElem().getBac();
            int hs2 = it2.getCur()->getElem().getHS();
            res.addNode(donthuc(hs1 + hs2, b1));
            ++it1;
            ++it2;
        }
        while(it1 != L.end()) {
            res.addNode(*it1);
            ++it1;
        }
        while(it2 != p.L.end()) {
            res.addNode(*it2);
            ++it2;
        }
        return res;
    }

    DaThuc operator-(DaThuc& p)  {
        DaThuc res;
        slist_it<donthuc> it1 = L.begin();
        slist_it<donthuc> it2 = p.L.begin();
        while(it1 != L.end() && it2 != p.L.end()) {
            int b1 = it1.getCur()->getElem().getBac();
            int hs1 = it1.getCur()->getElem().getHS();
            int b2 = it2.getCur()->getElem().getBac();
            int hs2 = it2.getCur()->getElem().getHS();
            res.addNode(donthuc(hs1 - hs2, b1));
            ++it1;
            ++it2;
        }
        while(it1 != L.end()) {
            res.addNode(*it1);
            ++it1;
        }
        while(it2 != p.L.end()) {
            res.addNode(donthuc(-(it2.getCur()->getElem().getHS()), it2.getCur()->getElem().getBac()));  
            ++it2;
        }
        return res;
    }

    DaThuc operator*(DaThuc& p){
        DaThuc temp;
        for(slist_it<donthuc> it1 = L.begin(); it1 != L.end(); ++it1) {
            for(slist_it<donthuc> it2 = p.L.begin(); it2 != p.L.end(); ++it2) {
                int b1 = it1.getCur()->getElem().getBac();
                int hs1 = it1.getCur()->getElem().getHS();
                int b2 = it2.getCur()->getElem().getBac();
                int hs2 = it2.getCur()->getElem().getHS();
                temp.addNode(donthuc(hs1 * hs2, b1 + b2));
            }
        }
        DaThuc res;
        for(int i = 0; i<= temp.L.size(); i++){
            float t = 0;
            for(slist_it<donthuc> it = temp.L.begin(); it != temp.L.end(); ++it) {
                if(it.getCur()->getElem().getBac() == i){
                    t += it.getCur()->getElem().getHS();
                }
            }
            res.addNode(donthuc(t, i));
        }
        return res;
    }


    friend istream& operator>>(istream& is, DaThuc& a) {
        cout << "\tNhap bac cua da thuc: ";
        is >> a.n;
        for(int i = 0; i <= a.n; i++) {
            float heso_moi;
            cout << "\tNhap he so cua bac " << i << " : ";
            is >> heso_moi; 
            if(heso_moi == 0) continue;
            donthuc tmp(heso_moi, i);
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
        for(slist_it<donthuc> i = L.begin(); i != L.end(); ++i) {
            fileout << *i;
        }
    }
};