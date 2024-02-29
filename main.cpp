#include <iostream>
using namespace std;


char jumlahHuruf = '0';
// variabel untuk menampung frekuensi kemunculan suatu huruf jika berurutan dan sama
char rep;
// variabel untuk menampung banyak perulangan ketika proses kompresi huruf

void printKonten (char arr[], int ukuranArr);
// prototype fungsi untuk menampilkan isi array
void kompresArray(char arr[], int ukuranArr);
// prototype fungsi untuk kompresi array

int main(){

    int ukuranArray;
    // variabel untuk menampung ukuran array yang diinputkan oleh user


        // proses input oleh user
        
    cout << "Masukkan banyak karakter yang ingin Anda inputkan: ";
    cin >> ukuranArray;
    // user memasukkan ukuran array yang diinginkan
    char huruf[ukuranArray];
    // deklarasi array dengan ukuran yang diinputkan oleh user

    for (int i = 0; i < ukuranArray; i++){
        cout << "Masukkan karakter: ";
        cin >> huruf[i];
        // user menginputkan karakter ke dalam array
    }
        // akhir dari proses input

    cout << "\n\nKarakter-Karakter yang Anda inputkan adalah: ";
    printKonten(huruf, ukuranArray);
    // menampilkan array yang diinputkan oleh user

    cout << "\nHasil kompresi dari karakter-karakter yang Anda inputkan adalah: ";
    kompresArray(huruf, ukuranArray);
    // menampilkan hasil kompresi dari array yang diinputkan oleh user

    return 0;
}


void printKonten (char arr[], int ukuranArr){
        cout << ukuranArr << ", [" ;
        for (int indeks = 0; indeks < ukuranArr; indeks++){
            if (indeks == ukuranArr-1){
                cout << "\"" << arr[indeks] << "\"";
                // output karakter terakhir pada array
            } else {
                cout << "\"" << arr[indeks] << "\", ";
                // output selain karakter terakhir pada array
            }
        }
        cout << "]" << endl;
}

void kompresArray(char arr[], int ukuranArr){
        // proses kompresi array
    for (int i = 0; i < ukuranArr; i++){
            // proses penghitungan frekuensi huruf jika berurutan dan sama
        for (int j = i; j < ukuranArr; j++){
            if (arr[i] == arr[j]){
                jumlahHuruf++;
            }
            if (arr[j+1] != arr[i]){
                break;
            }
        }
            // akhir dari proses penghitungan frekuensi

            // proses "penggabungan" karakter yang berurutan dan sama
        if (jumlahHuruf > '2'){
            rep = jumlahHuruf;
            while (rep > '2'){
                for (int k = i; k < ukuranArr; k++){
                        arr[k] = arr[k+1];
                }
                rep--;
                ukuranArr--;
            }
        }
            // akhir dari proses "penggabungan"

        if (jumlahHuruf > '1' && arr[i] == arr[i+1]){
            arr[i+1] = jumlahHuruf;
            // jika huruf yang berurutan dan sama sudah "digabungkan", 
            // ubah huruf kedua dari huruf yang berurutan dan sama menjadi frekuensi kemunculan huruf
        }

        jumlahHuruf = '0';
        // reset jumlah huruf untuk huruf selanjutnya pada array

    }
        // akhir dari proses kompresi array
    
    printKonten(arr, ukuranArr);
    // menampilkan hasil kompresi array
}
