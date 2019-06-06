#ifndef __GEOMETRY_HPP__
#define __GEOMETRY_HPP__

#include <vector>

class Point {
    private:
        double x_, y_;
    public:
        Point(double x, double y);
        const double getX() const;
        const double getY() const;
};

class Line {
    private:
        Point p1_, p2_;
    public:
        Line(Point p1, Point p2);
        Point getP1();
        Point getP2();
        bool isIntersect(Line l2);
        bool onLine(Point p);
        double direction(Point a, Point b, Point c);
};

class Polygon {
    private:
        std::vector<Point> polygon_;
    
    public:
        Polygon(std::vector<Point> points);
        Polygon();
        Point getPointByIndex(int index);
        bool inside(Point p);
};

#endif