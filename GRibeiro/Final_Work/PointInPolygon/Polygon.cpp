#include "Polygon.hpp"
#include <cmath>

Point::Point(double x, double y):x_(x), y_(y){}

const double Point::get_x() const {
    return this->x_;
}

const double Point::get_y() const {
    return this->y_;
}

Point::~Point() {}

LineSegment::LineSegment(const Point& p1, const Point& p2):first_(p1), second_(p2){}

const Point& LineSegment::first() const {
    return this->first_;
}

const Point& LineSegment::second() const {
    return this->second_;
}

const double& LineSegment::distance(){
    return this->first().get_x();
    //return sqrt((pow(abs(this->first().get_x()-this->second().get_x()),2))   +   pow(abs(this->first().get_y()-this->second().get_y()),2));
}