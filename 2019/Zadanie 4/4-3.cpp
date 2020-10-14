#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int NWD(int a, int b) {
    int wynik;

    for(int i=1; i<=min(a, b); i++){
        if(a%i == 0 && b%i == 0) {
            wynik = i;
        }
    }

    return wynik;
}

int main() {
    ifstream f_wej("liczby.txt");
    ofstream f_wyj("4-3.txt");

    int obecna_liczba, poprzednia_liczba;
    int obecne_NWD, poprzednie_NWD, naj_NWD;

    vector <int> ciag;
    vector <int> naj_ciag;

    f_wej >> poprzednia_liczba;
    f_wej >> obecna_liczba;
    obecne_NWD = NWD(poprzednia_liczba, obecna_liczba);

    if( obecne_NWD > 1 ){
        ciag.push_back(poprzednia_liczba);
        ciag.push_back(obecna_liczba);
    } else {
        ciag.push_back(obecna_liczba);
        obecne_NWD = obecna_liczba;
    }

    if( ciag.size() > naj_ciag.size() ) {
            naj_ciag = ciag;
    }
    
    for(int i=2; i<500; i++) {
        poprzednia_liczba = obecna_liczba;
        poprzednie_NWD = obecne_NWD;

        f_wej >> obecna_liczba;

        obecne_NWD = NWD(poprzednie_NWD, obecna_liczba);

        if(obecne_NWD > 1) {
            ciag.push_back(obecna_liczba);
        } 

        if( ciag.size() > naj_ciag.size() ) {
            naj_NWD = obecne_NWD;
            naj_ciag = ciag;
        }

        if(obecne_NWD <= 1) {
            ciag.clear();
            obecne_NWD = obecna_liczba;

            if(poprzednie_NWD > 1) {
                ciag.push_back(poprzednia_liczba);
            }

            ciag.push_back(obecna_liczba);
        }
    }

    f_wyj << naj_ciag[0] << endl;
    f_wyj << naj_ciag.size() << endl;
    f_wyj << naj_NWD << endl;

    return 0;
}