#include <iostream>

using namespace std;

struct kamera{
    string namaKamera;
    string harga;
    string aksesoris[3];
    int jumlahAcc = 0;
    int maxAcc = sizeof(aksesoris)/sizeof(aksesoris[0]);
};

string menu(){
    return "1. Tambah \n"
	"2. Tampilkan \n"
	"3. Hapus \n"
	"4. Edit \n"
	"5. Keluar\n";
}

void tambahAksesoris(kamera arr[], int *idx){
    cout << "Masukkan nama aksesoris >> ";
    cin.ignore();
    getline(cin, arr[*idx].aksesoris[arr[*idx].jumlahAcc]);
    arr[*idx].jumlahAcc++;
}

void tampilkanAksesoris(kamera arr[], int idx){
    for (int i = 0; i < arr[idx].jumlahAcc; i++){
        cout << "\tAksesoris ke-" << i+1 << " " << arr[idx].aksesoris[i] << endl;
    }    
}

void editAksesoris(kamera arr[], int idx){
    cout << "1. Ganti nama aksesoris\n"
    "2. Hapus aksesoris\n";
    string pilih;
    cout << "Masukkan pilihan >> ";
    cin >> pilih;
    if (pilih == "1"){
        for (int i = 0; i < arr[idx].jumlahAcc; i++){
            cout << i+1 << ".\tAksesoris: " << arr[idx].aksesoris[i] << endl;;
        }
        int idxAcc;
        cout << "Masukkan indeks aksesoris >> ";
        cin >> idxAcc;
        if (idxAcc > arr[idx].jumlahAcc){
            cout << "Indeks aksesoris tidak ditemukan, pengeditan aksesoris gagal" << endl;
        }else{
            cout << "Masukkan nama aksesoris >> ";
            cin.ignore();
            getline(cin, arr[idx].aksesoris[idxAcc-1]);
        }
    }
    //error
    // else if (pilih == "2"){
    //     for (int i = 0; i < arr[idx].jumlahAcc; i++){
    //         cout << i+1 << ".\tAksesoris: " << arr[idx].aksesoris[i] << endl;;
    //     }
    //     int idxAcc;
    //     cout << "Masukkan indeks aksesoris >> ";
    //     cin >> idxAcc;
    //     if (idxAcc > arr[idx].jumlahAcc){
    //         cout << "Indeks aksesoris tidak ditemukan, penghapusan aksesoris gagal" << endl;
    //     }else{
    //         for (int i = idxAcc-1; i < arr[idx].maxAcc; i++){
    //             arr[idx].aksesoris[i] = arr[idx].aksesoris[i+1];
    //         }
    //         arr[idx].jumlahAcc--;
    //     }
    // }

    
    else{
        cout << "Pilihan tidak ada!!!" << endl;
    }
    

}

void tambah(kamera arr[], int& jml, int kapasitas){
    if (jml == kapasitas){
        cout << "Tidak dapat menambahkan data kamera" << endl;
    }else{
        cout << "Masukkan nama kamera >> ";
        cin.ignore();
        getline(cin, arr[jml].namaKamera);
        cout << "Masukkan harga >> ";
        getline(cin, arr[jml].harga);
        string pilih;
        cout << "Apakah ingin menambahkan aksesoris >> (y/t)";
        cin >> pilih;
        while (pilih == "y"){
            tambahAksesoris(arr, &jml);
            if(arr[jml].jumlahAcc < arr[jml].maxAcc){
                cout << "Apakah ingin menambahkan aksesoris (y/t) >> ";
                cin >> pilih;
            }else{
                break;
            }
        }
        jml++;
    }
}

void lihat(kamera arr[], int& jml, int kapasitas){
    if (jml == 0){
        cout << "Belum ada data kamera" << endl;
    }else{
        for (int i = 0; i < jml; i++){
            cout << i+1 << ".\tNama kamera: " << arr[i].namaKamera << endl;
            cout << "\tHarga: " << arr[i].harga << endl;
            if (arr[i].jumlahAcc > 0){
                tampilkanAksesoris(arr, i);
                cout << endl;
            }
            cout << endl;
        }
    }    
}

void hapus (kamera arr[], int& jml, int kapasitas){
    if (jml == 0){
        cout << "Belum ada data kamera" << endl;
    }else{
        lihat(arr, jml, kapasitas);
        int idx;
        cout << "Masukkan indeks yang ingin dihapus >> ";
        cin >> idx;
        if (idx > jml || idx <= 0){
            cout << "Indeks kamera tidak mencapai "<< idx<< endl;
        }else{
            for (int i = idx-1; i < jml; i++){
                arr[i] = arr[i+1];
            }
            jml--;
            cout << "Data kamera berhasil dihapus" << endl;
        }
    }
}

void edit (kamera arr[], int& jml, int kapasitas){
    if (jml == 0){
        cout << "Belum ada data kamera" << endl;
    }else{
        lihat(arr, jml, kapasitas);
        int idx;
        cout << "Masukkan indeks yang ingin diedit >> ";
        cin >> idx;
        if (idx > jml || idx <= 0){
            cout << "Indeks kamera tidak mencapai "<< idx<< endl;
        }else{
            cout << "Nama kamera\t: " << arr[idx-1].namaKamera << endl;
            cout << "Harga\t\t: " << arr[idx-1].harga << endl;
            if (arr[idx-1].jumlahAcc > 0){
                tampilkanAksesoris(arr, idx);
            }
            cout << "Masukkan nama kamera baru >> ";
            cin.ignore();
            getline(cin, arr[idx-1].namaKamera);
            cout << "Masukkan harga kamera baru >> ";
            getline(cin, arr[idx-1].harga);
            string edit;
            if (arr[idx-1].jumlahAcc > 0){
                cout << "Ingin edit aksesoris (y/t) >> ";
                cin >> edit;
                if (edit == "y"){
                    editAksesoris(arr, idx-1);
                }
            }
        }
    }

}    
void tampilan(kamera arr[], int& jml, int kapasitas){
    string ulang = "y";
    while (ulang == "y"){
        cout << menu();
        string pilih;
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        if (pilih == "1"){
            tambah(arr, jml, kapasitas);
        }else if (pilih == "2"){
            lihat(arr, jml, kapasitas);
        }else if(pilih == "3"){
            hapus(arr, jml, kapasitas);
        }else if(pilih == "4"){
            edit(arr, jml, kapasitas);
        }else if(pilih == "5"){
            ulang = "t";
        }else{
            cout << "Pilihan tidak tersedia" << endl;
        }
    }
}

int main(int argc, char const *argv[]){
    const int kapasitas = 10;
    kamera kmr[kapasitas];
    int jumlah = 0;

    tampilan(kmr, jumlah, kapasitas);

    return 0;
}