#include <iostream>

using namespace std;

int pascal (int baris, int kolom){
    if(kolom == 0 || kolom == baris){
        return 1;
    }else{
        return pascal(baris-1, kolom-1) + pascal(baris-1, kolom);
    }
}

int main(int argc, char const *argv[]){
    int baris, kolom;
    for(baris = 0; baris <3; baris++){
        for(kolom = 0; kolom <= baris; kolom++){
            cout << pascal(baris, kolom) << " ";
        }
        cout << endl;
    }
    return 0;
}