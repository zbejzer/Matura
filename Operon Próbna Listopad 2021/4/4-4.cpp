#include <iostream>
#include <fstream>
#include <array>
#include <set>
#include <vector>

using namespace std;

bool czy_pierwsza(int liczba)
{
	bool pierwszosc = true;
	
	if( liczba == 0 || liczba == 1 )
		pierwszosc = false;
	
	for(int i=2; i<liczba && pierwszosc; i++)
		if((liczba%i) == 0)
			pierwszosc = false;
			
	return pierwszosc;
}

int suma_kwadratow( int liczba )
{
    int suma = 0;
    
	while( liczba > 0)
	{
		int liczba_jednosci = liczba%10;
		suma += liczba_jednosci * liczba_jednosci;
		liczba /= 10;
	}
	
	return suma;
}

bool czy_wesola(int liczba)
{
	set <int> policzone_liczby;
	policzone_liczby.insert(liczba);
	int policzona_liczba = suma_kwadratow(liczba);
	
	do{
		policzone_liczby.insert(policzona_liczba);
		policzona_liczba = suma_kwadratow(policzona_liczba);
	}while( policzone_liczby.count(policzona_liczba)<1 && policzona_liczba != 1 );
	
	policzone_liczby.insert(policzona_liczba);
	
	if(policzona_liczba == 1)
		return true;
	else
		return false;
}

int main()
{
    ifstream wejscie("liczby.txt");
    int liczby_wesole = 0;

    for(int i=0; i<2001; i++)
    {
    	int wczytana_liczba;
    	wejscie >> wczytana_liczba;
    	
        if( czy_wesola(wczytana_liczba) && czy_pierwsza(wczytana_liczba) )
			liczby_wesole++;
    }
    
	cout << liczby_wesole << endl;

	system("pause");

    return 0;
}
