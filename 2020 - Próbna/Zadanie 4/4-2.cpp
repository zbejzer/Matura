#include <iostream>
#include <fstream>
#include <math.h>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("4-2.txt");

    int poprzednia_luka, obecna_luka = 0, obecna_liczba, poprzednia_liczba;
    vector <int> ciag;
    vector <int> max_ciag;

    f_wej >> obecna_liczba;
    ciag.push_back(obecna_liczba);

    for(int i=1; i<1000; i++) {
        poprzednia_liczba = obecna_liczba;
        poprzednia_luka = obecna_luka;
        
        f_wej >> obecna_liczba;

        obecna_luka = abs(obecna_liczba - poprzednia_liczba);

        if(obecna_luka == poprzednia_luka) {
            ciag.push_back(obecna_liczba);
        }

        if(ciag.size() > max_ciag.size()) {
            max_ciag = ciag;
        }

        if(obecna_luka != poprzednia_luka) {
            ciag.clear();
            ciag.push_back(poprzednia_liczba);
            ciag.push_back(obecna_liczba);
        }
        
    }
    f_wyj << "Dlugosc: " << max_ciag.size() << endl;
    f_wyj << "Poczatek: " << max_ciag[0] << endl;
    f_wyj << "Koniec: " << max_ciag[max_ciag.size()-1] << endl;
    
    return 0;
}