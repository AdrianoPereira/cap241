#include "Polygon.hpp"

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