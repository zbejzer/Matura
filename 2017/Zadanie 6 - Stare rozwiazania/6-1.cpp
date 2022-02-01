#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream wej("dane.txt");
    ofstream wyj("6-1.txt");

    int max_val = 0, min_val = 255;

    for(int h = 0; h < 200; h++){
        for(int w = 0; w < 320; w++){
            int liczba;
            wej >> liczba;

            if(liczba > max_val)
                max_val = liczba;
            if(liczba < min_val)
                min_val = liczba;
        }
    }

    cout << max_val << endl;
    wyj << max_val << endl;
    cout << min_val << endl;
    wyj << min_val << endl;

    getchar();
    getchar();
    return 0;
}