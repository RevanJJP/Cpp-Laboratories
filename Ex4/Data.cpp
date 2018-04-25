#include <iostream>
#include "Data.h"

using namespace std;

namespace cpp4{

    Data::Data(int dzien, int miesiac, int rok): dzien{dzien}, miesiac{miesiac}, rok{rok} {}

    void Data::setDzien(int d) {this->dzien=d;}
    int Data::getDzien() const{return dzien;}
    void Data::setMiesiac(int m) {this->miesiac=m;}
    int Data::getMiesiac() const{return miesiac;}
    void Data::setRok(int r) {this->rok=r;}
    int Data::getRok() const{return rok;}

    bool Data::zapisz(ostream &os) const{
        os<<dzien<<" "<<miesiac<<" "<<rok;
        if(!os) return false;
        return true;
    }

    bool Data::wczytaj(istream &is) {
        is>>dzien>>miesiac>>rok;
        if(!is) return false;
        return true;
    }

    ostream& operator<<(ostream &stream, Data &d) {
        stream<<d.dzien<<"-"<<d.miesiac<<"-"<<d.rok<<endl;
        return stream;
    }
}
