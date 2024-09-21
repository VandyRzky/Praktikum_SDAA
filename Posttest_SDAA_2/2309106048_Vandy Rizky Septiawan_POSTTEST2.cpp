#include <iostream>

using namespace std;

struct kamera{
    string namaKamera;
    string harga;
};

string menu(){
    return "1. Tambah \n"
	"2. Tampilkan \n"
	"3. Hapus \n"
	"4. Edit \n"
	"5. Keluar\n";
}

void tambah(kamera arr[], int& jml, int kapasitas){
    if (jml == kapasitas){
        cout << "Tidak dapat menambahkan data kamera" << endl;
    }else{
        cout << "Masukkan nama kamera >> ";
        getline(cin, arr[jml].namaKamera);
        cout << "Masukkan harga >> ";
        getline(cin, arr[jml].harga);
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
        if (idx > jml){
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

void edit (kamera arr[], int& jml, int kapasitas){ //belum jadi
    if (jml == 0){
        cout << "Belum ada data kamera" << endl;
    }else{
        lihat(arr, jml, kapasitas);
        int idx;
        cout << "Masukkan indeks yang ingin diedit >> ";
        cin >> idx;
        if (idx > jml){
            cout << "Indeks kamera tidak mencapai "<< idx<< endl;
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
            cin.ignore();
            tambah(arr, jml, kapasitas);
        }else if (pilih == "2"){
            lihat(arr, jml, kapasitas);
        }else if(pilih == "3"){
            hapus(arr, jml, kapasitas);
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
