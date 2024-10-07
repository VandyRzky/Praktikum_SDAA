#include <iostream>

using namespace std;

struct kamera{
    string idKamera;
    string nama;
    string harga;
    kamera* next;
};

// Fungsi untuk menambahkan kamera ke stack (push)
void push(kamera*& head, string idKamera, string namaKamera, string harga) {
    kamera* newKamera = new kamera();
    newKamera->idKamera = idKamera;
    newKamera->nama = namaKamera;
    newKamera->harga = harga;
    newKamera->next = head; // Elemen baru akan menunjuk ke elemen sebelumnya (yang ada di head)
    head = newKamera; // Head sekarang adalah elemen baru
}

// Fungsi untuk menampilkan seluruh kamera (stack)
void tampilkanKamera(kamera*& head) {
    if (head == nullptr) {
        cout << "Stack kosong!" << endl;
        return;
    }
    kamera* temp = head;
    while (temp != nullptr) {
        cout << "Id kamera: " << temp->idKamera << endl;
        cout << "Nama kamera: " << temp->nama << endl;
        cout << "Harga (Rp): " << temp->harga << endl;
        cout << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menghapus kamera dari stack (pop)
void pop(kamera*& head) {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada yang bisa di-pop!" << endl;
        return;
    }
    kamera* temp = head;
    head = head->next; // Pindahkan head ke elemen berikutnya
    delete temp; // Hapus elemen paling atas
    cout << "Kamera paling atas telah dihapus (pop)" << endl;
}

// Fungsi untuk menambah kamera ke stack (push) melalui input user
void tambahKamera(kamera*& head) {
    string idKamera, namaKamera, harga;
    cin.ignore();
    cout << "Masukkan ID kamera >> ";
    getline(cin, idKamera);
    cout << "Masukkan nama kamera >> ";
    getline(cin, namaKamera);
    cout << "Masukkan harga kamera >> ";
    getline(cin, harga);
    push(head, idKamera, namaKamera, harga);
}

// Menu aplikasi stack
void menu(kamera*& head) {
    string pilih, ulang = "y";
    while (ulang == "y") {
        cout << "1. Tambah kamera (push)\n"
             << "2. Lihat kamera (tampilkan stack)\n"
             << "3. Hapus kamera (pop)\n"
             << "4. Keluar\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        if (pilih == "1") {
            tambahKamera(head);
        } else if (pilih == "2") {
            tampilkanKamera(head);
        } else if (pilih == "3") {
            pop(head);
        } else if (pilih == "4") {
            ulang = "t";
        } else {
            cout << "Pilihan tidak ada" << endl;
        }
    }
}

int main(int argc, char const* argv[]) {
    kamera* head = nullptr;

    menu(head);

    return 0;
}
