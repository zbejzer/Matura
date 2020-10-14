#include<iostream>
#include<fstream>

using namespace std;

bool is_pow_3(int a)
{
    bool warunek = false;

    for(int i=1; i<=a; i*=3) {
        if(i == a) {
            warunek = true;
        }
    }

    return warunek;
}

int main() {
    ifstream f_wej("liczby.txt");
    ofstream f_wyj("4-1.txt");

    int obecna_liczba, n_pow3 = 0;
    
    for(int i=0; i<500; i++) {
        f_wej >> obecna_liczba;
        if( is_pow_3(obecna_liczba) ) {
            n_pow3++;    
        }
    }

    f_wyj << n_pow3;

    return 0;
}