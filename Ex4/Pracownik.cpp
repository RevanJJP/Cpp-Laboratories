#include <iostream>
#include "Osoba.h"
#include "Data.h"
#include "Pracownik.h"

namespace cpp4{

    Pracownik::Pracownik(string imie, string nazwisko, const Data &rok_ur, double pensja): Osoba(imie, nazwisko, rok_ur), pensja(pensja) {}
    Pracownik::~Pracownik() {}

    double Pracownik::wyplata() const { return pensja; }

        string Pracownik::opis() const {
        return "Imie:\t" + imie + "\nNazwisko:\t" + nazwisko + "\nPensja:\t" + to_string(pensja) + "\nData:\t" + to_string(rok_ur.getDzien()) + "-" + to_string(rok_ur.getMiesiac()) + "-" + to_string(rok_ur.getRok()) + "\n";
    }

    bool Pracownik::zapisz(ostream &os) const {
        os << opis();
        if(!os) return false;
        return true;
    }

    bool Pracownik::wczytaj(istream &is) {
        int dzien, miesiac, rok;
        is >> imie >> nazwisko >> dzien >> miesiac >> rok >> pensja;
        if(!is) return false;
        rok_ur.setDzien(dzien);
        rok_ur.setDzien(miesiac);
        rok_ur.setDzien(rok);
        return true;
    }
}
