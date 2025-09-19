#include <iostream>
using namespace std;

void balikArray(int* array, int ukuran) {
    int* awal = array;
    int* akhir = array + ukuran - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int angkaPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int size = sizeof(angkaPrima) / sizeof(angkaPrima[0]);

    cout << "Array bilangan prima sebelum dibalik:" << endl;
    for (int i = 0; i < size; ++i) {
        std::cout << angkaPrima[i] << " ";
    }

    balikArray(angkaPrima, size);

    cout << "\nArray bilangan prima sesudah dibalik:" << endl;
    for (int i = 0; i < size; ++i) {
        std::cout << angkaPrima[i] << " ";
    }


    return 0;
}