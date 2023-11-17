#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string msv;
    string hoten;
    int tuoi;
    Student* left;
    Student* right;
public:    
    Student(string m, string ht, int t)  {
        this->msv = m;
        this->hoten = ht;
        this->tuoi = t;
        left = right = nullptr;
    }
};

class DanhSach {
private:
    Student* root;
    
public:
    DanhSach(){ root = nullptr; }
    void addStudent(Student*& p, const string& msv, const string& ho_ten, int tuoi) {
        if (p == nullptr) {
            p = new Student(msv, ho_ten, tuoi);
        } 
        else if (msv < p->msv) {
            addStudent(p->left, msv, ho_ten, tuoi);
        } 
        else if (msv > p->msv) {
            addStudent(p->right, msv, ho_ten, tuoi);
        } 
    }

    void insert(const string& msv, const string& ho_ten, int tuoi) {
        Student *p = searchStudent(msv);
        if(p == NULL)
            addStudent(root, msv, ho_ten, tuoi);
        else{
            cout << "Sinh vien da ton tai." << endl;
        }
    }

    Student* deleteStudent(Student*& p, const string& msv) {
        if (p == nullptr) { 
            return p;
        } 
        else if (msv < p->msv) { 
            p->left = deleteStudent(p->left, msv);
        } 
        else if (msv > p->msv) {
            p->right = deleteStudent(p->right, msv);
        } 
        else {
            if (p->left == nullptr) { // co nut phai
                Student* temp = p->right;
                delete p;
                return temp;
            } 
            else if (p->right == nullptr) { // co nut trai
                Student* temp = p->left;
                delete p;
                return temp;
            } 
            // co ca 2 con
            Student* temp = findMinLest(p->right);
            p->msv = temp->msv;
            p->hoten = temp->hoten;
            p->tuoi = temp->tuoi;
            p->right = deleteStudent(p->right, temp->msv);
        }
        return p;
    }

    void deleteStudent(const string& msv) {
        root = deleteStudent(root, msv);
    }

    Student* findMinLest(Student* p) {
        while (p->left != nullptr) {
            p = p->left;
        }
        return p;
    }

    Student* searchStudent(Student* p, const string& msv) {
        if (p == nullptr || p->msv == msv) {
            return p;
        }
        if (msv < p->msv) {
            return searchStudent(p->left, msv);
        }
        return searchStudent(p->right, msv);
    }

    Student* searchStudent(const string& msv) {
        return searchStudent(root, msv);
    }

    void output(Student* p) {
        if (p != nullptr) {
            output(p->left);
            cout << "MSV: " << p->msv << endl;
            cout << "Ho ten: " << p->hoten << endl;
            cout << "Tuoi: " << p->tuoi << endl;
            cout << "-------------------------" << endl;
            output(p->right);
        }
    }

    void output() {
        output(root);
    }
    void updateStudent(const string& msv, const string& new_ho_ten, int new_tuoi) {
        Student* student = searchStudent(msv);
        if (student != nullptr) {
            student->hoten = new_ho_ten;
            student->tuoi = new_tuoi;
        } else {
            cout << "Khong tim thay sinh vien." << endl;
        }
    }

    void docFile(ifstream& file) {
        string msv, ho_ten;
        int tuoi;

        while (file >> msv) {
            file.ignore();
            getline(file, ho_ten);
            file >> tuoi;
            insert(msv, ho_ten, tuoi);
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
    
    void ghiFile(ofstream& file, Student* p) {
        if (p != nullptr) {
            ghiFile(file, p->left);
            file << "MSV: " << p->msv << endl;
            file << "Ho ten: " << p->hoten << endl;
            file << "Tuoi: " << p->tuoi << endl;
            file << "-------------------------" << endl;
            ghiFile(file, p->right);
        }
    }

    void ghiFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Khong mo duoc tiep." << endl;
            return;
        }
        ghiFile(file, root);
        file.close();
    }
};

int main() {
    cout << "------------ BAI 40 ------------" << endl;
    DanhSach a;
    a.docFile("students.txt");
    while (true) {
        cout << "Chon chuc nang:" << endl;
        cout << "\t1. Them sinh vien" << endl;
        cout << "\t2. Xoa sinh vien" << endl;
        cout << "\t3. Cap nhat thon tin sinh vien" << endl;
        cout << "\t4. Tim kiem" << endl;
        cout << "\t5. Hien thi danh sach" << endl;
        cout << "\t6. Ghi danh sach sinh vien" << endl;
        cout << "\t7. Thoat" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string msv, ho_ten;
                int tuoi;
                cout << "MSV: "; cin >> msv;
                cout << "Ho ten: ";
                cin.ignore(); getline(cin, ho_ten);
                cout << "Tuoi: "; cin >> tuoi;
                a.insert(msv, ho_ten, tuoi);
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
                cout << "Nhap ho ten: ";
                cin.ignore(); getline(cin, ho_ten);
                cout << "Nhap tuoi: "; cin >> tuoi;
                a.updateStudent(msv, ho_ten, tuoi);
                break;
            }
            case 4: {
                string msv;
                cout << "Nhap MSV: ";
                cin >> msv;
                Student* student = a.searchStudent(msv);
                if (student != nullptr) {
                    cout << "Thong tin sinh vien:" << endl;
                    cout << "MSV: " << student->msv << endl;
                    cout << "Ho ten: " << student->hoten << endl;
                    cout << "Tuoi: " << student->tuoi << endl;
                } else {
                    cout << "Khong tim thay." << endl;
                }
                break;
            }
            case 5: {
                a.output();
                break;
            }
            case 6: {
                a.ghiFile("students.txt");
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
