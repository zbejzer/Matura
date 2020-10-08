#include <iostream>
#include <fstream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("4-3.txt");

    int obecna_liczba, poprzednia_liczba, max_krotnosc = 0;
    vector <int> luki;
    vector <int> luki_max_krotnosci;

    f_wej >> obecna_liczba;

    for(int i=1; i<1000; i++) {
        poprzednia_liczba = obecna_liczba;

        f_wej >> obecna_liczba;

        luki.push_back( abs(obecna_liczba - poprzednia_liczba) );
    }

    for(int i=0; i<luki.size(); i++){
        int krotnosc = count(luki.begin(), luki.end(), luki[i]);
        if( count(luki_max_krotnosci.begin(), luki_max_krotnosci.end(), luki[i]) == 0 ){
            if( krotnosc == max_krotnosc ) {
                luki_max_krotnosci.push_back( luki[i] );
            }
            if( krotnosc > max_krotnosc ) {
                max_krotnosc = krotnosc;
                luki_max_krotnosci.clear();
                luki_max_krotnosci.push_back( luki[i] );
            }
        }
    }

    f_wyj << "Max krotnosc: " << max_krotnosc << endl;
    for(int i=0; i<luki_max_krotnosci.size(); i++) {
        f_wyj << luki_max_krotnosci[i] << endl;
    }

    return 0;
}