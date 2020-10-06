#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream wejscie;
    ofstream wyjscie;
    wejscie.open("pary.txt", ios::in);
    wyjscie.open("wyniki_4-2.txt", ios::out);

    for(int i=0; i<100; i++) {
    	int garbage, powtorzenia=1, max_p=0;
        string linijka, ciag="", max="";
        wejscie >> garbage >> linijka;

        ciag += linijka[0];

        for(int c=1; c < linijka.size(); c++) {
            if( linijka[c] == linijka[c-1] ){
                ciag += linijka[c];
                powtorzenia++;
            }
            if( powtorzenia>max_p ){
                max = ciag;
                max_p = powtorzenia;
            }
            if( linijka[c] != linijka[c-1] ){
                ciag = "";
                ciag += linijka[c];
                powtorzenia = 1;
            }
        }

        wyjscie << max << " " << max_p << endl;
    }

    wejscie.close();
    wyjscie.close();

    return 0;
}
