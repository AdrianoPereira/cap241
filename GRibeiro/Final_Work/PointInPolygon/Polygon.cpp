#include "Polygon.hpp"
#include <cmath>
#include <iostream>
#include <vector>

#define INF 0x3f3f
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

Point::Point(double x, double y):x_(x), y_(y){}

const double Point::get_x() const {
    return this->x_;
}

const double Point::get_y() const {
    return this->y_;
}

const double Point::distance(const Point& other) const {
    return sqrt(pow(abs(this->get_x()-other.get_x()), 2) + pow(abs(this->get_y()-other.get_y()), 2));
}

// Point::~Point() {}

Polygon::Polygon(std::vector<Point> segments) {
    for(auto s : segments) {
        std::cout << s.get_x() << std::endl;
    }
}

Polygon::~Polygon() {}

Point Polygon::get_point(int index) {
    return this->polygon_[index];
}

bool Point::on_segment(Point q, Point r) { 
    if (q.get_x() <= max(this->get_x(), r.get_x()) && q.get_x() >= min(this->get_x(), r.get_x()) && 
            q.get_y() <= max(this->get_y(), r.get_y()) && q.get_y() >= min(this->get_y(), r.get_y())) 
        return true; 
    return false; 
} 


int Point::orientation(Point q, Point r) { 
    int val = (q.get_y() - this->get_y()) * (r.get_x() - q.get_x()) - 
              (q.get_x() - this->get_x()) * (r.get_y() - q.get_y()); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool Point::do_intersect(Point q1, Point p2, Point q2) { 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = this->orientation(q1, p2); 
    int o2 = this->orientation(q1, q2); 
    int o3 = p2.orientation(q2, *this); 
    int o4 = p2.orientation(q2, *this); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && this->on_segment(p2, q1)) return true; 
  
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && this->on_segment(q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && p2.on_segment(*this, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && p2.on_segment(q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

bool Polygon::is_inside(Point p, int n) { 
    // There must be at least 3 vertices in polygon[] 
    
    if (n < 3)  return false; 
  
    // Create a point for line segment from p to infinite 
    Point extreme = {INF, p.get_y()}; 
  
    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0; 
    do { 
        int next = (i+1)%n; 
  
        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (this->get_point(i).do_intersect(this->get_point(next), p, extreme)) { 
            // If the point 'p' is colinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (this->get_point(i).orientation(p, this->get_point(next)) == 0) 
               return this->get_point(i).on_segment(p, this->get_point(next)); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  
    // Return true if count is odd, false otherwise 
    return count&1;  // Same as (count%2 == 1) 
} 
