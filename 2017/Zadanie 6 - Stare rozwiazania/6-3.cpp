#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream wej("dane.txt");
    ofstream wyj("6-3.txt");

    int obraz[200][320];
    int left_val, right_val, licznik=0;

    for(int h = 0; h < 200; h++){
        for(int w = 0; w < 320; w++){
            wej >> obraz[h][w];
        }
    }

    // Narożniki
    if(
        abs(obraz[0][0]-obraz[0][1]) > 128 ||   // LG
        abs(obraz[0][0]-obraz[1][0]) > 128
    ) licznik++;
    if(
        abs(obraz[0][319]-obraz[0][318]) > 128 ||   // PG
        abs(obraz[0][319]-obraz[1][319]) > 128
    ) licznik++;
    if(
        abs(obraz[199][0]-obraz[198][0]) > 128 ||   // LD
        abs(obraz[199][0]-obraz[199][1]) > 128
    ) licznik++;
    if(
        abs(obraz[199][319]-obraz[198][319]) > 128 ||   // PD
        abs(obraz[199][319]-obraz[199][318]) > 128
    ) licznik++;

    for(int h = 1; h < 200-1; h++){
        for(int w = 1; w < 320-1; w++){
            if(
                abs(obraz[h][w-1]-obraz[h][w]) > 128 ||
                abs(obraz[h][w+1]-obraz[h][w]) > 128 ||
                abs(obraz[h-1][w]-obraz[h][w]) > 128 ||
                abs(obraz[h+1][w]-obraz[h][w]) > 128
            ) licznik++;
        }
    }

    // Boki
    for(int h = 1; h < 200-1; h++){
        if(
                abs(obraz[h-1][0]-obraz[h][0]) > 128 ||
                abs(obraz[h][1]-obraz[h][0]) > 128 ||
                abs(obraz[h+1][0]-obraz[h][0]) > 128
        ) licznik++;
        if(
                abs(obraz[h-1][319]-obraz[h][319]) > 128 ||
                abs(obraz[h][318]-obraz[h][319]) > 128 ||
                abs(obraz[h+1][319]-obraz[h][319]) > 128
        ) licznik++;
    }

    // Góra i dół
    for(int w = 1; w < 320-1; w++){
        if(
                abs(obraz[0][w-1]-obraz[0][w]) > 128 ||
                abs(obraz[1][w]-obraz[0][w]) > 128 ||
                abs(obraz[0][w+1]-obraz[0][w]) > 128
        ) licznik++;
        if(
                abs(obraz[199][w-1]-obraz[199][w]) > 128 ||
                abs(obraz[198][w]-obraz[199][w]) > 128 ||
                abs(obraz[199][w+1]-obraz[199][w]) > 128
        ) licznik++;
    }
        

    cout << licznik << endl;
    wyj << licznik << endl;
    getchar();
    getchar();
    return 0;
}