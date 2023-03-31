#include <iostream>
#include <string>

#include "Harmonogram.h"
#include "Czas.h"


Harmonogram::Harmonogram()
{
    tab_czas = nullptr; //nullptr to po prostu pusty wska�nik, mo�na nim zerowa� wska�niki
    rozmiar = 0;
    // tab_czas = new Czas[rozmiar]; // alokacja pami�ci dla TABLICY element�w klasy Czas
                             // (szeroko�� mo�e byc zmienn�)
}

Harmonogram::~Harmonogram()
{
    delete[] tab_czas;            // zwolnienie TABLICY element�w pod wska�nikiem
}

Harmonogram::Harmonogram(const Harmonogram& poprzedni) //Konstruktor kopiuj�cy
{
    // Konstruktor przenosi warto�ci wcze�niejszego konstruktora do tego nowo utworzonego

    rozmiar = poprzedni.rozmiar;
    tab_czas = new Czas[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        *(tab_czas + i) = *(poprzedni.tab_czas + i);
       
    }
}

Harmonogram& Harmonogram::operator=(const Harmonogram& doprzypisania) //Operator przypisania
{
    if (&doprzypisania == this) return *this; // Przypisanie do samego siebie mo�e powodowa� b��dy
    delete[] tab_czas;

    rozmiar = doprzypisania.rozmiar;

    tab_czas = new Czas[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        *(tab_czas + i) = *(doprzypisania.tab_czas + i);
    }


    return *this;
}

void Harmonogram::wprowadz_czas(Czas& nowy)
{
    Czas* nowy_czas_tab;
    rozmiar++;

    nowy_czas_tab = new Czas[rozmiar];

    for (int i = 0; i < rozmiar - 1; i++)
    {
        *(nowy_czas_tab + i) = *(tab_czas + i);
    }

 
    *(nowy_czas_tab + (rozmiar - 1)) = nowy;

    delete[] tab_czas;

    tab_czas = nowy_czas_tab;
}

int Harmonogram::ile_czasow()
{
    return rozmiar;
}

Czas Harmonogram::daj_czas(int ktory)
{
    if (ktory >= rozmiar - 1)
    {
        std::cout << "Nie ma takiego czasu!" << std::endl;
        return NULL;
    }

    return *(tab_czas + ktory);
}

Czas Harmonogram::zsumuj_czasy()
{
    Czas suma;

    for (int i = 0; i < rozmiar; i++)
    {
        suma.sumowanie_dla_przedzialu(*(tab_czas +i));
    }

    return suma;
}

void Harmonogram::wyswietl_cale_zestawienie(int jak)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "[" << i << "] -> ";
        tab_czas[i].wyswietl_czas_smg(jak);
    }

}

Harmonogram Harmonogram::kopia_zapasowa(int n)
{
    Harmonogram n_czasow;
   
    n_czasow.wyswietl_cale_zestawienie(3);

    if (n > rozmiar)
    {
       
        n_czasow.rozmiar = rozmiar; //Je�li ilo�� czas�w do skopiowania b�dzie wi�ksza ni� ilo�� zapisanych czas�w to kod skopiuje wszystkie zapisane
    }
    else
    {
        n_czasow.rozmiar = n;
    }

    n_czasow.tab_czas = new Czas[n_czasow.rozmiar];

    for (int i = 0; i < n_czasow.rozmiar; i++)
        n_czasow.tab_czas[i] = tab_czas[i];

    return n_czasow;
}

Harmonogram Harmonogram::przedzial(int h, int m, int s)
{
    Czas zakres(h, m, s);
    Harmonogram przedzial_czasow;
    Czas suma_czasow;
    int i = 0;

    zakres.wyswietl_czas_smg(3);

    suma_czasow.sumowanie_dla_przedzialu(tab_czas[i]);

    while (suma_czasow < zakres || suma_czasow == zakres)
    {
        if (i > (rozmiar -1))
            break;
        przedzial_czasow.wprowadz_czas(tab_czas[i]);
        i++;
        suma_czasow.sumowanie_dla_przedzialu(tab_czas[i]);
        suma_czasow.wyswietl_czas_smg(3);
    }

    return przedzial_czasow;
}

void Harmonogram::zwieksz_o(int oile, int jaki)
{
    *(tab_czas + jaki) += oile;
}