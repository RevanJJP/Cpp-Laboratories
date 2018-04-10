//
// Created by Jakub Posłuszny on 10.04.2018.
//
#include "lib3cpp.h"
using namespace std;

Point::Point(float x, float y) : x(x), y(y)  {}
float Point::get_x() const {return x;}
float Point::get_y() const {return y;}

Polygon::Polygon(int size) : size(size), counter(0), array((Point*) (calloc(size, sizeof(Point))))   {
    if(size<=0) throw invalid_argument("Wrong array size");
}

Polygon::~Polygon()   {
    free(array);
    array=nullptr;
}


Polygon::Polygon(const Polygon& obj) : size(obj.size), counter(obj.counter), array((Point*) (calloc(obj.size, sizeof(Point)))) {
    for(int i=0; i<counter; i++) this->array[i]=obj.array[i];
}
Polygon::Polygon(Polygon&& obj) : size(obj.size), counter(obj.counter), array(obj.array){
    obj.array=nullptr;
    obj.counter=0;
}

Polygon& Polygon::operator = (const Polygon& obj){
    if (this!=&obj) {
        this->~Polygon();
        this->size=obj.size;
        this->counter=obj.counter;
        this->array=(Point*) (calloc(size, sizeof(Point)));
        for (int i=0; i<counter; i++) this -> array[i] = obj.array[i];
    }
    return *this;
}
Polygon& Polygon::operator = (Polygon&& obj){
    if (this!=&obj) {
        this->~Polygon();
        this->size=obj.size;
        this->counter=obj.counter;
        this->array=obj.array;
        obj.array=nullptr;
        obj.size=0;
        obj.counter=0;
    }
    return *this;
}
    
int Polygon::get_object_amount() const{return counter;}

int Polygon::get_size() const{return size;}
    
void Polygon::add_object(const Point& obj){
    if(counter<size) {
        this->array[counter]=obj;
        counter++;
    }
    else throw overflow_error("Array is full");
}

ostream&operator << (ostream& out, const Polygon& obj){
    out<< "SIZE:\t" << obj.size << endl;
    out<< "COUNTER:\t" << obj.counter << endl;
    out<< "{";
    for(int i=0; i<obj.counter; i++){
        Point point=obj.array[i];
        out<< "(" << point.get_x() << "," << point.get_y() << ")";
        if(i!=obj.counter-1) cout <<",";
    }
    out<< "}"<<endl<<endl;
    return out;
}

