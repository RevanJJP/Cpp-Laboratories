#ifndef CPP4_DATA_H
#define CPP4_DATA_H

#include <iostream>

using namespace std;

namespace cpp4{

    class Data{
    private:
        int dzien, miesiac, rok;
    public:
        Data(int dzien, int miesiac, int rok);
        void setDzien(int d);
        int getDzien() const;
        void setMiesiac(int m);
        int getMiesiac() const;
        void setRok(int r);
        int getRok() const;

        bool zapisz(ostream &os) const;
        bool wczytaj(istream &is);
        friend ostream &operator<<(ostream &stream, Data &data);
    };
}







#endif //LAB4_11_04_18_Data_H
