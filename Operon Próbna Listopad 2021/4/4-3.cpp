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

int main()
{
    ifstream wejscie("liczby.txt");
    int liczby_wesole = 0, dlugosc_ciagu = 0, najdluszszy_ciag = 0, pierwszy_wyraz, ostatni_wyraz; 
    
    array<int, 2001> wczytane_liczby;
    array<bool, 2001> szczesliwosc_liczb;

    for(int i=0; i<2001; i++)
    {
    	wejscie >> wczytane_liczby[i];
    	szczesliwosc_liczb[i] = czy_wesola(wczytane_liczby[i]);
    }
    	
    for(int i=0; i<2001; i++)
    {
    	if(szczesliwosc_liczb[i])
    	{
    		dlugosc_ciagu++;
    		if(dlugosc_ciagu > najdluszszy_ciag)
    		{
    			najdluszszy_ciag = dlugosc_ciagu;
    			ostatni_wyraz = wczytane_liczby[i];
    			pierwszy_wyraz = wczytane_liczby[i+1-dlugosc_ciagu]; 
			}
		}
		else 
			dlugosc_ciagu = 0;
	}
	
	cout << najdluszszy_ciag << " " << pierwszy_wyraz << " " << ostatni_wyraz << endl;
	
	system("pause");

    return 0;
}
