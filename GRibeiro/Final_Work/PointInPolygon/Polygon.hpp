#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

class Point {
    private:
        double x_, y_; 
    public:
        Point(double x, double y);
        const double get_x() const;
        const double get_y() const;
        // void translate(double x, double y);
        // double distance(const Point& other) const;
        ~Point();
};

class LineSegment {
    private:
        Point first_;
        Point second_;

        static bool overlaps(double a, double b, double c, double d);
        static double crossProduct(const Point& p1, const Point& p2, const Point& p3);
    
    public:
        LineSegment(const Point& p1, const Point& p2);
        const Point& first() const;
        const Point& second() const;
        bool contains(const Point& p) const;
        bool intersects(const LineSegment& other) const;
        
        const double& distance();
};

class Polygon {
    private:
        LineSegment* polygon_;

    public:
        Polygon(LineSegment* lines);
        ~Polygon();
};


#endif      //__POLYGON__HPP__