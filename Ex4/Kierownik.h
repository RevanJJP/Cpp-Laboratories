#ifndef CPP4_KIEROWNIK_H
#define CPP4_KIEROWNIK_H

#include <iostream>
#include "Osoba.h"
#include "Data.h"
#include "Pracownik.h"

namespace cpp4{

    class Kierownik : public Pracownik{
    protected:
        double dodatek;

    public:
        Kierownik(string imie, string nazwisko, const Data &rok_ur, double pensja, double dodatek);
        ~Kierownik() override;
        virtual string opis() const override;
        virtual double wyplata() const override;
        virtual bool zapisz(ostream &os) const override;
        virtual bool wczytaj(istream &is) override;
    };
}

#endif