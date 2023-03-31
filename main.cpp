#include <iostream>
#include <string>

#include "Czas.h"
#include "Harmonogram.h"


Harmonogram przykladowy_rozklad(Harmonogram Plan);
Czas stworz(int h, int m, int s);

int main()
{
    Harmonogram Plan, Backup;
    Plan = przykladowy_rozklad(Plan);
    Czas nowy, suma;

    int wybor, jak, n, ktory, bekap = 0, wyjdz = 1, h, m, s, x, jaki, ss, czasy;
    int h1, m1, s1, ktory1;
    
    setlocale(LC_ALL, "pl_PL");

    do
    {
        std::cout << "PROJEKT 1 - HARMONOGRAM" << std::endl
                   << std::endl << "MENU" << std::endl
                                << "(1) -> Dodaj nowy czas do harmonogramu" << std::endl
                                << "(2) -> Wyœwietl ca³y harmonogram" << std::endl
                                << "(3) -> Zwiêksz wybrany czas o x sekund" << std::endl
                                << "(4) -> Utwórz kopiê harmonogramu" << std::endl
                                << "(5) -> Utwórz kopiê harmonogramu mieszcz¹cego siê w zakresie" << std::endl
                                << "(6) -> Wyœwietl zsumowany czas" << std::endl
                                << "(7) -> Wyjœcie" << std::endl
                                << "-> ";

        std::cin >> wybor;
        switch (wybor)
        {
        case 1: //DODAWANIE NOWEGO CZASU DO HARMONOGRAMU
            system("cls");
            do
            {
                std::cout << "Podaj godzinê" << std::endl;
                std::cin >> h1;

                if (h1 > 24 || h1 < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (h1 > 24 || h1 < 0);

            do
            {
                std::cout << "Podaj minute" << std::endl;
                std::cin >> m1;

                if (m1 > 60 || m1 < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (m1 > 60 || m1 < 0);

            do
            {
                std::cout << "Podaj sekunde" << std::endl;
                std::cin >> s1;

                if (s1 > 60 || s1 < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (s1 > 60 || s1 < 0);

            nowy = stworz(h1, m1, s1);
            Plan.wprowadz_czas(nowy);
            system("cls");
            break;

        case 2: // WYŒWIETLANIE CA£EGO HARMONOGRAMU
            system("cls");
            do
            {
                std::cout << "Który harmonogram chcesz wyœwietliæ" << std::endl
                    << "(1) -> Plan" << std::endl
                    << "(2) -> Kopia zapasowa" << std::endl
                    << "-> ";
                std::cin >> ktory;

                if (ktory != 1 && ktory != 2)
                    std::cout << "Nie ma takiej opcji!" << std::endl;

                if (bekap == 0 && ktory == 2)
                {
                    std::cout << "Nie stworzono kopii zapasowej!" << std::endl
                              << "Odczytywanie harmonogramu z 'Planu'" << std::endl;
                    ktory = 1;
                }

            } while (ktory != 1 && ktory != 2);

            do
            {
                std::cout << "Wybierz format w jakim ma zostaæ przedstawiony czas" << std::endl
                    << "(0) - sek, min, godz" << std::endl
                    << "(1) - sek, min" << std::endl
                    << "(2) - sek" << std::endl
                    << "(3) - godz:min:sek" << std::endl
                    << "-> ";
                std::cin >> jak;

                if(jak > 3 || jak < 0)
                    std::cout << "Nie ma takiej opcji!" << std::endl;
            } while (jak > 3 || jak < 0);

            system("cls");

            if(ktory == 1)
                Plan.wyswietl_cale_zestawienie(jak);
            if (ktory == 2)
                Backup.wyswietl_cale_zestawienie(jak);

            system("pause");
            system("cls");
            break;

        case 3: // ZWIÊKSZANIE CZASU O 'X' SEKUND
            system("cls");
            Plan.wyswietl_cale_zestawienie(3);
            czasy = Plan.ile_czasow();
            do
            {
                std::cout << "Podaj który czas chcesz zwiêkszyæ?" << std::endl
                    << "-> ";
                std::cin >> jaki;

                if (jaki > czasy || jaki < 0)
                    std::cout << "Nie ma czasu o takim numerze!";
            } while (jaki > czasy || jaki < 0);

            do
            {
                std::cout << "Podaj o ile sekund chcesz zwiêkszyæ wskazany czas" << std::endl;
                std::cin >> ss;

                if (ss < 0)
                    std::cout << "Liczba musi byæ dodatnia!" << std::endl;

            } while (ss < 0);
            Plan.zwieksz_o(ss, jaki);
            system("cls");
            break;

        case 4: // KOPIOWANIE HARMONOGRAMU
            system("cls");
            Plan.wyswietl_cale_zestawienie(3);
            czasy = Plan.ile_czasow();
            do
            {
                std::cout << "Ile czasów ma zostaæ przeniesione?" << std::endl
                    << "-> ";
                std::cin >> n;

                if (n > czasy || n < 0)
                    std::cout << "Nie ma czasu o takim numerze!";
            } while (n > czasy || n < 0);

            Backup = Plan.kopia_zapasowa(n);
            bekap = 1;
            system("cls");
            break;

        case 5: // Z ZAKRESU
            system("cls");
            std::cout << "Podaj czas, którego nie mo¿e przekroczyæ suma czasów harmonogramu" << std::endl;
            
            do
            {
                std::cout << "Podaj godzinê" << std::endl;
                std::cin >> h;

                if (h > 24 || h < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (h > 24 || h < 0);

            do
            {
                std::cout << "Podaj minute" << std::endl;
                std::cin >> m;

                if (m > 60 || m < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (m > 60 || m < 0);

            do
            {
                std::cout << "Podaj sekunde" << std::endl;
                std::cin >> s;

                if (s > 60 || s < 0)
                    std::cout << "Z³a wartoœæ!" << std::endl;
            } while (s > 60 || s < 0);

            Backup = Plan.przedzial(h, m, s);

            bekap = 1;
            system("cls");
            break;

        case 6: //ZSUMOWANY CZAS
            system("cls");
            do
            {
                std::cout << "Który harmonogram chcesz zsumowaæ" << std::endl
                    << "(1) -> Plan" << std::endl
                    << "(2) -> Kopia zapasowa" << std::endl
                    << "-> ";
                std::cin >> ktory1;

                if (ktory1 != 1 && ktory1 != 2)
                    std::cout << "Nie ma takiej opcji!" << std::endl;

            } while (ktory1 != 1 && ktory1 != 2);
            
            if (ktory1 == 1)
            {
                suma = Plan.zsumuj_czasy();
                suma.wyswietl_czas_smg(3);
            }
            if (ktory1 == 2)
            {
                suma = Backup.zsumuj_czasy();
                suma.wyswietl_czas_smg(3);
            }
            system("pause");
            system("cls");
            break;

        case 7: // WYJŒCIE
            wyjdz = 2;
            break;

        default:
            system("cls");
            std::cout << "Nie ma takiej opcji!" << std::endl;
            break;
        }


    } while (wyjdz == 1);

    return 0;
}

Harmonogram przykladowy_rozklad(Harmonogram Plan)
{
    Czas c1(12, 14, 15), c2(21,15, 55), c3(1,9,0), c4(5, 2, 3), c5(18, 52, 11);
    
    Plan.wprowadz_czas(c1);
    Plan.wprowadz_czas(c2);
    Plan.wprowadz_czas(c3);
    Plan.wprowadz_czas(c4);
    Plan.wprowadz_czas(c5);

    return Plan;
}

Czas stworz(int h, int m, int s)
{
    Czas nowy(h, m, s);
    return nowy;
}