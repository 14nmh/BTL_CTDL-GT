#include <iostream>
#include <math.h>
#include <fstream>
#include "dslk.cpp"
using namespace std;

class node {
    float heso;
    int bac;

public:
    node() {}
    node(float hs, int bac_moi) {
        heso = hs;
        bac = bac_moi;
    }
    float getHS() const { return heso; }
    int getBac() const { return bac; }

    friend istream& operator>>(istream& cin, node& a) {
        cout << "Nhap he so: ";
        cin >> a.heso;
        return cin;
    }

    friend ostream& operator<<(ostream& cout, const node& a) {
        if(a.bac == 0){
            if(a.heso) cout << a.heso;
        }
        else{
            if(a.heso == 0) cout << " ";
            else{ 
                if(a.heso>0) cout << " + " << a.heso << "x^" << a.bac;
                if(a.heso<0) cout << " - " << fabs(a.heso) << "x^" << a.bac;
            }
        }
        return cout;
    }


};

class DaThuc {
    slist<node> L;
    int n;
public:
    DaThuc(){}
    DaThuc(slist<node> a){
        this->L = a;
    }
    void addNode(const node& tmp) {
        L.push_back(tmp);
    }

    void duyet() {
        for (slist_it<node> i = L.begin(); i != L.end(); i++) {
            cout << *i;
        }
    }

    DaThuc operator+(DaThuc& other)  {
        DaThuc res;
        slist_it<node> it1 = L.begin();
        slist_it<node> it2 = other.L.begin();

        while (it1 != L.end() && it2 != other.L.end()) {
            int b1 = it1.getcur()->getElem().getBac();
            int hs1 = it1.getcur()->getElem().getHS();
            int b2 = it2.getcur()->getElem().getBac();
            int hs2 = it2.getcur()->getElem().getHS();
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
        while (it2 != other.L.end()) {
            res.addNode(*it2);
            ++it2;
        }

        return res;
    }

    DaThuc operator-(DaThuc& other)  {
        DaThuc res;
        slist_it<node> it1 = L.begin();
        slist_it<node> it2 = other.L.begin();

        while (it1 != L.end() && it2 != other.L.end()) {
            int b1 = it1.getcur()->getElem().getBac();
            int hs1 = it1.getcur()->getElem().getHS();
            int b2 = it2.getcur()->getElem().getBac();
            int hs2 = it2.getcur()->getElem().getHS();
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
        while (it2 != other.L.end()) {
            res.addNode(node(-(it2.getcur()->getElem().getHS()), it2.getcur()->getElem().getBac()));  
            ++it2;
        }
        return res;
    }

    DaThuc operator*(DaThuc& other){
        DaThuc temp;
        for (slist_it<node> it1 = L.begin(); it1 != L.end(); ++it1) {
            for (slist_it<node> it2 = other.L.begin(); it2 != other.L.end(); ++it2) {
                int b1 = it1.getcur()->getElem().getBac();
                int hs1 = it1.getcur()->getElem().getHS();
                int b2 = it2.getcur()->getElem().getBac();
                int hs2 = it2.getcur()->getElem().getHS();
            temp.addNode(node(hs1 * hs2, b1 + b2));
            }
        }
        DaThuc res;
        for(int i = 0; i<= temp.L.size(); i++){
            float tmp = 0;
            for(slist_it<node> it = temp.L.begin(); it != temp.L.end(); ++it) {
                if(it.getcur()->getElem().getBac() == i){
                    tmp += it.getcur()->getElem().getHS();
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
        a.duyet();
        return os;
    }

    void ghiFile(ofstream &fileout, DaThuc& a) {
        for (slist_it<node> i = L.begin(); i != L.end(); i++) {
            fileout << *i;
        }
    }
};

int main() {
    cout << "-------------- BAI 2 --------------\n";
    DaThuc a, b, tong, hieu, tich;
    cout << "Nhap da thuc A:\n"; cin >> a;
    cout << "Nhap da thuc B:\n"; cin >> b;
    cout << "Da thuc A la: y(x) = " << a << endl;
    cout << "Da thuc B la: y(x) = " << b << endl;

    tong = a + b; cout << "Tong hai da thuc la: y(x) = " << tong << endl;

    hieu = a - b; cout << "Hieu hai da thuc la: y(x) = " << hieu << "\n";

    tich = a*b; cout << "Tich hai da thuc la: y(x) = " << tich << "\n";

    ofstream outputFile("output.txt");
    outputFile << "\nDa thuc A la: y(x) = ";        a.ghiFile(outputFile, a);        
    outputFile << "\nDa thuc B la: y(x) = ";        b.ghiFile(outputFile, b); 
    outputFile << "\nTong hai da thuc la: y(x) = "; tong.ghiFile(outputFile, tong);
    outputFile << "\nTich hai da thuc la: y(x) = "; tich.ghiFile(outputFile, tich); 
    outputFile << "\nHieu hai da thuc la: y(x) = "; hieu.ghiFile(outputFile, hieu); 
    outputFile.close();
}

// Nguyen Manh Hung