#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__
#include <vector>

class Point {
    private:
        double x_, y_; 
    public:
        Point(double x, double y);
        const double get_x() const;
        const double get_y() const;
        const double distance(const Point& other) const;

        bool on_segment(Point q, Point r);
        int orientation(Point q, Point r);
        bool do_intersect(Point q1, Point p2, Point q2);
};

class Polygon {
    private:
        std::vector<Point> polygon_;
    public:
        Polygon(std::vector<Point> points);
        bool is_inside(Point p, int n);
        Point get_point(int index);
        ~Polygon();
};

#endif      //__POLYGON__HPP__