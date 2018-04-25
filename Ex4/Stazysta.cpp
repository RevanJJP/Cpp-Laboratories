#include <iostream>
#include "Osoba.h"
#include "Data.h"
#include "Stazysta.h"

namespace cpp4{

    Stazysta::Stazysta(string imie, string nazwisko, const Data &rok_ur, double stypendium, const Data &koniec_stazu): Osoba(imie, nazwisko, rok_ur), stypendium(stypendium), koniec_stazu(koniec_stazu) {}
    
    Stazysta::~Stazysta() {}

    void Stazysta::zmienKoniecStazu(Data d) {
        koniec_stazu.setDzien(d.getDzien());
        koniec_stazu.setMiesiac(d.getMiesiac());
        koniec_stazu.setRok(d.getRok());
    }

    double Stazysta::wyplata() const { return stypendium; }

    string Stazysta::opis() const {
        return "Imie:\t" + imie + "\nNazwisko:\t" + nazwisko + "\nStypendium:\t" + to_string(stypendium) + "\nData:\t" + to_string(rok_ur.getDzien()) + "-" + to_string(rok_ur.getMiesiac()) + "-" + to_string(rok_ur.getRok()) + "\n";
    }

    bool Stazysta::zapisz(ostream &os) const {
        os << imie << " " << nazwisko << endl << opis();
        if(!os) return false;
        return true;
    }

    bool Stazysta::wczytaj(istream &is) {
        int dzien, miesiac, rok;
        is >> imie >> nazwisko >> dzien >> miesiac >> rok >> stypendium;
        if(!is) return false;
        rok_ur.setDzien(dzien);
        rok_ur.setDzien(miesiac);
        rok_ur.setDzien(rok);
        return true;
    }
}
