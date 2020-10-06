#include <fstream>
#include <string>

using namespace std;

bool is_prime(int x) {
    bool pierwsza=true;

    if(x >= 2) {
        for(int i=2; i<x; i++) {
            if (x%i==0 ){
                pierwsza = false;
            }
        }
    }

    return pierwsza;
}

int main() {
    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("pary.txt", ios::in);
    wyjscie.open("wyniki_4-1.txt", ios::out);

    for(int i=0; i<100; i++) {
    	int liczba;
        string garbage;
        wejscie >> liczba >> garbage;

        // parzysta
        if(liczba%2 == 0) {
            wyjscie << liczba << " ";
            for(int j=2; j<=liczba; j++) {
            	if( is_prime(j) && is_prime(liczba-j) ) {
	                wyjscie << j << " " << liczba-j;
	                break;
            	}
        	}
            wyjscie << "\n";
        }
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}
