#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    double ipk;
};

int main() {
    int jumlahMahasiswa = 4;
    Mahasiswa daftarMahasiswa[jumlahMahasiswa];
    cout << "Masukkan data 4 mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        getline(cin >> ws, daftarMahasiswa[i].nama);
        cout << "NIM: ";
        cin >> daftarMahasiswa[i].nim;
        cout << "IPK: ";
        cin >> daftarMahasiswa[i].ipk;
    }

    cout << "\nData Mahasiswa sebelum diurutkan:" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Nama: " << daftarMahasiswa[i].nama << endl;
        cout << "NIM: " << daftarMahasiswa[i].nim << endl;
        cout << "IPK: " << daftarMahasiswa[i].ipk << endl;
        cout << "--------------------" << endl;
    }
    
    // Bubble Sort coyy
    for (int i = 0; i < jumlahMahasiswa - 1; ++i) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; ++j) {
            if (daftarMahasiswa[j].ipk > daftarMahasiswa[j + 1].ipk) {
                Mahasiswa temp = daftarMahasiswa[j];
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
                daftarMahasiswa[j + 1] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan berdasarkan IPK (ascending):" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Nama: " << daftarMahasiswa[i].nama << endl;
        cout << "NIM: " << daftarMahasiswa[i].nim << endl;
        cout << "IPK: " << daftarMahasiswa[i].ipk << endl;
        cout << "--------------------" << endl;
    }

    return 0;
}