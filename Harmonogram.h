
class Czas;

class Harmonogram
{
private:
    int rozmiar;
    Czas* tab_czas;

public:
    Harmonogram();
    ~Harmonogram();
    Harmonogram(const Harmonogram& poprzedni); //KONSTRUKTOR KOPIUJ¥CY
    Harmonogram& operator=(const Harmonogram& harmo); //OPERATOR PRZYPISANIA
    void wprowadz_czas(Czas& nowy);
    int ile_czasow();
    Czas daj_czas(int ktory);
    Czas zsumuj_czasy();
    void wyswietl_cale_zestawienie(int jak);
    Harmonogram kopia_zapasowa(int n);
    Harmonogram przedzial(int h, int m, int s);
    void zwieksz_o(int oile, int jaki);
};