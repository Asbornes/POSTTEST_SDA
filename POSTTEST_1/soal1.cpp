#include <iostream>

void balikArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    const int ukuran = 7;
    int data[ukuran] = {2, 3, 5, 7, 11, 13, 17};

    std::cout << "Array sebelum dibalik: ";
    for (int i = 0; i < ukuran; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    balikArray(data, ukuran);

    std::cout << "Array sesudah dibalik: ";
    for (int i = 0; i < ukuran; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}