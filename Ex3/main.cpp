#include <iostream>
#include "lib3cpp.h"
using namespace std;

int main() {
    Point point_a(1.0, 1.0);
    Point point_b(1.0, 2.0);
    Point point_c(2.0, 2.0);
    Point point_d(2.0, 1.0);
    
    Polygon triangle; 
    cout<< "\nTriangle size:\t" << triangle.get_size();
    cout<< "\nTriangle object amount:\t" << triangle.get_object_amount();
    Polygon square(4);
    cout<< "\nSquare size:\t" << square.get_size();
    cout<< "\nSquare object amount:\t" << square.get_object_amount();
    
    cout << "\nCreating polygon of -1:\n";
    try {
        Polygon polygon(-1);
    } catch (invalid_argument error){
        cout<< "Error: " << error.what();
    }


    cout << "\nAdding 4 points to square:\n";
    try {
        square.add_object(point_a);
        square.add_object(point_b);
        square.add_object(point_c);
        square.add_object(point_d);
    } catch (overflow_error error) {
        cout << "Error: " << error.what();
    }

    cout << "\nPrinting square:\n";
    cout << square;

cout << "\nAdding 3 points to triangle:\n";
    try {
        triangle.add_object(point_a);
        triangle.add_object(point_b);
        triangle.add_object(point_c);
        triangle.add_object(point_d);
    } catch (overflow_error error) {
        cout << "Error: " << error.what();
    }

    cout << "\nPrinting triangle:\n";
    cout << triangle;


    Polygon triangle_constructor_copy(triangle);
    cout << "\nTriangled constructor copy:\n" << triangle_constructor_copy;
    Polygon triangle_constructor_moved = move(triangle_constructor_copy);
    cout << "\nTriangle constructor moved:\n" << triangle_constructor_moved;
    cout << "\nTringled used for moving\n" << triangle_constructor_copy;

    Polygon triangle_copy;
    triangle_copy=triangle;
    cout << "\nTriangled copy:\n" << triangle_copy;
    Polygon triangle_moved;
    triangle_moved = move(triangle_copy);
    cout << "\nTriangle moved:\n" << triangle_moved;
    cout << "\nTringled used for moving\n" << triangle_constructor_copy;

    cout << "\nDeleting triangle\n";
    triangle.~Polygon();
    

    return 0;
}
