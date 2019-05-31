#include <bits/stdc++.h>
#include "Polygon.hpp"
using namespace std;
#define max(x, y) (((x) > (y)) ? (x) : (y))

int main() {
    Point p1(0,0);
    Point p2(10,0);
    Point p3(10, 10);
    Point p4(0, 10);
    Point p5(20, 20);

    vector<Point> points;

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p1);

    Polygon pl(points);

    cout << pl.is_inside(p1, 6)  << endl;


    return 0;
}