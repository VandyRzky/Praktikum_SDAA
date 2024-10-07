#include <iostream>

using namespace std;

struct kamera{
    string idKamera;
    string nama;
    string harga;
    kamera* next;
};


void push(kamera*& head, string idKamera, string namaKamera, string harga) {
    kamera* newKamera = new kamera();
    newKamera->idKamera = idKamera;
    newKamera->nama = namaKamera;
    newKamera->harga = harga;
    newKamera->next = head; 
    head = newKamera; 
}


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

void pop(kamera*& head) {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada yang bisa di-pop!" << endl;
        return;
    }
    kamera* temp = head;
    head = head->next; 
    delete temp; 
    cout << "Kamera paling atas telah dihapus" << endl;
}

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

void editKamera(kamera*& head){
    if (head == nullptr){
        cout << "Belum ada data kamera" << endl;
        return;
    }
    string idKamera;
    tampilkanKamera(head);
    cin.ignore();
    cout << "Masukkan id kamera yang akan diubah >> ";
    getline(cin, idKamera);

    kamera* temp = head;
    while(temp != nullptr){
        if (temp->idKamera == idKamera){
            cout << "Masukkan nama kamera baru >> ";
            getline(cin, temp->nama);
            cout << "Masukkan harga kamera baru >> ";
            getline(cin, temp->harga);
            cout << "Berhasil melakukan perubahan data" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Id kamera tidak ditemukan" << endl;
}


void menu(kamera*& head){
    string pilih, ulang = "y";
    while (ulang == "y"){
        cout<< "1. Tambah kamera \n"
        "2. Lihat kamera\n"
        "3. Hapus kamera\n"
        "4. Edit kamera\n"
        "5. Keluar\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        if (pilih == "1"){
            tambahKamera(head);
        }else if(pilih == "2"){
            tampilkanKamera(head);
        }else if(pilih == "3"){
            pop(head);
        }else if (pilih == "4"){
            editKamera(head);
        }else if (pilih == "5"){
            ulang = "t";
        }else{
            cout << "Pilihan tidak ada" << endl;
        }  
    }
}

int main(int argc, char const* argv[]) {
    kamera* head = nullptr;

    menu(head);

    return 0;
}
