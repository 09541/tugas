#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nama_item;
    string prev_item;
    string item_terkuat;
    string item_terlemah;
    char lagi ='y';
    int stat;
    int prev_stat;
    int stat_tertinggi;
    int stat_terrendah;
    bool first = true;

    while(lagi=='y') {
        cout << "Masukkan nama item : ";
        cin >> nama_item;
        cout << "Masukkan stat : ";
        cin >> stat;
        cout << "Item Anda adalah : " << nama_item;
        cout << "\nStat : " << stat;
        if (first == true) {
            prev_item = "Tidak ada";
            item_terkuat = nama_item;
            item_terlemah = nama_item;
            stat_tertinggi = stat;
            stat_terrendah = stat;
        }
        else {
            if(stat >= stat_tertinggi) {
                stat_tertinggi = stat;
                item_terkuat = nama_item;
            }
            else{
                if(stat <= stat_terrendah) {
                    stat_terrendah = stat;
                    item_terlemah = nama_item;
                }
            }
        }

        cout << "\nItem sebelumnya : " << prev_item;
        cout << "\nItem terhebat : " << item_terkuat;
        cout << "\nItem terlemah : " << item_terlemah;
        prev_item = nama_item;
        prev_stat = stat;
        first = false;
        cout << "\nInput item lagi ? (y/n)" << endl;
        cin >> lagi;
    }
    return 0;
}
