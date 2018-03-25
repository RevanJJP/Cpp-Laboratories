//
// Created by Jakub Posłuszny on 20.03.2018.
//

#ifndef CPP2_LIBRARY_H
#define CPP2_LIBRARY_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Wektor {
    float x, y, z;
    friend class Punkt;

public:
    Wektor(float x=0, float y=0, float z=0);

    Wektor operator +  (Wektor const &obj) const; //+
    Wektor operator += (Wektor const &obj); //+
    Wektor operator - () const; //+

    explicit operator float() const; //+
    bool operator > (Wektor const &obj) const; //+
    float operator [] (int index) const; //+

    friend Wektor operator * (float a, Wektor const &obj);  //+
    friend Wektor operator * (Wektor const &obj, float a);  //+
    friend ostream& operator << (ostream& outStream, Wektor const &obj); //+
};

class Punkt {
    float x, y, z;

public:
    Punkt(float x=0, float y=0, float z=0);

    Punkt operator + (Wektor const &obj) const; //+
    Punkt& operator ++ ();     //suffix +
    Punkt operator ++ (int); //prefix  +

    friend ostream& operator << (ostream& outStream, Punkt const& obj); //+
};

#endif CPP2_LIBRARY_H
