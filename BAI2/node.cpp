#include <iostream>
#include <math.h>
#include <fstream>
#include "dslk.cpp"

using namespace std;

class donthuc {
    float heso;
    int bac;
public:
    donthuc() {}
    donthuc(float hs, int bac_moi) {
        heso = hs;
        bac = bac_moi;
    }
    float getHS() const { return heso; }
    int getBac() const { return bac; }

    friend istream& operator>>(istream& cin, donthuc& a) {
        cout << "Nhap he so: ";
        cin >> a.heso;
        return cin;
    }

    friend ostream& operator<<(ostream& cout, const donthuc& a) {
        if(a.bac == 0){
            if(a.heso) cout << a.heso;
        }
        else{ 
            if(a.heso>0) cout << " + " << a.heso << "x^" << a.bac;
            if(a.heso<0) cout << " - " << fabs(a.heso) << "x^" << a.bac;
        }
        return cout;
    }
};