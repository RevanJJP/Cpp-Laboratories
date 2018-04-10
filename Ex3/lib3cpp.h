//
// Created by Jakub Posłuszny on 10.04.2018.
//

#ifndef CPP3_LIB3CPP_H
#define CPP3_LIB3CPP_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
using namespace std;

class Point {
private:
    float x, y;
public:
    Point(float x, float y);
    float get_x() const;
    float get_y() const;
};

class Polygon {
private:
    Point* array;
    int size;
    int counter;

public:
    explicit Polygon(int size=3);
    ~Polygon();

    Polygon(const Polygon& obj); //copy
    Polygon(Polygon&& obj);      //move

    Polygon& operator = (const Polygon& obj);
    Polygon& operator = (Polygon&& obj);
    
    int get_object_amount() const;
    int get_size() const;
    
    void add_object(const Point& obj);

    friend ostream&operator << (ostream& out, const Polygon& obj);
};

#endif
