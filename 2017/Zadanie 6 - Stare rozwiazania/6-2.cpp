#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream wej("dane.txt");
    ofstream wyj("6-2.txt");

    int obraz[200][320];
    int left_val, right_val, licznik=0;

    for(int h = 0; h < 200; h++){
        for(int w = 0; w < 320; w++){
            wej >> obraz[h][w];
        }
    }

    for(int h = 0; h < 200; h++){
        for(int w = 0; w < 320; w++){
            if(obraz[h][w]!=obraz[h][319-w]){
                licznik++;
                break;
            }
        }
    }

    cout << licznik << endl;
    wyj << licznik << endl;
    getchar();
    getchar();
    return 0;
}