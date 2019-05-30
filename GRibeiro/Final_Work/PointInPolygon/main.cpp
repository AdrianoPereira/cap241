#include <bits/stdc++.h>
#include "Polygon.hpp"

using namespace std;

int main() {


    Point p1(2,2);
    Point p2(4,2);
    Point p3(4,3);
    Point p4(3,5);
    Point p5(1,4);
    Point p6(1,3);

    LineSegment l1(p1,p2);

    cout << l1.distance(); 


    return 0;
}