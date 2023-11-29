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
        cout << "7. Ghi danh sach sinh vien vao tep" << endl;
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
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 3:{
                system("cls");
                string msv;
                a.deleteStudent(msv);
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 4:{
                system("cls");
                string msv;
                a.updateStudent(msv);
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");
                break;
            }
            case 5:{
                system("cls");
                string msv;
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
                cout << "Nhan phim bat ky de tiep tuc";
                getch();
                system("cls");            
                break;
            }
            case 8:{
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