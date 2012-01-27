#include <iostream>
#include <windows.h>
using namespace std;


#define kolor 12

// plansza
const int wiersze = 8;  
const int kolumny = 8;

// pionki
const char czlowiek    = 'X';
const char computer = 'O';

/****************************************************************************/


void WyswietlTablice(const char tablica[][kolumny])
{
    cout << " ";
    for (int c = 0; c < kolumny; c++)
        cout << c;
    cout << endl;

    for (int r = 0; r < wiersze; r++)
    {
        cout << r;
        for (int c = 0; c < kolumny; c++)
            cout << tablica[r][c];
        cout << endl;
    }
}

/****************************************************************************/


int Mechanizm(char tablica[][kolumny], int wiersz, int kolumna, char zeton)
{
    int odwrocone_pionki = 0;

    if (tablica[wiersz][kolumna] != ' ')
        return 0;

    tablica[wiersz][kolumna] = zeton;

    char przeciwny_pionek;
    if (zeton == czlowiek)
        przeciwny_pionek = computer;
    else
        przeciwny_pionek = czlowiek;


    // czy mamy pionki w prawo aby odwrócic od podanej lokalizacji?
    int pionki_do_przewrocenia = -1;
    for (int c = kolumna + 1; c < kolumny && tablica[wiersz][c] != ' ' && pionki_do_przewrocenia == -1; c++)
    {
        if (tablica[wiersz][c] == zeton)
            pionki_do_przewrocenia = c;
    }
