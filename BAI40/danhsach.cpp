#include <iostream>
#include <fstream>
#include "student.cpp"
#ifndef __DANHSACH__CPP__
#define __DANHSACH_CPP__
using namespace std;
class DanhSach{
    BST<string, Student> a;
    public:
        DanhSach(){}
        DanhSach(BST<string, Student> a1) { a = a1; }

        void addStudent(Student &s){
            a.insert(s.getMSV(), s);
        }

       void duyet(Node<string, Student>* p) { // inoder
            if (p != NULL) {
                duyet(p->getLeft());
                cout << "Ma sinh vien: " << p->getElem().getMSV() << endl;
                cout << "Ho ten: " << p->getElem().getHoten() << endl;
                cout << "Tuoi: " << p->getElem().getTuoi() << endl << endl;
                duyet(p->getRight());
            }
        }

        void duyet() {
            duyet(a.getRoot());
        }

        void findStudent(string msv1){
            cout << "Nhap MSV cua sinh vien can tim: ";
            cin >> msv1;
            if(a.search(msv1, a.getRoot()) == NULL){
                cout << "Khong co sinh vien can tim.\n";
            }
            else{
                cout << "Sinh vien can tim la: \n";
                cout << "\tMa sinh vien: " <<  a.search(msv1, a.getRoot())->getElem().getMSV() << endl;
                cout << "\tHo ten: " <<  a.search(msv1, a.getRoot())->getElem().getHoten() << endl;
                cout << "\tTuoi: " << a.search(msv1, a.getRoot())->getElem().getTuoi() << endl;
            }
        }

        void deleteStudent(string msv1){
            cout << "Nhap MSV cua sinh vien can xoa: "; cin >> msv1;
            if(a.search(msv1, a.getRoot()) == NULL){
                cout << "Khong tim thay sinh vien nay.\n";
            }
            else{
                a.remove(msv1);
                cout << "Xoa sinh vien thanh cong.\n";
            }
        }

        void updateStudent(string msv1){
            cout << "Nhap MSV cua sinh vien can cap nhat: "; 
            cin >> msv1;
            if(a.search(msv1, a.getRoot()) == NULL){
                cout << "Khong co sinh vien can tim.\n";
            }
            else{
                string ten; int tuoi;
                deleteStudent(msv1);
                cout << "Nhap ten can thay doi: "; cin.ignore(); getline(cin, ten);
                cout << "Nhap tuoi can thay doi: "; cin >> tuoi;
                Student tmp(msv1, ten, tuoi);
                addStudent(tmp);
                cout << "Cap nhat thong tin sinh vien thanh cong.\n";
            }
        }

        friend istream& operator>> (istream& is, DanhSach& d){
            cout << "Nhap thong tin sinh vien: \n";
            Student tmp; is >> tmp;
            if(d.a.search(tmp.getMSV(), d.a.getRoot()) == NULL){
                d.addStudent(tmp);
                cout << "Them sinh vien thanh cong.\n";
            }
            else    
                cout << "Sinh vien da ton tai.\n";
            return is;
        }

        void docFile(ifstream& file) {
            string msv, ho_ten;
            int tuoi;
            while (file >> msv) {
                file.ignore();
                getline(file, ho_ten);
                file >> tuoi;
                Student tmp(msv, ho_ten, tuoi);
                addStudent(tmp);
            }
        }

        void docFile(const string& filename) {
            ifstream file(filename);
            if (file) {
                cout << "Doc file thanh cong.\n";
                docFile(file);
                file.close();
            } else {
                cout << "Khong mo duoc tep." << endl;
            }
        }

        void ghiFile(ofstream& file, Node<string, Student>* p) {
            if (p != nullptr) {
                ghiFile(file, p->getLeft());
                file << "---------------------------------" << endl;
                file << "MSV: " << p->getElem().getMSV() << endl;
                file << "Ho ten: " << p->getElem().getHoten() << endl;
                file << "Tuoi: " << p->getElem().getTuoi() << endl;
                ghiFile(file, p->getRight());
            }
        }

        void ghiFile(const string& filename) {
            ofstream file(filename);
            if (!file) {
                cout << "Khong mo duoc tiep." << endl;
                return;
            }
            ghiFile(file, a.getRoot());
            file.close();
            cout << "Ghi file thanh cong." << endl; 
        }
};
#endif