#include <iostream>
#include <fstream>
#include "bst.cpp"
#ifndef __STUDENT__CPP__
#define __STUDENT_CPP__
using namespace std;
class Student{
    string msv;
    string hoten;
    int tuoi;
    public:
        Student(){}
        Student(string msv1, string hoten1, int tuoi1){
            msv = msv1;
            hoten = hoten1;
            tuoi = tuoi1;
        }
        string getMSV() { return msv;}
        string getHoten() { return hoten;}
        int getTuoi() { return tuoi;}
        void setMSV(string msv1) { msv = msv1; }
        void setHoten(string hoten1) { hoten = hoten1; }
        void setTuoi(int tuoi1) { tuoi = tuoi1; } 
        friend istream& operator>> (istream& is, Student& a){
            cout << "\tNhap ma sinh vien: "; 
            is >> a.msv;
            cout << "\tNhap ho ten: ";
            cin.ignore();
            getline(is, a.hoten);
            cout << "\tNhap tuoi: ";
            is >> a.tuoi;
            return is;
        }
        friend ostream& operator<< (ostream& cout, Student& a){
            cout << "Ma sinh vien: " << a.msv << endl;
            cout << "Ho ten: " << a.hoten << endl;
            cout << "Tuoi: " << a.tuoi << endl;
            return cout;
        }
};
#endif