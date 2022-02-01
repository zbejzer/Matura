#include <iostream>
#include <fstream>
#include <array>
#include <set>
#include <vector>

using namespace std;

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

int dlugosc_cyklu(int liczba)
{
	set <int> policzone_liczby;
	policzone_liczby.insert(liczba);
	int policzona_liczba = suma_kwadratow(liczba);
	
	do{
		policzone_liczby.insert(policzona_liczba);
		policzona_liczba = suma_kwadratow(policzona_liczba);
	}while( policzone_liczby.count(policzona_liczba)<1 && policzona_liczba != 1 );
	
	policzone_liczby.insert(policzona_liczba);
	
	return policzone_liczby.size();
}

int main()
{
	array <int, 1000> wczytane_liczby;
    array <bool, 1000> wesolosc;
    array <int, 1000> dlugosc_ciagu;
    vector <int> najdluzsze_wesole;
    int najwieksza_dlugosc = 0;

    for(int i=0; i<1000; i++)
    {
        wczytane_liczby[i] = i;
        wesolosc[i] = czy_wesola(wczytane_liczby[i]);
		dlugosc_ciagu[i] = dlugosc_cyklu(wczytane_liczby[i]);
    }
    
    for(int i=0; i<1000; i++)
    {
        if(wesolosc[i])
        {
        	if(dlugosc_ciagu[i] > najwieksza_dlugosc)
        	{
        		najwieksza_dlugosc = dlugosc_ciagu[i];
        		najdluzsze_wesole.clear();
        		najdluzsze_wesole.push_back(wczytane_liczby[i]);
			} else if(dlugosc_ciagu[i] == najwieksza_dlugosc)
        		najdluzsze_wesole.push_back(wczytane_liczby[i]);
		}
    }

	cout << najwieksza_dlugosc << endl;
	
	for(int i=0; i<najdluzsze_wesole.size(); i++)
		cout << najdluzsze_wesole[i] << " ";
		
	cout << endl;

	system("pause");

    return 0;
}
