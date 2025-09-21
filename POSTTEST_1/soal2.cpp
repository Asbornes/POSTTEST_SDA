#include <iostream>

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int jumlah_baris_genap = 0;

    std::cout << "Matriks 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriks[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Menghitung jumlah elemen baris genap (indeks 1)
    for (int j = 0; j < 3; j++) {
        jumlah_baris_genap += matriks[1][j];
    }

    std::cout << "\nJumlah elemen baris genap (baris kedua) adalah: " << jumlah_baris_genap << std::endl;

    return 0;
}