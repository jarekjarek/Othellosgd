#include <iostream>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
using namespace std;


#define kolor 12

// planszas
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


    // upewniamy sie ze nasz pionek jest co najmiej dwa pola dalej aby odwrócic przeciwnika
    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia > kolumna + 1)
    {

        //odwrócenie w prawo pionków przewiwnika
        for (int c = kolumna + 1; c < pionki_do_przewrocenia; c++)
        {
            tablica[wiersz][c] = zeton;
            odwrocone_pionki++;
        }
    }


    // czy mamy pionki w lewo aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    for (int c = kolumna - 1; c >= 0 && tablica[wiersz][c] != ' ' && pionki_do_przewrocenia == -1; c--)
    {
        if (tablica[wiersz][c] == zeton)
            pionki_do_przewrocenia = c;
    }




    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia < kolumna - 1)
    {

        for (int c = kolumna - 1; c > pionki_do_przewrocenia; c--)
        {
            tablica[wiersz][c] = zeton;
            odwrocone_pionki++;
        }
    }


     //czy mamy pionki w góre aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    for (int r = wiersz - 1; r >= 0 && tablica[r][kolumna] != ' ' && pionki_do_przewrocenia == -1; r--)
    {
        if (tablica[r][kolumna] == zeton)
            pionki_do_przewrocenia = r;
    }

    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia < wiersz - 1)
    {

        for (int r = wiersz - 1; r > pionki_do_przewrocenia; r--)
        {
            tablica[r][kolumna] = zeton;
            odwrocone_pionki++;
        }
    }


    // //czy mamy pionki w dó³ aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    for (int r = wiersz + 1; r < wiersze && tablica[r][kolumna] != ' ' && pionki_do_przewrocenia == -1; r++)
    {
        if (tablica[r][kolumna] == zeton)
            pionki_do_przewrocenia = r;
    }


    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia > wiersz + 1)
    {

        for (int r = wiersz + 1; r < pionki_do_przewrocenia; r++)
        {
            tablica[r][kolumna] = zeton;
            odwrocone_pionki++;
        }
    }


     //czy mamy pionki w góre-lewo aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    int c = kolumna - 1;
    for (int r = wiersz - 1; c >= 0 && r >= 0 && tablica[r][c] != ' ' && pionki_do_przewrocenia == -1; r--)
    {
        if (tablica[r][c] == zeton)
            pionki_do_przewrocenia = r;
        c--;
    }


    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia < wiersz - 1)
    {
        c = kolumna - 1;
        for (int r = wiersz - 1; r > pionki_do_przewrocenia; r--)
        {
            tablica[r][c] = zeton;
            odwrocone_pionki++;
            c--;
        }
    }


     //czy mamy pionki w góre-prawo aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    c = kolumna + 1;
    for (int r = wiersz - 1; c < kolumny && r >= 0 && tablica[r][c] != ' ' && pionki_do_przewrocenia == -1; r--)
    {
        if (tablica[r][c] == zeton)
            pionki_do_przewrocenia = r;
        c++;
    }


    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia < wiersz - 1)
    {
        c = kolumna + 1;
        for (int r = wiersz - 1; r > pionki_do_przewrocenia; r--)
        {
            tablica[r][c] = zeton;
            odwrocone_pionki++;
            c++;
        }
    }


     //czy mamy pionki w dó³-lewo aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    c = kolumna - 1;
    for (int r = wiersz + 1; c >= 0 && r < wiersze && tablica[r][c] != ' ' && pionki_do_przewrocenia == -1; r++)
    {
        if (tablica[r][c] == zeton)
            pionki_do_przewrocenia = r;
        c--;
    }


    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia > wiersz + 1)
    {
        c = kolumna - 1;
        for (int r = wiersz + 1; r < pionki_do_przewrocenia; r++)
        {
            tablica[r][c] = zeton;
            odwrocone_pionki++;
            c--;
        }
    }


     //czy mamy pionki w dó³-prawo aby odwrócic od podanej lokalizacji?
    pionki_do_przewrocenia = -1;
    c = kolumna + 1;
    for (int r = wiersz + 1; c < kolumny && r < wiersze && tablica[r][c] != ' ' && pionki_do_przewrocenia == -1; r++)
    {
        if (tablica[r][c] == zeton)
            pionki_do_przewrocenia = r;
        c++;
    }


    if (pionki_do_przewrocenia != -1 && pionki_do_przewrocenia > wiersz + 1)
    {
        c = kolumna + 1;
        for (int r = wiersz + 1; r < pionki_do_przewrocenia; r++)
        {
            tablica[r][c] = zeton;
            odwrocone_pionki++;
            c++;
        }
    }

    // Jesli zadnych pionkow nie da sie przewrocic jest to nielegalny ruch
    if (odwrocone_pionki == 0)
        tablica[wiersz][kolumna] = ' ';

    return odwrocone_pionki;
}
/****************************************************************************/


// Sprawdza czy mozna zrobic wazny ruch
int Czy_ruch_jest_mozliwy(const char tablica[][kolumny], char player)
{
    return 1;
}

/**********************************
