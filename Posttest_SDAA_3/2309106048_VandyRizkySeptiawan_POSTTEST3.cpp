#include <iostream>

using namespace std;

struct kamera{
    string idKamera;
    string nama;
    string harga;
    kamera* next;
};

void tambahKameraProses(kamera*& head, string idKamera, string namaKamera, string harga);

void tambahKamera(kamera*& head){
    string idKamera, namaKamera, harga;
    cin.ignore();
    cout << "Masukkan ID kamera >> ";
    getline(cin, idKamera);
    cout << "Masukkan nama kamera >> ";
    getline(cin, namaKamera);
    cout << "Masukkan harga kamera >> ";
    getline(cin, harga);

    tambahKameraProses(head, idKamera, namaKamera, harga);
}

void tambahKameraProses(kamera*& head, string idKamera, string namaKamera, string harga){
    kamera* tambahKamera = new kamera();
    tambahKamera->nama = namaKamera;
    tambahKamera->harga = harga;
    tambahKamera->idKamera = idKamera;
    tambahKamera->next =  nullptr;

    if (head == nullptr){
            head = tambahKamera;
    }else{
        kamera* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = tambahKamera;
    }
}

void tampilkanKamera(kamera*& head){
    if (head == nullptr){
        cout << "Belum ada data" << endl;
        return;
    }
    kamera* temp = head;
    while (temp != nullptr){
        cout << "Id kamera: " << temp->idKamera << endl;
        cout << "Nama kamera: " << temp->nama << endl;
        cout << "Harga (Rp): " << temp->harga << endl;
        cout << endl;
        temp = temp->next;
    }
    
}

void hapusKamera(kamera*& head){
    if (head == nullptr){
        cout << "Belum ada data" << endl;
        return;
    }
    if (head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    kamera* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
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
            hapusKamera(head);
        }else if (pilih == "4"){
            editKamera(head);
        }else if (pilih == "5"){
            ulang = "t";
        }else{
            cout << "Pilihan tidak ada" << endl;
        }  
    }
}

int main(int argc, char const *argv[]){
    kamera* head = nullptr;

    menu(head);

    return 0;
}
