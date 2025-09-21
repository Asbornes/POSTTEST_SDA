#include <iostream>

struct Mahasiswa {
    std::string nama;
    int nim;
    float ipk;
};

int main() {
    const int jumlahMahasiswa = 4;
    Mahasiswa mhs[jumlahMahasiswa];

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        std::cout << "Masukkan data mahasiswa ke-" << i + 1 << ":" << std::endl;
        std::cout << "Nama: ";
        std::cin.ignore();
        std::getline(std::cin, mhs[i].nama);
        std::cout << "NIM: ";
        std::cin >> mhs[i].nim;
        std::cout << "IPK: ";
        std::cin >> mhs[i].ipk;
    }

    for (int i = 0; i < jumlahMahasiswa - 1; ++i) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; ++j) {
            if (mhs[j].ipk > mhs[j + 1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }

    std::cout << "\nData mahasiswa setelah diurutkan berdasarkan IPK (ascending):" << std::endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        std::cout << "\nMahasiswa ke-" << i + 1 << ":" << std::endl;
        std::cout << "Nama: " << mhs[i].nama << std::endl;
        std::cout << "NIM: " << mhs[i].nim << std::endl;
        std::cout << "IPK: " << mhs[i].ipk << std::endl;
    }

    return 0;
}