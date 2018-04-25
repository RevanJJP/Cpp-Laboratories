#include <iostream>
#include "Osoba.h"
#include "Data.h"
#include "Kierownik.h"

namespace cpp4{

    Kierownik::Kierownik(string imie, string nazwisko, const Data &rok_ur, double pensja, double dodatek): Pracownik(imie, nazwisko, rok_ur, pensja), dodatek(dodatek) {}
    Kierownik::~Kierownik() {}

    double Kierownik::wyplata() const { return pensja+dodatek; }

    string Kierownik::opis() const {
        return "Imie:\t" + imie + "\nNazwisko:\t" + nazwisko + "\nPensja:\t" + to_string(pensja) + "\nDodatek:\t" + to_string(dodatek) +  "\nData:\t" + to_string(rok_ur.getDzien()) + "-" + to_string(rok_ur.getMiesiac()) + "-" + to_string(rok_ur.getRok()) + "\n";
    }

    bool Kierownik::zapisz(ostream &os) const {
        os << opis();
        if(!os) return false;
        return true;
    }

    bool Kierownik::wczytaj(istream &is) {
        int dzien, miesiac, rok;
        is >> imie >> nazwisko >> dzien >> miesiac >> rok >> pensja;
        if(!is) return false;
        rok_ur.setDzien(dzien);
        rok_ur.setDzien(miesiac);
        rok_ur.setDzien(rok);
        return true;
    }
}
