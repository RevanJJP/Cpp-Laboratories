//
// Created by Jakub Posłuszny on 20.03.2018.
//
#include "library.h"
using namespace std;

//Wektor
Wektor::Wektor(float x, float y, float z) : x(x), y(y), z(z)  {}

Wektor Wektor::operator + (Wektor const &obj) const {
    Wektor sum;
    sum.x=x+obj.x;
    sum.y=y+obj.y;
    sum.z=z+obj.z;

    return sum;
}

Wektor Wektor::operator += (Wektor const &obj) {
    *this= *this+obj;
    return *this;
}

Wektor Wektor::operator - () const {
    Wektor minus = *this;
    minus.x=-x;
    minus.y=-y;
    minus.z=-z;

    return minus;
}

Wektor::operator float() const{
    return sqrt(x*x + y*y + z*z);
}

bool Wektor::operator > (Wektor const &obj) const {
    return (float)*this > (float) obj;
}

float Wektor::operator[](const int index) const {
    if(index==0)
        return x;
    if(index==1)
        return y;
    if(index==2)
        return z;

    cout << "Index out of bound: 0->x, 1->y, 2->z" << endl;
    return NULL;
}

//f. zewn.
Wektor operator * (float a, Wektor const &obj) {
    Wektor out;
    out.x = a*obj.x;
    out.y = a*obj.y;
    out.z = a*obj.z;
    return  out;
}
Wektor operator * (Wektor const &obj, float a) {
    return a*obj;
}

ostream& operator << (ostream& outStream, Wektor const &obj) {
    return outStream << "(" << obj.x << " " << obj.y << " " << obj.z << " ";
}

//Punkt
Punkt::Punkt(float x, float y, float z) : x(x), y(y), z(z)    {}

Punkt Punkt::operator + (Wektor const &obj) const {
    Punkt sum=*this;
    sum.x+=obj.x;
    sum.y+=obj.y;
    sum.z+=obj.z;

    return sum;
}

Punkt& Punkt::operator ++ ()   {
    x++;
    y++;
    z++;
}

Punkt Punkt::operator ++ (int)   {
    Punkt temp = *this;
    ++*this;
    return temp;
}

//zewn

ostream& operator << (ostream& outStream, Punkt const &obj)    {
    return outStream << "(" << obj.x << " " << obj.y << " " << obj.z << " ";
}


