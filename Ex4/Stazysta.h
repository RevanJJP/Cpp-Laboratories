#ifndef CPP4_STAZYSTA_H
#define CPP4_STAZYSTA_H

#include <iostream>
#include "Osoba.h"
#include "Data.h"

namespace cpp4{

    class Stazysta : public Osoba{
    protected:
        double stypendium;
        Data koniec_stazu;

    public:
        Stazysta(string imie, string nazwisko, const Data &rok_ur, double stypendium, const Data &koniec_stazu);
        ~Stazysta() override;
        void zmienKoniecStazu(Data d);
        virtual double wyplata() const override;
        virtual string opis() const override;
        virtual bool zapisz(ostream &os) const override;
        virtual bool wczytaj(istream &is) override;
    };
}

#endif
