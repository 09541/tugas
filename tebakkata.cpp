#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    string kata;
    string tebakan;
    int life=3;
    int jumlah_huruf;
    srand(static_cast<unsigned int>(time(0)));

    cout << "Masukkan sebuah kata : ";
    cin >> kata;
    jumlah_huruf = kata.size();
    cout << "\nJumlah huruf dari " << kata << " adalah : " << jumlah_huruf << endl;
    string acak = kata;

    for (int i = 0; i < jumlah_huruf; ++i) {
        int huruf1 = (rand() % jumlah_huruf);
        int huruf2 = (rand() % jumlah_huruf);
        char temp = acak[huruf1];
        acak[huruf1] = acak[huruf2];
        acak[huruf2] = temp;
    }

    cout << "kata teracak : " << acak << endl;

    while (life > 0 && tebakan != kata) {
        cout << "\nMasukkan tebakan Anda : ";
        cin >> tebakan;
        if (tebakan == kata) {
            cout << "Tebakan Anda benar.\n";
            break;
        }
        else {
            life--;
            if (tebakan!=kata) {
                cout << "Tebakan Anda terlalu besar.\n";
            }
            cout << "Tebakan salah, nyawa : " << life << endl;
            if (life == 0) {
                cout << "==Game over==" << endl;
            }
        }
    }

    return 0;
}
