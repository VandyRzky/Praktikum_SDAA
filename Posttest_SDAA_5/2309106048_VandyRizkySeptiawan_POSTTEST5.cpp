#include <iostream>
using namespace std;

struct kamera {
    string idKamera;
    string nama;
    string harga;
    kamera* next;
};

void tambahKameraProses(kamera*& head, string idKamera, string namaKamera, string harga);

void tambahKamera(kamera*& head) {
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

void tambahKameraProses(kamera*& head, string idKamera, string namaKamera, string harga) {
    kamera* tambahKamera = new kamera();
    tambahKamera->nama = namaKamera;
    tambahKamera->harga = harga;
    tambahKamera->idKamera = idKamera;
    tambahKamera->next = nullptr;

    if (head == nullptr) {
        head = tambahKamera;
    } else {
        kamera* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = tambahKamera;
    }
}

void tampilkanKamera(kamera*& head) {
    if (head == nullptr) {
        cout << "Belum ada data" << endl;
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

void hapusKamera(kamera*& head) {
    if (head == nullptr) {
        cout << "Belum ada data" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    kamera* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void editKamera(kamera*& head) {
    if (head == nullptr) {
        cout << "Belum ada data kamera" << endl;
        return;
    }
    string idKamera;
    tampilkanKamera(head);
    cin.ignore();
    cout << "Masukkan id kamera yang akan diubah >> ";
    getline(cin, idKamera);

    kamera* temp = head;
    while (temp != nullptr) {
        if (temp->idKamera == idKamera) {
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

kamera* getMiddle(kamera* head) {
    if (head == nullptr) return head;
    kamera* slow = head;
    kamera* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

kamera* merge(kamera* left, kamera* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    kamera* result = nullptr;

    if (left->nama <= right->nama) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

kamera* mergeSortKamera(kamera* head) {
    if (head == nullptr || head->next == nullptr) return head;

    kamera* middle = getMiddle(head);
    kamera* nextOfMiddle = middle->next;
    middle->next = nullptr;

    kamera* left = mergeSortKamera(head);
    kamera* right = mergeSortKamera(nextOfMiddle);

    kamera* sortedList = merge(left, right);

    return sortedList;
}

void mergeSort(kamera*& head) {
    if (head == nullptr) {
        cout << "Belum ada data untuk diurutkan" << endl;
        return;
    }
    head = mergeSortKamera(head);
    tampilkanKamera(head);
}

kamera* getTail(kamera* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

kamera* partition(kamera* head, kamera* end, kamera*& newHead, kamera*& newEnd) {
    kamera* pivot = end;
    kamera* prev = nullptr, * cur = head, * tail = pivot;

    while (cur != pivot) {
        // Compare nama secara descending
        if (cur->nama > pivot->nama) {
            if (newHead == nullptr) {
                newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev != nullptr) {
                prev->next = cur->next;
            }
            kamera* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (newHead == nullptr) {
        newHead = pivot;
    }
    newEnd = tail;

    return pivot;
}

kamera* quickSortRecur(kamera* head, kamera* end) {
    if (!head || head == end) {
        return head;
    }

    kamera* newHead = nullptr, * newEnd = nullptr;

    kamera* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        kamera* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(kamera*& head) {
    if (head == nullptr) {
        cout << "Belum ada data untuk diurutkan" << endl;
        return;
    }
    head = quickSortRecur(head, getTail(head));
    tampilkanKamera(head);
}

void menu(kamera*& head) {
    string pilih, ulang = "y";
    while (ulang == "y") {
        cout << "1. Tambah kamera \n"
            "2. Hapus kamera\n"
            "3. Edit kamera\n"
            "4. Tampilkan secara descending\n"
            "5. Tampilkan secara ascending\n"
            "6. Keluar\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        if (pilih == "1") {
            tambahKamera(head);
        } else if (pilih == "2") {
            hapusKamera(head);
        } else if (pilih == "3") {
            editKamera(head);
        } else if (pilih == "4") {
            quickSort(head);
        } else if (pilih == "5") {
            mergeSort(head);
        } else if (pilih == "6") {
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
