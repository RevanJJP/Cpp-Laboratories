#ifndef CPP4_OSOBA_H
#define CPP4_OSOBA_H
#include <string>
#include <iostream>
#include "Osoba.h"
#include "Data.h"

using namespace std;

namespace cpp4{

    class Osoba{
    protected:
        string imie, nazwisko;
        Data rok_ur;

    public:
        Osoba(string imie, string nazwisko, const Data &rok_ur);
        virtual ~Osoba();
        virtual string opis() const;
        virtual double wyplata() const { return 0; }
        virtual bool zapisz(ostream &os) const;
        virtual bool wczytaj(istream &is);
    };
}

#endif
