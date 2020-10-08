#include <iostream>
#include <fstream>
#include <math.h>
#include <limits.h>

using namespace std;

int main() {
    ifstream f_wej("dane4.txt");
    //ofstream f_wyj("4-1.txt");

    int max_luka=0, min_luka=INT_MAX, obecna_liczba, poprzednia_liczba;

    f_wej >> obecna_liczba;

    for(int i=1; i<1000; i++) {
        poprzednia_liczba = obecna_liczba;
        f_wej >> obecna_liczba;

        if( abs(obecna_liczba - poprzednia_liczba) < min_luka )
            min_luka = abs(obecna_liczba - poprzednia_liczba);

        if( abs(obecna_liczba - poprzednia_liczba) > max_luka )
            max_luka = abs(obecna_liczba - poprzednia_liczba);
    }
    cout << "Najwieksza: " << max_luka << endl;
    cout << "Najmniejsza: " << min_luka << endl;

    getchar();
    return 0;
}