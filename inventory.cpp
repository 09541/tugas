#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
	vector<vector<string>> items{ { "pedang","100" },{ "pisau", "60" },{ "pistol","50" } ,{ "batu","20" } };
	vector<vector<string>> inventory;
	vector<vector<string>>::iterator iter1;
	vector<string>::iterator iter2;

	unsigned int maks_inventory = 0;
	long int maks_item = items.size();
	unsigned int pilihan;
	unsigned int item_dapat = 0;
	unsigned int jumlah_inventory = 0;
	unsigned int hapus;
    char lagi = 'y';

	cout << "jumlah item yang tersedia : " << maks_item << endl;
	cout << "kapasitas inventory : ";
	cin >> maks_inventory;
	cout << endl;

	while (lagi == 'y'||lagi=='Y') {
		hapus = 0;
        cout << "===================================" << endl;
		cout << "inventory : " << endl;
		cout << "1. Tampilkan inventory " << endl;
		cout << "2. Hapus item" << endl;
		cout << "3. Loot item" << endl;
		cout << "pilih perintah: ";
		cout << "===================================" << endl;
		cin >> pilihan;

		switch (pilihan) {
		case 1:
		{
			if (inventory.empty()) {
				cout << "INVENTORY KOSONG!!" << endl;
			}
			else {
				cout << "\nisi inventory : " << endl;
				for (iter1 = inventory.begin(); iter1 != inventory.end(); ++iter1) {
					for (iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
						cout << *iter2 << " ";
					}
					cout << endl;
				}
			}
			break;
		}
		case 2:
		{
			if (inventory.empty()) {
				cout << "INVENTORY KOSONG!!" << endl;
			}
			else {
				cout << "hapus item ke - : " << endl;
				cin >> hapus;
				if (hapus > jumlah_inventory) {
					cout << "item yang akan dihapus tidak ada." << endl;
				}
				else {
					inventory.erase(inventory.begin() + (hapus - 1));
					jumlah_inventory=-1;
					cout << "jumlah inventory sekarang : " << jumlah_inventory << endl;
				}
			}
			break;
		}

		case 3:
		{
			if (jumlah_inventory == maks_inventory) {
				cout << "INVENTORY PENUH!!! " << endl;
			}
			else {
				srand((unsigned)time(0));
				item_dapat = (rand() % maks_item);
				cout << "Anda mendapat : " << items[item_dapat][0] << " . Stat : " << items[item_dapat][1] << endl;

				inventory.push_back(vector<string>({ items[item_dapat][0] }));
				inventory[jumlah_inventory].push_back(items[item_dapat][1]);
				jumlah_inventory++;
				cout << "Jumlah inventory sekarang : " << jumlah_inventory << endl;
			}
			break;
		}
		}
		cout << "\nMasih ingin menggunakan menu inventory [y/n] ? ";
		cin >> lagi;
		cout << endl;
	}

	return 0;
}
