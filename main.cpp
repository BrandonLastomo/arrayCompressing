#include <iostream>
using namespace std;

int main(){

    int ukuranArray = 1;
    char huruf[ukuranArray] = {'a'};
    char jumlahHuruf = '0';
    char rep;

    
        for (int i = 0; i < ukuranArray; i++){
            for (int j = 0; j < ukuranArray; j++){
                if (huruf[i] == huruf[j]){
                    jumlahHuruf++;
                }
            }

            // cout << "jumlah huruf " << huruf[i] << ": " << jumlahHuruf << endl; 

            if (jumlahHuruf > '2'){
                rep = jumlahHuruf;
                while (rep > '2'){
                    for (int k = i; k < ukuranArray; k++){
                            huruf[k] = huruf[k+1];
                    }
                    
                    rep--;
                    ukuranArray--;

                }
                
            }

            if (jumlahHuruf > '1' && huruf[i] == huruf[i+1]){
                huruf[i+1] = jumlahHuruf;
            }

            jumlahHuruf = '0';
        }

        cout << ukuranArray << ", [" ;
        for (int arr = 0; arr < ukuranArray; arr++){
            if (arr == ukuranArray-1){
                cout << "\"" << huruf[arr] << "\"";
            } else {
                cout << "\"" << huruf[arr] << "\", ";
            }
        }
        cout << "]" << endl;
        

    
    // cout << "\n\n===Test Section===\n\n";

    // for (int a = 0; a < ukuranArray; a++){
    //     cout << huruf[a] << endl;
    // }

    // cout << "\n\n===size Section===\n\n";
    
    // cout << ukuranArray << endl;
    // cout << jumlahHuruf;




    return 0;
}