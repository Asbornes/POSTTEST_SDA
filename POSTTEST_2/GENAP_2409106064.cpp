#include <iostream>

using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node {
    Penerbangan data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;
string NIM = "064";
int kodeUnik = 0;

void transversal(Node* head) {
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa ditampilkan." << endl;
        return;
    }

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

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    cout << "Jadwal berhasil ditambahkan dengan kode: " << kodePenerbangan << endl;
}

void addSpecific(Node*& head, Node*& tail, int posisi, string tujuan, string status) {
    if (posisi < 1) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    if (posisi == 1) {
        Node* newNode = new Node;
        string kodePenerbangan = "JT-" + NIM;
        if (kodeUnik > 0) {
            kodePenerbangan += "-" + to_string(kodeUnik);
        }
        kodeUnik++;
        newNode->data.kodePenerbangan = kodePenerbangan;
        newNode->data.tujuan = tujuan;
        newNode->data.status = status;
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        cout << "Jadwal berhasil disisipkan dengan kode: " << kodePenerbangan << endl;
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
        temp->next = newNode;
        cout << "Jadwal berhasil disisipkan dengan kode: " << kodePenerbangan << endl;
    }
}

void deleteFirst(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Jadwal paling awal berhasil dihapus." << endl;
}

void edit(Node* head, Node* tail, string kodePenerbangan, string statusBaru) {
    if (head == nullptr) {
        cout << "Jadwal kosong, tidak bisa diupdate." << endl;
        return;
    }

    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kodePenerbangan) {
            cout << "Jadwal ditemukan! Mengupdate status..." << endl;
            temp->data.status = statusBaru;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Status berhasil diubah menjadi: " << statusBaru << endl;
    } else {
        cout << "Kode penerbangan tidak ditemukan." << endl;
    }
}

int main() {
    int pilihan;
    string tujuan, status, kodePenerbangan;
    int posisi;

    do {
        cout << "|======================================|" << endl;
        cout << "|        FLIGHT SCHEDULE SYSTEM        |" << endl;
        cout << "|======================================|" << endl;
        cout << "|    RIDWAN NUR RAHMAN - 2409106064    |" << endl;
        cout << "|><><><><><><><<><><><><><><><><><><><>|" << endl;
        cout << "|    1.Tambah Jadwal Penerbangan       |" << endl;
        cout << "|    2.Sisipkan Jadwal Penerbangan     |" << endl;
        cout << "|    3.Hapus Jadwal paling awal        |" << endl;
        cout << "|    4.Update Status Penerbangan       |" << endl;
        cout << "| 5.Tampilkan semua Jadwal Penerbangan |" << endl;
        cout << "|              0.Keluar                |" << endl;
        cout << "|======================================|" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Tujuan Penerbangan: ";
                cin.ignore();
                getline(cin, tujuan);
                addLast(head, tail, tujuan, "On Time");
                break;
            case 2:
                posisi = 3;
                cout << "Masukkan Tujuan Penerbangan: ";
                cin.ignore();
                getline(cin, tujuan);
                addSpecific(head, tail, posisi, tujuan, "On Time");
                break;
            case 3:
                deleteFirst(head, tail);
                break;
            case 4:
                cout << "Masukkan Kode Penerbangan yang ingin diubah: ";
                cin.ignore();
                getline(cin, kodePenerbangan);
                cout << "Masukkan Status Baru: ";
                getline(cin, status);
                edit(head, tail, kodePenerbangan, status);
                break;
            case 5:
                transversal(head);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}