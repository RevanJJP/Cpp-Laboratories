#ifndef CPP4_PRACOWNIK_H
#define CPP4_PRACOWNIK_H

#include <iostream>
#include "Osoba.h"
#include "Data.h"

namespace cpp4{

    class Pracownik : public Osoba{
    protected:
        double pensja;

    public:
        Pracownik(string imie, string nazwisko, const Data &rok_ur, double pensja);
        ~Pracownik() override;
        virtual string opis() const override;
        virtual double wyplata() const override;
        virtual bool zapisz(ostream &os) const override;
        virtual bool wczytaj(istream &is) override;
    };
}

#endif
