#include <iostream>
#include "bst.cpp"
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
class DanhSach{
    BST<string, Student> a;
    public:
        DanhSach(){}
        DanhSach(BST<string, Student> a1){
            a = a1;
        }
        void addStudent(Student &s){
            a.insert(s.getMSV(), s);
        }
        // void insert(){
        //     Student tmp; cin >> tmp;
        //     addStudent(tmp);
        // }
       void duyet(Node<string, Student>* p) {
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
            if(a.search(msv1, a.getRoot()) == NULL){
                cout << "Khong co sinh vien can tim.\n";
            }
            else{
                cout << "Sinh vien can tim la: \n";
                cout << "Ma sinh vien: " <<  a.search(msv1, a.getRoot())->getElem().getMSV() << endl;
                cout << "Ho ten: " <<  a.search(msv1, a.getRoot())->getElem().getHoten() << endl;
                cout << "Tuoi: " << a.search(msv1, a.getRoot())->getElem().getTuoi() << endl;
            }
        }

        void deleteStudent(string msv1){
            if(a.search(msv1, a.getRoot()) == NULL){
                cout << "Khong co sinh vien can tim.\n";
            }
            else{
                a.remove(msv1);
            }
        }
        void updateStudent(string msv1){
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
            }
        }
        friend istream& operator>> (istream& is, DanhSach& d){
            cout << "Nhap thong tin sinh vien: \n";
            Student tmp; is >> tmp;
            if(d.a.search(tmp.getMSV(), d.a.getRoot()) == NULL)
                d.addStudent(tmp);
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
                docFile(file);
                file.close();
            } else {
                cout << "Khong mo duoc tep." << endl;
            }
        }

        void ghiFile(ofstream& file, Node<string, Student>* p) {
            if (p != nullptr) {
                ghiFile(file, p->getLeft());
                file << "MSV: " << p->getElem().getMSV() << endl;
                file << "Ho ten: " << p->getElem().getHoten() << endl;
                file << "Tuoi: " << p->getElem().getTuoi() << endl;
                file << "-------------------------" << endl;
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
        }
};
int main(){
    cout << "------------ BAI 40 ------------" << endl;
    DanhSach a;
    a.docFile("students.txt");
    while (true) {
        cout << "Chon chuc nang:" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Xoa sinh vien" << endl;
        cout << "3. Cap nhat thon tin sinh vien" << endl;
        cout << "4. Tim kiem" << endl;
        cout << "5. Hien thi danh sach" << endl;
        cout << "6. Ghi danh sach sinh vien" << endl;
        cout << "7. Thoat" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cin >> a;
                break;
            }
            case 2: {
                string msv;
                cout << "Nhap MSV: "; cin >> msv;
                a.deleteStudent(msv);
                break;
            }
            case 3: {
                string msv, ho_ten;
                int tuoi;
                cout << "Nhap MSV: "; cin >> msv;
                a.updateStudent(msv);
                break;
            }
            case 4: {
                string msv;
                cout << "Nhap MSV: ";
                cin >> msv;
                a.findStudent(msv);
            }
            case 5: {
                a.duyet();
                break;
            }
            case 6: {
                a.ghiFile("output.txt");
                cout << "Ghi file thanh cong." << endl;
                break;
            }
            case 7: {
                return 0;
            }
            default: {
                cout << "Lua chon khong hon le." << endl;
            }
        }
    }

    return 0;
}