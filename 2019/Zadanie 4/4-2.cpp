#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int silnia(int przyjetaLiczba)
{
    int wynik = 1;

    for(int i=1; i<=przyjetaLiczba; i++)
        wynik *= i;

    return wynik;
}

int sumaSilniCyfr(int przyjetaLiczba)
{
    int suma = 0;
    string znakiLiczby = to_string(przyjetaLiczba);

    for(int i=0; i<znakiLiczby.size(); i++)
    {
        suma += silnia(znakiLiczby[i] - '0');
    }

    return suma;
}

int main()
{
    ifstream sourceFile("liczby.txt");
    vector<int> liczbyRowneSumieSilni;
    
    for(int i=0; i<500; i++)
    {
        int obecnaLiczba;
        sourceFile >> obecnaLiczba;
        
        if( obecnaLiczba == sumaSilniCyfr(obecnaLiczba) )
            liczbyRowneSumieSilni.push_back(obecnaLiczba);
    }

    for(int i=0; i<liczbyRowneSumieSilni.size(); i++)
        cout << liczbyRowneSumieSilni[i] << " ";

    return 0;
}