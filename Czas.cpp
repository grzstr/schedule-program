#include <iostream>
#include <string>

#include "Czas.h"

void Czas::wyswietl_czas_smg(int jak)
{
    if (jak == 0) //sek min godz
    {
        std::cout << sek << "," << min << "," << godz << std::endl;
    }
    else if (jak == 1) // sek min
    {
        std::cout << sek << "," << min << std::endl;
    }
    else if (jak == 2) // sek
    {
        std::cout << sek << std::endl;
    }
    else if (jak == 3) //Wyswietlanie czasu godz:min:sek
    {
        wyswietl_czas();
    }

}

void Czas::sumowanie_dla_przedzialu(Czas& c2)
{

    int sekr = 0, minr = 0, godzr = 0;

    sek = sek + c2.sek;
    while (sek >= 60)
    {
        sek = sek - 60;
        sekr++;
    }

    min = min + c2.min + sekr;
    while (min >= 60)
    {
        min = min - 60;
        minr++;
    }

    godz = godz + c2.godz + minr;
}


//**********************************
//KONSTRUKTOR
//**********************************

Czas::Czas(int h, int m, int s) //Domyœlny czas to 00:00:00, który zostanie ustawiony automatycznie jeœli utworzony obiekt w klasie Czas nie bêdzie mia³ podanej godziny
{
    sek = s;
    min = m;
    godz = h;
    dodaj_czas();
}


//**********************************
//OPERATORY
//**********************************

Czas Czas::operator+(Czas& c2)
{

    int sekr = 0, minr = 0, godzr = 0;

    sek = sek + c2.sek;
    while (sek >= 60)
    {
        sek = sek - 60;
        sekr++;
    }

    min = min + c2.min + sekr;
    while (min >= 60)
    {
        min = min - 60;
        minr++;
    }

    godz = godz + c2.godz + minr;
    while (godz >= 24)
    {
        godz = godz - 24;
        godzr++;
    }

    return *this;
}

bool Czas::operator==(Czas& c2)
{
    if (godz == c2.godz)
    {
        if (min == c2.min)
        {
            if (sek == c2.sek)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Czas& Czas::operator+=(int s)
{
    int sekr = 0, minr = 0, godzr = 0;

    sek = sek + s;
    while (sek >= 60)
    {
        sek = sek - 60;
        sekr++;
    }

    min = min + sekr;
    while (min >= 60)
    {
        min = min - 60;
        minr++;
    }

    godz = godz + minr;
    while (godz >= 24)
    {
        godz = godz - 24;
        godzr++;
    }

    return *this;
}

bool Czas::operator<(Czas& c2)
{
    if (godz < c2.godz)
    {
        return true; //Je¿eli godz1 < godz2 to Czas 1 < Czas2
    }
    else
    {
        if (min < c2.min)
        {
            return true;
        }
        else
        {
            if (sek < c2.sek)
            {
                return true;
            }
            else
            {
                return false; //false je¿eli c1>=c2
            }
        }
    }
}

bool Czas::operator>(Czas& c2)
{
    if (godz > c2.godz)
    {
        return true;
    }
    else
    {
        if (min > c2.min)
        {
            return true;
        }
        else
        {
            if (sek > c2.sek)
            {
                return true;
            }
            else
            {
                return false; // false je¿eli c1<=c2
            }
        }
    }
}


//************************************************************************



void Czas::wyswietl_czas()
{
    std::cout << "Czas: ";
   
    if (godz < 10)
        std::cout << "0";

    std::cout << godz << ":";
       
    if (min < 10)
        std::cout << "0";

    std::cout << min << ":";

    if (sek < 10)
        std::cout << "0";

    std::cout << sek << std::endl;
}

void Czas::dodaj_godzine()
{
    do
    {
        if (godz > 23 || godz < 0)
            std::cout << "Wprowadzono nieprawid³ow¹ godzinê" << std::endl;
    } while (godz > 23 || godz < 0);
}

void Czas::dodaj_minute()
{
    do
    {
 
        if (min > 60 || min < 0)
            std::cout << "Wprowadzono nieprawid³ow¹ minutê" << std::endl;
    } while (min > 60 || min < 0);
}

void Czas::dodaj_sekunde()
{
    do
    {
 
        if (sek > 60 || sek < 0)
            std::cout << "Wprowadzono nieprawid³ow¹ sekundê" << std::endl;
    } while (sek > 60 || sek < 0);
}

void Czas::dodaj_czas()
{
    dodaj_godzine();
    dodaj_minute();
    dodaj_sekunde();
}
