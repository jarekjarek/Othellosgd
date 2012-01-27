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

