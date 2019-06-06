#include "Geometry.hpp"
#include <vector>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

Point::Point(double x, double y):x_(x), y_(y) {}

const double Point::getX() const { return this->x_; }

const double Point::getY() const { return this->y_; }

Line::Line(Point p1, Point p2):p1_(p1), p2_(p2) {}

Point Line::getP1() { return this->p1_; }

Point Line::getP2() { return this->p2_; }

bool Line::onLine(Point p) {
    Point p1 = this->getP1();
    Point p2 = this->getP2();
    
    if(p.getX() <= max(p1.getX(), p2.getX()) && p.getX() <= min(p1.getX(), p2.getX()) &&
      (p.getY() <= max(p1.getY(), p2.getY()) && p.getY() <= min(p1.getY(), p2.getY())))
         return true;

   return false;
}

bool Line::isIntersect(Line l2) {
   //four direction for two lines and points of other line
   double dir1 = this->direction(this->getP1(), this->getP2(), l2.getP1());
   double dir2 = this->direction(this->getP1(), this->getP2(), l2.getP2());
   double dir3 = this->direction(l2.getP1(), l2.getP2(), this->getP1());
   double dir4 = this->direction(l2.getP1(), l2.getP2(), this->getP2());

   if(dir1 != dir2 && dir3 != dir4)
      return true;           //they are intersecting
   if(dir1==0 && l2.onLine(this->getP1()))        //when p2 of line2 are on the line1
      return true;
   if(dir2==0 && this->onLine(l2.getP2()))         //when p1 of line2 are on the line1
      return true;
   if(dir3==0 && l2.onLine(this->getP1()))       //when p2 of line1 are on the line2
      return true;
   if(dir4==0 && l2.onLine(this->getP2())) //when p1 of line1 are on the line2
      return true;
   return false;
}

Polygon::Polygon(std::vector<Point> points):polygon_(points) {}

Polygon::Polygon() {}

bool Polygon::inside(Point p) {
    int n = this->polygon_.size();

    if(n < 3)
        return false;                  //when polygon has less than 3 edge, it is not polygon
    
    Line exline = {p, {9999, p.getY()}};   //create a point at infinity, y is same as point p
    int count = 0;
    int i = 0;
    do {
        Line side = {this->polygon_[i], this->polygon_[(i+1)%n]};     //forming a line from two consecutive points of poly
        if(side.isIntersect(exline)) {          //if side is intersects exline
            if(side.direction(side.getP1(), p, side.getP2()) == 0) // remover direction da line
                return side.onLine(p);
            count++;
        }
        i = (i+1)%n;
    } while(i != 0);
        return count&1;             //when count is odd
}

//Utils
double Line::direction(Point a, Point b, Point c) {
    double val = (b.getY()-a.getY())*(c.getX()-b.getX())-(b.getX()-a.getX())*(c.getY()-b.getY());
    
    if (val == 0)
        return 0;           //colinear
    else if(val < 0)
        return 2;          //anti-clockwise direction
    
    return 1;          //clockwise direction
}