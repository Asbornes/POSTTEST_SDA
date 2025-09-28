#include <iostream>
#include <string>

using namespace std;

void clearScreen() {
    system("cls || clear");
}

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node {
    Penerbangan data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;
string NIM = "064";
int kodeUnik = 0;
int jumlahJadwal = 0;

string pilihStatus() {
    int pilihan;
    while (true) {
        cout << "Pilih Status:\n";
        cout << "1. On Time\n";
        cout << "2. Boarding\n";
        cout << "3. Delayed\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: return "On Time";
            case 2: return "Boarding";
            case 3: return "Delayed";
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    }
}

void transversal(Node* head) {
    clearScreen();
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa ditampilkan." << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Kode Penerbangan: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->data.tujuan << endl;
            cout << "Status: " << temp->data.status << endl;
            temp = temp->next;
            cout << endl;
        }
        cout << "--- Akhir dari jadwal ---" << endl;
    }
    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

void transversalReverse(Node* tail) {
    clearScreen();
    if (tail == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa ditampilkan." << endl;
    } else {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << "Kode Penerbangan: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->data.tujuan << endl;
            cout << "Status: " << temp->data.status << endl;
            temp = temp->prev;
            cout << endl;
        }
        cout << "--- Akhir dari jadwal ---" << endl;
    }
    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

void showDetails(Node* head) {
    clearScreen();
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa ditampilkan." << endl;
        cout << "Tekan ENTER.....";
        cin.ignore();
        cin.get();
        clearScreen();
        return;
    }

    string kodePenerbangan;
    cout << "Masukkan Kode Penerbangan untuk melihat detail: ";
    cin.ignore();
    getline(cin, kodePenerbangan);

    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodePenerbangan) {
            cout << "\n--- Detail Jadwal ---" << endl;
            cout << "Kode Penerbangan: " << temp->data.kodePenerbangan << endl;
            cout << "Tujuan: " << temp->data.tujuan << endl;
            cout << "Status: " << temp->data.status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Kode Penerbangan tidak ditemukan." << endl;
    }

    cout << "Tekan ENTER.....";
    cin.get();
    clearScreen();
}

void addLast(Node*& head, Node*& tail, string tujuan, string status) {
    Node* newNode = new Node;

    string kodePenerbangan = "JT-" + NIM;
    if (kodeUnik > 0) {
        kodePenerbangan += "-" + to_string(kodeUnik);
    }
    kodeUnik++;

    newNode->data.kodePenerbangan = kodePenerbangan;
    newNode->data.tujuan = tujuan;
    newNode->data.status = status;
    newNode->next = nullptr;
    newNode->prev = tail; 

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    jumlahJadwal++;

    cout << "Jadwal berhasil ditambahkan dengan kode: " << kodePenerbangan << endl;
    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

void addSpecific(Node*& head, Node*& tail, int posisi, string tujuan, string status) {
    if (posisi < 1) {
        cout << "Posisi tidak valid." << endl;
        cout << "Tekan ENTER.....";
        cin.ignore();
        cin.get();
        clearScreen();
        return;
    }

    Node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << "Posisi melebihi panjang linked list." << endl;
    } else if (temp->next == nullptr) {
        addLast(head, tail, tujuan, status);
        return;
    } else {
        Node* newNode = new Node;
        string kodePenerbangan = "JT-" + NIM;
        if (kodeUnik > 0) {
            kodePenerbangan += "-" + to_string(kodeUnik);
        }
        kodeUnik++;
        newNode->data.kodePenerbangan = kodePenerbangan;
        newNode->data.tujuan = tujuan;
        newNode->data.status = status;
        newNode->next = temp->next;
        newNode->prev = temp; 
        temp->next->prev = newNode;
        temp->next = newNode;
        jumlahJadwal++;
        cout << "Jadwal berhasil disisipkan dengan kode: " << kodePenerbangan << endl;
    }

    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

void deleteFirst(Node*& head, Node*& tail) {
    clearScreen();
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa dihapus." << endl;
    } else {
        Node* temp = head;
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        jumlahJadwal--;
        cout << "Jadwal paling awal berhasil dihapus." << endl;
    }
    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

void update(Node* head, Node* tail, string kodePenerbangan) {
    clearScreen();
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak bisa diupdate." << endl;
    } else {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data.kodePenerbangan == kodePenerbangan) {
                cout << "Jadwal ditemukan! Mengupdate status..." << endl;
                temp->data.status = pilihStatus();
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            cout << "Status berhasil diupdate." << endl;
        } else {
            cout << "Kode penerbangan tidak ditemukan." << endl;
        }
    }
    cout << "Tekan ENTER.....";
    cin.ignore();
    cin.get();
    clearScreen();
}

int main() {
    clearScreen();
    int pilihan;
    string tujuan, status, kodePenerbangan;
    int posisi;

    do {
        cout << "========================================" << endl;
        cout << "|        FLIGHT SCHEDULE SYSTEM        |" << endl;
        cout << "|======================================|" << endl;
        cout << "|    RIDWAN NUR RAHMAN - 2409106064    |" << endl;
        cout << "|><><><><><><><<><><><><><><><><><><><>|" << endl;
        cout << "|    1. Tambah Jadwal Penerbangan      |" << endl;
        cout << "|    2. Sisipkan Jadwal Penerbangan    |" << endl;
        cout << "|    3. Hapus Jadwal paling awal       |" << endl;
        cout << "|    4. Update Status Penerbangan      |" << endl;
        cout << "|    5. Tampilkan Jadwal dari depan    |" << endl;
        cout << "|    6. Tampilkan Jadwal dari belakang |" << endl;
        cout << "|    7. Cari detail jadwal             |" << endl;
        cout << "|             0. Keluar                |" << endl;
        cout << "========================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;
        clearScreen();

        switch (pilihan) {
            case 1:
                cout << "Masukkan Tujuan Penerbangan: ";
                cin.ignore();
                getline(cin, tujuan);
                status = pilihStatus();
                addLast(head, tail, tujuan, status);
                break;
            case 2:
                if (jumlahJadwal < 4) {
                    cout << "Jumlah jadwal kurang dari 4, tidak bisa menyisipkan." << endl;
                    cout << "Tekan ENTER.....";
                    cin.ignore();
                    cin.get();
                    clearScreen();
                } else {
                    posisi = 5;
                    cout << "Masukkan Tujuan Penerbangan: ";
                    cin.ignore();
                    getline(cin, tujuan);
                    status = pilihStatus();
                    addSpecific(head, tail, posisi, tujuan, status);
                }
                break;
            case 3:
                deleteFirst(head, tail);
                break;
            case 4:
                cout << "Masukkan Kode Penerbangan yang ingin diubah: ";
                cin.ignore();
                getline(cin, kodePenerbangan);
                update(head, tail, kodePenerbangan);
                break;
            case 5:
                transversal(head);
                break;
            case 6:
                transversalReverse(tail);
                break;
            case 7:
                showDetails(head);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "Tekan ENTER.....";
                cin.ignore();
                cin.get();
                clearScreen();
                break;
        }
    } while (pilihan != 0);

    return 0;
}