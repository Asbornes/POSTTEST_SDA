#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {1, 2, 3}, 
        {10, 6, 12},  
        {7, 8, 9}  
    };

    int totalBarisGenap = 0;

    for (int j = 0; j < 3; ++j) {
        totalBarisGenap += matriks[1][j];
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "[ "; 
        for (int j = 0; j < 3; ++j) {
            cout << matriks[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nJumlah elemen pada baris genap adalah: "<< matriks[1][0] << " + " << matriks[1][1] << " + " << matriks[1][2] << " = "<< totalBarisGenap << endl;

    return 0;
}