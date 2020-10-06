#include <fstream>
#include <iostream>
#include <string>
#include <utility>  
#include <algorithm>
#include <vector>

using namespace std;

bool test(pair <int, string> a, pair <int, string> b) {
    bool warunek = false;
    
    if(a.first < b.first) {
        warunek = true;
    } else {
        if(a.first == b.first) {
            for(int i=0; i<min(a.second.size(), b.second.size()); i++){
                if((int)a.second[i] < (int)b.second[i]){
                    warunek = true;
                    break;
                }
            }
        }
    }

    return !warunek;
}

int main() {
    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("pary.txt", ios::in);
    wyjscie.open("wyniki_4-3.txt", ios::out);

    vector <pair <int, string>> dane;

    for(int i=0; i<100; i++) {
        int liczba;
        string znaki;

        wejscie >> liczba >> znaki;

        if(znaki.size() == liczba) {
            dane.push_back( make_pair(liczba, znaki) );
        }
    }

    sort(dane.begin(), dane.end(), test);

    wyjscie << dane[dane.size()-1].first << " " << dane[dane.size()-1].second << endl;

    wejscie.close();
    wyjscie.close();

    return 0;
}
