#include <iostream>
using namespace std;


char jumlahHuruf = '0';
char rep;

void printKonten (char arr[], int ukuranArr){
        cout << ukuranArr << ", [" ;
        for (int indeks = 0; indeks < ukuranArr; indeks++){
            if (indeks == ukuranArr-1){
                cout << "\"" << arr[indeks] << "\"";
            } else {
                cout << "\"" << arr[indeks] << "\", ";
            }
        }
        cout << "]" << endl;
}

void kompressArray(char arr[], int ukuranArr){
    
    for (int i = 0; i < ukuranArr; i++){
        for (int j = 0; j < ukuranArr; j++){
            if (arr[i] == arr[j]){
                jumlahHuruf++;
            }
        }

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

        if (jumlahHuruf > '1' && arr[i] == arr[i+1]){
            arr[i+1] = jumlahHuruf;
        }

        jumlahHuruf = '0';

    }

    
    printKonten(arr, ukuranArr);

}

int main(){

    int ukuranArray;

    cout << "Masukkan banyak karakter yang ingin Anda inputkan: ";
    cin >> ukuranArray;
    char huruf[ukuranArray];

    for (int i = 0; i < ukuranArray; i++){
        cout << "Masukkan karakter: ";
        cin >> huruf[i];
    }

    cout << "\n\nKarakter-Karakter yang Anda inputkan adalah: ";
    printKonten(huruf, ukuranArray);

    cout << "\nHasil kompres dari karakter-karakter yang Anda inputkan adalah: ";
    kompressArray(huruf, ukuranArray);
        
    return 0;
}