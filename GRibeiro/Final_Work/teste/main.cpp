                                                                                                                                                #include <bits/stdc++.h>
#include "Geometry.hpp"
// #include <fstream>   
#define _ ios::sync_with_stdio(0);

using namespace std;

vector<double> splitToInt(string str) {
    istringstream iss(str);
    vector<string> sans(istream_iterator<string>{iss}, istream_iterator<string>());

    vector<double> ans;
    
    for(auto s : sans) {
        ans.push_back(atof(s.c_str()));
    }
    
    return ans;
}

Polygon createPolygon(vector<double> points) {
    vector<Point> pts;
    for(int i=0; i<points.size()-2; i++) {
        double x = points[i], y = points[++i];
        Point p(x, y);
        pts.push_back(p);
    }
    Polygon ans(pts);
    return ans;
}

int main() {_
    ifstream file("itaituba.txt");
    // ifstream file("in2");

    string line;
    int test = 0;

    if(file.is_open()) {
        while(getline(file, line)) {
            cout << "Test #" << ++test << endl;

            vector<double> arr = splitToInt(line);
            Polygon poly(createPolygon(arr));
            Point ptest(arr[arr.size()-2], arr[arr.size()-1]);
            
            poly.displayPoints();
            cout << "The point " << ptest.getX() << " " << ptest.getY() << (poly.inPolygon(ptest) ? " is inside polygon\n" : " is outside polygon\n");
            cout << endl;
        }
    }
    return 0;
}