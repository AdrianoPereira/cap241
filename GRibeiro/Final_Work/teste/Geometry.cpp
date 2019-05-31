#include "Geometry.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>

Point::Point(double x, double y):x_(x), y_(y){}

Point::Point(const Point& p){ this->x_ = p.x_; this->y_ = p.y_; }

double Point::getX() { return this->x_; }

double Point::getY() { return this->y_; }

Point& Point::operator= (const Point& p) {
    this->x_ = p.x_;
    this->y_ = p.y_;
    return *this;
}

int direction(Point pi, Point pj, Point pk) {
    return (pk.getX() - pi.getX()) * (pj.getY() - pi.getY()) - (pj.getX() - pi.getX()) * (pk.getY() - pi.getY());
}

bool onSegment(Point pi, Point pj, Point pk) {
    if (std::min(pi.getX(), pj.getX()) <= pk.getX() && pk.getX() <= std::max(pi.getX(), pj.getX())
        && std::min(pi.getY(), pj.getY()) <= pk.getY() && pk.getY() <= std::max(pi.getY(), pj.getY())) {
        return true;
    } else {
        return false;
    }
}

bool segmentIntersect(Point p1, Point p2, Point p3, Point p4) {
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    } else if (d1 == 0 && onSegment(p3, p4, p1)) {
        return true;
    } else if (d2 == 0 && onSegment(p3, p4, p2)) {
        return true;
    } else if (d3 == 0 && onSegment(p1, p2, p3)) {
        return true;
    } else if (d4 == 0 && onSegment(p1, p2, p4)) {
        return true;
    } else {
        return false;
    }
}

Polygon::Polygon(std::vector<Point>& points):points(points) { calcBoundingBox(points); }

bool Polygon::inBoundingBox(Point point) {
    if (point.getX() < bbox.xmin || point.getX() > bbox.xmax || point.getY() < bbox.ymin || point.getY() > bbox.ymax) {
        return false;
    } else {
        return true;
    }
}

bool Polygon::inPolygon(Point point) {
    if (!inBoundingBox(point)) {
        return false;
    }
    //create a ray (segment) starting from the given point, 
    //and to the point outside of polygon.
    Point outside(bbox.xmin - 1, bbox.ymin);
    int intersections = 0;
    //check intersections between the ray and every side of the polygon.
    for (int i = 0; i < points.size() - 1; ++i) {
        if (segmentIntersect(point, outside, points.at(i), points.at(i + 1))) {
            intersections++;
        }
    }
    //check the last line
    if (segmentIntersect(point, outside, points.at(points.size() - 1), points.at(0))) {
        intersections++;
    }
    return (intersections % 2 != 0);
}

void Polygon::calcBoundingBox(std::vector<Point> points) {
    for (auto &point : points) {
        if (point.getX() < bbox.xmin) {
            bbox.xmin = point.getX();
        } else if (point.getX() > bbox.xmax) {
            bbox.xmax = point.getX();
        }
        if (point.getY() < bbox.ymin) {
            bbox.ymin = point.getY();
        } else if (point.getY() > bbox.ymax) {
            bbox.ymax = point.getY();
        }
    }
}

void Polygon::displayPoints() {
    std::cout << "Polygon: (";
    for(int i=0; i<this->points.size(); i++) {
        std::cout << std::fixed << std::setprecision(5) 
        << "(" << (this->points[i].getX()) << ", " << (this->points[i].getY()) << ")";
    }
    std::cout << ")\n";
}