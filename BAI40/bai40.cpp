#include <iostream>
#include <fstream>
#include <conio.h>
#include "danhsach.cpp"
using namespace std;

int main(){
    system("cls");
    cout << "------------ BAI 40 ------------" << endl;
    DanhSach a;
    while (true) {
        cout << "--------------------------------" << endl;
        cout << "Chon chuc nang:" << endl;
        cout << "1. Doc danh sach sinh vien tu tep" << endl;
        cout << "2. Them sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Cap nhat thon tin sinh vien" << endl;
        cout << "5. Tim kiem sinh vien" << endl;
        cout << "6. Hien thi danh sach ra man hinh" << endl;
        cout << "7. Ghi danh sach sinh vien vao ten" << endl;
        cout << "8. Thoat" << endl;
        cout << "--------------------------------" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:{
                system("cls");
                a.docFile("students.txt");
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 2:{
                system("cls");
                cin >> a;
                cout << "Them sinh vien thanh cong.\n";
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 3:{
                system("cls");
                string msv;
                cout << "Nhap MSV: "; cin >> msv;
                a.deleteStudent(msv);
                cout << "Xoa sinh vien thanh cong.\n";
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 4:{
                system("cls");
                string msv, ho_ten;
                int tuoi;
                cout << "Nhap MSV: "; cin >> msv;
                a.updateStudent(msv);
                cout << "Cap nhat thong tin sinh vien thanh cong.";
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 5:{
                system("cls");
                string msv;
                cout << "Nhap MSV: ";
                cin >> msv;
                a.findStudent(msv);
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 6:{
                system("cls");
                a.duyet();
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 7:{
                system("cls");
                a.ghiFile("output.txt");
                cout << "Ghi file thanh cong." << endl; 
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");            
                break;
            }
            case 8:{
                system("cls");
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                return 0;
            }
            default:{
                system("cls");
                cout << "Lua chon khong hon le." << endl;
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
        }
    }
    return 0;
}

// Nguyen Manh Hung