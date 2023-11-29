#include <iostream>
#include <math.h>
#include <fstream>
#include "dathuc.cpp"
using namespace std;

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
    outputFile << "OUTPUT" << endl;
    outputFile << "----------------------------------------------------------------";
    outputFile << "\nDa thuc A la: y(x) = ";        a.ghiFile(outputFile, a);        
    outputFile << "\nDa thuc B la: y(x) = ";        b.ghiFile(outputFile, b); 
    outputFile << "\nTong hai da thuc la: y(x) = "; tong.ghiFile(outputFile, tong);
    outputFile << "\nTich hai da thuc la: y(x) = "; tich.ghiFile(outputFile, tich); 
    outputFile << "\nHieu hai da thuc la: y(x) = "; hieu.ghiFile(outputFile, hieu); 
    outputFile.close();
    cout << "--------------------------------" << endl;
}

// Nguyen Manh Hung