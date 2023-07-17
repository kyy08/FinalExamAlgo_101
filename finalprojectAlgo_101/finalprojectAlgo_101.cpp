#include <iostream>
#include <string>
using namespace std;

// isi disini
const int MAX_MAHASISWA = 100;

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];

int jumlahMahasiswa = 0;
//isi disini

void tambahMahasiswa() {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "========== TAMBAH MAHASISWA ==========" << endl;
		cout << "NIM : ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore();
		cout << "Nama : ";
		getline(cin, nama[jumlahMahasiswa]);
		cout << "Tahun Masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];
		cin.ignore();

		jumlahMahasiswa++;
		cout << "Mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
}

//isi disini
void tampilkanSemuaMahasiswa() {
	cout << "============ SEMUA MAHASISWA ==========" << endl;
	if (jumlahMahasiswa > 0) {
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM     : " << NIM[i] << endl;
			cout << "Nama    : " << nama[i] << endl;
			cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
			cout << "----------------------------------" << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}
//isi disini
void algorithmacariMahasiswaByNIM() {
	int cariNIM;
	cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
	cout << "Masukkan NIM yang dicari: ";
	cin >> cariNIM;

	bool found = false;
	for (int i = 0; i < jumlahMahasiswa; i++) {
		if (NIM[i] == cariNIM)
			cout << "NIM     : " << NIM[i] << endl;
			cout << "Nama    : " << nama[i] << endl;
			cout << "Tahun   : " << tahunMasuk[i] << endl;
			cout << "----------------------------------------" << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan." << endl;
	}
}

//isi disini
void algorithmaSortByTahunMasuk() {
	cout << "========== SEMUA MAHASISWA BERDASARKAN TAHUN MASUK (TERURUT) ==========" << endl;
	if (jumlahMahasiswa > 0) {
		// Copy data mahasiswa ke temporary arrays
		int tempNIM[MAX_MAHASISWA];
		string tempNama[MAX_MAHASISWA];
		int tempTahunMasuk[MAX_MAHASISWA];
		for (int i = 0; i < jumlahMahasiswa; i++) {
			tempNIM[i] = NIM[i];
			tempNama[i] = nama[i];
			tempTahunMasuk[i] = tahunMasuk[i];
		}
		// Sorting berdasarkan tahun masuk
		for (int i = 0; i < jumlahMahasiswa - 1; i++) {
			for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
				if (tempTahunMasuk[j] > tempTahunMasuk[j + 1]) {
					swap(tempNIM[j], tempNIM[j + 1]);
					swap(tempNama[j], tempNama[j + 1]);
					swap(tempTahunMasuk[j], tempTahunMasuk[j + 1]);
				}
			}
		}
		// Menampilkan data mahasiswa yang sudah terurut
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM: " << tempNIM[i] << endl;
			cout << "Nama: " << tempNama[i] << endl;
			cout << "Tahun Masuk: " << tempTahunMasuk[i] << endl;
			cout << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}


int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa()
			break;
		case 3:
			cariMahasiswaByNIM();
			break;
		case 4:
			algoritmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}

		cout << endl;
	} while (pilihan != 5);

	return 0;
}

//2. stack,buble sort
//3. stack adalah algoritma yang terdiri dari push dan pop , sedangkan di da queue terdapat delete dan insert
//4.
//5. a 5
//5. b 