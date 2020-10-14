#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int silnia(int a) {
    int wynik = 1;

    if(a != 0) {
        for(int i = 1; i<=a; i++){
            wynik *= i;
        }
    }

    return wynik;
}

int main() {
    ifstream f_wej("liczby.txt");
    ofstream f_wyj("4-2.txt");

    string obecna_liczba;
    
    for(int i=0; i<500; i++) {
        f_wej >> obecna_liczba;

        int suma = 0;

        for(int i=0; i<obecna_liczba.size(); i++ ) {
            string obecna_cyfra = "";
            obecna_cyfra += obecna_liczba[i];
            suma += silnia( stoi(obecna_cyfra) );
        }

        if( stoi(obecna_liczba) == suma ) {
            f_wyj << obecna_liczba << endl;
        }
    }

    return 0;
}