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


 */



void Czlowiek(char tablica[][kolumny])
{
    int wiersz, kolumna;
    bool nielegalny_ruch;


    if (Czy_ruch_jest_mozliwy(tablica, czlowiek))
    {
        do
        {
            nielegalny_ruch = false;

            cout << "wiersz? ";
            cin >> wiersz;
            while (wiersz < 0 || wiersz >= wiersze)
            {
                cout << "Wybierz wiersz od 0 do " << (wiersze - 1) << ".\n";
                cout << "wiersz? ";
                cin >> wiersz;
            }

            cout << "kolumna? ";
            cin >> kolumna;
            while (kolumna < 0 || kolumna >= kolumny)
            {
                cout << "Wybierz kolumne od 0 do " << (kolumny - 1) << ".\n";
                cout << "kolumna? ";
                cin >> kolumna;
            }

            if (tablica[wiersz][kolumna] != ' ')// sprawdza czy pole jest puste
            {
                cout << "Podaj puste pole na planszy.\n";
                nielegalny_ruch = 1;
            }
            else
            {
                int odwocone_pionki = Mechanizm(tablica, wiersz, kolumna, czlowiek);
                if (odwocone_pionki == 0)
                {
                    cout << "nielegalny ruch\n";
                    nielegalny_ruch = true;
                }
                else if (odwocone_pionki == 1)
                    cout << "odwrocony 1 pionek.\n\n";
                else
                    cout << "odwrocone " << odwocone_pionki << " pionki.\n\n";
            }
        } while (nielegalny_ruch);
    }
    else
    {
        cout << "nie mozesz sie ruszac.\n";
    }
}

void ZapiszTablice(char tablica[][kolumny], char tym_tablica[][kolumny])
{

    for( int i = 0; i < wiersze; i++)
    {
        for(int j =0; j < kolumny; j++)
            tym_tablica[i][j]= tablica[i][j];
    }
}





void Computer(char tablica[][kolumny])
{
    char tym_tablica[wiersze][kolumny];
    int odwrocone_pionki[wiersze][kolumny];
    int pionki;
    int temp = 0;
    int i,j;

    ZapiszTablice(tablica,tym_tablica);

    pionki=0;
    srand((int)time(0));

    while (pionki == 0){

        i=rand()%8;
        j=rand()%8;
        if(tablica[i][j] != 'X' ||tablica[i][j] !='O' )
            {
                pionki = Mechanizm(tablica,i,j,'O');


            }
    }



}


void main()
{

    //Run these two lines first
    HANDLE hcolor;
    hcolor = GetStdHandle (STD_OUTPUT_HANDLE);
    char tablica[wiersze][kolumny];

    //Use this function to set your colors
    SetConsoleTextAttribute(hcolor, kolor);


    for(int i=0;i<8;i++)for(int j=0;j<8;j++)tablica[j][i]=' ';
    tablica[3][3]='O';
    tablica[3][4]='X';
    tablica[4][3]='X';
    tablica[4][4]='O';


    int b=0;
    WyswietlTablice(tablica);
    while(b<10)
    {
    cout << endl;

    Czlowiek(tablica);
    WyswietlTablice(tablica);
    Computer(tablica);
    WyswietlTablice(tablica);
    b++;
    }


    system("Pause");
}
