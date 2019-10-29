#include <iostream>
#include <ctime>
//#include <cmath>
#include <stdlib.h>

using namespace std;

int main() {

    int maks_nilai;
    int life = 3;
    int tebak;
    int tebakan;
    char lagi='y';

    while ((maks_nilai>100)||(maks_nilai<10)||(lagi=='y')) {
        cout << "\nMasukkan angka (10-100) : ";
        cin >> maks_nilai;
        if (maks_nilai > 100){
            cout << "Terlalu besar\n";
        }
        else if (maks_nilai < 10){
            cout << "Terlalu kecil\n";
        }
        else{
            cout << "Silakan tebak angka antara 0 sampai " << maks_nilai << " !! ";
            srand((unsigned)time(0));
            tebak = (rand()%maks_nilai)+1;
            cout << "\nini adalah bantuan!! " << tebak-9 << " -antara- " << tebak+7 << endl; ; //test the number
        }
        while (life > 0 && tebakan != tebak) {
            cout << "\nMasukkan tebakan Anda : ";
            cin >> tebakan;
            if (tebakan == tebak) {
                cout << "Tebakan Anda benar.\n";
                break;
            }
            else {
                life--;
                if (tebakan > tebak) {
                    cout << "Tebakan Anda terlalu besar.\n";
                }
                else if (tebakan < tebak) {
                    cout << "Tebakan Anda terlalu kecil.\n";
                }
                cout << "Tebakan Anda salah, nyawa : " << life << endl;
                if (life == 0) {
                    cout << "Game over." << endl;
                }
            }
        }
        cout << "main lagi???(y/n)" << endl;
        cin >> lagi;
    }
    return 0;
}
