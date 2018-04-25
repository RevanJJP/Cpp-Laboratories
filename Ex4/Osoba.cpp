#include <iostream>
#include <string>
#include "Data.h"
#include "Osoba.h"

using namespace std;

namespace cpp4{

    Osoba::Osoba(string imie, string nazwisko, const Data &rok_ur): imie(imie), nazwisko(nazwisko), rok_ur(rok_ur){}
    Osoba::~Osoba(){}

    string Osoba::opis() const {
        return "Imie:\t" + imie + "\nNazwisko:\t" + nazwisko + "\nData:\t" + to_string(rok_ur.getDzien()) + "-" + to_string(rok_ur.getMiesiac()) + "-" + to_string(rok_ur.getRok()) + "\n";
    }

    bool Osoba::zapisz(ostream &os) const {
        os << opis();
        if(!os) return false;
        return true;
    }

    bool Osoba::wczytaj(istream &is) {
        int dzien, miesiac, rok;
        is >> imie >> nazwisko >> dzien >> miesiac >> rok;
        if(!is) return false;
        rok_ur.setDzien(dzien);
        rok_ur.setDzien(miesiac);
        rok_ur.setDzien(rok);
        return true;
    }
}