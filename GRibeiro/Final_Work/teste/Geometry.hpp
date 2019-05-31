#ifndef __GEOMETRY_HPP__
#define __GEOMETRY_HPP__
#include <vector>
#include <limits>

class Point {
    private:
        double x_, y_;
    public:
        Point(double, double);
        Point(const Point& p);
        Point& operator = (const Point& p);
        double getX();
        double getY();
};

struct BoundingBox {
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    
    BoundingBox(double xmin, double xmax, double ymin, double ymax) {
        this->xmin = xmin;
        this->xmax = xmax;
        this->ymin = ymin;
        this->ymax = ymax;
    }

    BoundingBox() {
        this->xmin = std::numeric_limits<double>::max();
        this->xmax = std::numeric_limits<double>::min();
        this->ymin = std::numeric_limits<double>::max();
        this->ymax = std::numeric_limits<double>::min();
    }
};

class Polygon {
    private:
        std::vector<Point> points;
        BoundingBox bbox;
    
    private:
        void calcBoundingBox(std::vector<Point> points);
    
    public:
        Polygon(std::vector<Point>& points);
        bool inBoundingBox(Point point);
        bool inPolygon(Point point);
        void displayPoints();
};  

#endif