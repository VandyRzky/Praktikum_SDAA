#include <iostream>
using namespace std;

struct kamera {
    int idKamera;
    string nama;
    string harga;
    kamera* next;
};

void tambahKameraProses(kamera*& head, int idKamera, string namaKamera, string harga);
int fibonacciSearch(kamera* head, int x);

int fibMonaccianSearch(int n) {
    int fib2 = 0; 
    int fib1 = 1; 
    int fibM = fib2 + fib1; 

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    return fibM;
}

kamera* getKameraAtIndex(kamera* head, int index) {
    kamera* temp = head;
    int count = 0;
    while (temp != nullptr && count < index) {
        temp = temp->next;
        count++;
    }
    return temp;
}

int getLength(kamera* head) {
    int length = 0;
    kamera* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

int fibonacciSearch(kamera* head, int x) {
    int length = getLength(head);

    int fib2 = 0; 
    int fib1 = 1; 
    int fibM = fib2 + fib1; 

    while (fibM < length) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, length - 1);
        kamera* kameraAtIndex = getKameraAtIndex(head, i);
        if (kameraAtIndex->idKamera < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (kameraAtIndex->idKamera > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }

        else {
            return i;
        }
    }

    kamera* kameraAtLastIndex = getKameraAtIndex(head, offset + 1);
    if (fib1 && kameraAtLastIndex->idKamera == x) {
        return offset + 1;
    }

    return -1;
}

void cariKameraFibonacci(kamera* head) {
    int idKamera;
    cout << "Masukkan ID kamera yang akan dicari >> ";
    cin >> idKamera;

    int index = fibonacciSearch(head, idKamera);

    if (index != -1) {
        kamera* kameraDitemukan = getKameraAtIndex(head, index);
        cout << "Id kamera: " << kameraDitemukan->idKamera << endl;
        cout << "Nama kamera: " << kameraDitemukan->nama << endl;
        cout << "Harga kamera: " << kameraDitemukan->harga << endl;
    } else {
        cout << "ID kamera tidak ditemukan" << endl;
    }
}


int manualSqrt(int num) {
    int result = 0;
    while (result * result <= num) {
        result++;
    }
    return result - 1;
}

int jumpSearch(kamera* head, int x) {
    int length = getLength(head);  
    int step = manualSqrt(length); 
    int prev = 0;
    kamera* temp = head;

    while (temp != nullptr && temp->idKamera < x) {
        prev = min(prev + step, length - 1);
        temp = getKameraAtIndex(head, prev);
        if (temp == nullptr || temp->idKamera >= x) {
            break;
        }
    }

    kamera* searchNode = getKameraAtIndex(head, prev - step);
    while (searchNode != nullptr && searchNode->idKamera <= x) {
        if (searchNode->idKamera == x) {
            return prev - step;  
        }
        searchNode = searchNode->next;
        prev++;
    }

    return -1;  
}

void cariKameraJump(kamera* head) {
    int idKamera;
    cout << "Masukkan ID kamera yang akan dicari >> ";
    cin >> idKamera;

    int index = jumpSearch(head, idKamera);

    if (index != -1) {
        kamera* kameraDitemukan = getKameraAtIndex(head, index);
        cout << "Id kamera: " << kameraDitemukan->idKamera << endl;
        cout << "Nama kamera: " << kameraDitemukan->nama << endl;
        cout << "Harga kamera: " << kameraDitemukan->harga << endl;
    } else {
        cout << "ID kamera tidak ditemukan" << endl;
    }
}

void makeLastOccurrenceTable(string pattern, int lastOccurrence[]) {
    int size = 256;  
    int m = pattern.length();

    for (int i = 0; i < size; i++) {
        lastOccurrence[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        lastOccurrence[(int)pattern[i]] = i;
    }
}

int boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int lastOccurrence[256];  
    makeLastOccurrenceTable(pattern, lastOccurrence);

    int shift = 0;  
    while (shift <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        if (j < 0) {
            return shift;  
        } else {
            shift += max(1, j - lastOccurrence[(int)text[shift + j]]);
        }
    }

    return -1;  
}

void cariKameraBoyerMoore(kamera* head) {
    string namaKamera;
    cout << "Masukkan nama kamera yang akan dicari >> ";
    cin.ignore();
    getline(cin, namaKamera);

    kamera* temp = head;
    bool ditemukan = false;
    int posisi = 0;
    while (temp != nullptr) {
        int index = boyerMooreSearch(temp->nama, namaKamera);
        if (index != -1) {
            cout << "Id kamera: " << temp->idKamera << endl;
            cout << "Nama kamera: " << temp->nama << endl;
            cout << "Harga kamera: " << temp->harga << endl;
            cout << endl;
            ditemukan = true;
        }
        temp = temp->next;
        posisi++;
    }

    if (!ditemukan) {
        cout << "Nama kamera tidak ditemukan" << endl;
    }
}


void tambahKamera(kamera*& head) {
    int idKamera;
    string namaKamera, harga;
    cin.ignore();
    cout << "Masukkan ID kamera >> ";
    cin >> idKamera;
    cin.ignore();
    cout << "Masukkan nama kamera >> ";
    getline(cin, namaKamera);
    cout << "Masukkan harga kamera >> ";
    getline(cin, harga);

    tambahKameraProses(head, idKamera, namaKamera, harga);
}

void tambahKameraProses(kamera*& head, int idKamera, string namaKamera, string harga) {
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
    int idKamera;
    tampilkanKamera(head);
    cin.ignore();
    cout << "Masukkan id kamera yang akan diubah >> ";
    cin >> idKamera;
    cin.ignore();

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
            "6. Cari Id dengan fibonachi search\n"
            "7. Cari Id dengan jump search\n"
            "8. Cari nama kamera\n"
            "9. Keluar\n";
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
        } else if(pilih == "6"){
            cariKameraFibonacci(head);
        } else if(pilih == "7"){
            cariKameraJump(head);
        } else if(pilih == "8"){
            cariKameraBoyerMoore(head);
        } else if (pilih == "9") {
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
