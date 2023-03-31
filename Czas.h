class Czas
{
private:
    int godz;
    int min;
    int sek;

public:
    void wyswietl_czas_smg(int jak);
    void sumowanie_dla_przedzialu(Czas& c2);

    //konstruktory
    Czas(int h = 0, int m = 0, int s = 0);

    //operatory
    Czas operator+(Czas& c2);
    bool operator==(Czas& c2);
    Czas& operator+=(int s);
    bool operator<(Czas& c2);
    bool operator>(Czas& c2);

private:
    void wyswietl_czas();
    void dodaj_godzine();
    void dodaj_minute();
    void dodaj_sekunde();
    void dodaj_czas();


};