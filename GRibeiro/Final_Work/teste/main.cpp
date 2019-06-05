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

Point createPoint(vector<double> points) {
    Point ans(points[0], points[1]);
    return ans;
}

Polygon createPolygon(vector<double> points) {
    vector<Point> pts;
    for(int i=0; i<points.size(); i++) {
        double x = points[i], y = points[++i];
        Point p(x, y);
        pts.push_back(p);
    }
    Polygon ans(pts);
    return ans;
}

#include <dirent.h> // for read files from directory function

vector<string> read_dir_instances(const string& input_dir) {
    DIR *p_DIR;
    struct dirent *entry;
    vector<string> ans;

    /* convert string to char* */
    char input_dir_char[1024];
    strncpy(input_dir_char, input_dir.c_str(), sizeof(input_dir_char));
    input_dir_char[sizeof(input_dir_char) - 1] = 0;

    if ((p_DIR = opendir(input_dir_char)) != NULL) {
        while ((entry = readdir(p_DIR))) {
            int len = static_cast<int>(strlen(entry->d_name));
            const char *last_four = &entry->d_name[len-4];
            if ((strcmp(entry->d_name, "..") != 0) && ((strcmp(last_four, ".txt") == 0)))
                ans.push_back(string(input_dir)+std::string(entry->d_name));
        }
        closedir(p_DIR);
    }
    return ans;
}

string cleanName(string str) {
    int x;
    string ans = "";

    for(x=str.size()-1; x>0; x--)
        if(str[x] == '/') break; 
    
    for(int y=x+1; y<str.size(); y++)
        ans+=str[y];
    
    return ans;
}

int main() {_
    vector<string> paths_pc = read_dir_instances("./polygons/");
    vector<string> paths_pd = read_dir_instances("./points/");

    for(const auto& path_city : paths_pc) {
        ifstream file(path_city);
        string line;
        int count = 0;

        while(getline(file, line)) {
            // cout << path_city << endl;
            vector<double> arr_p = splitToInt(line);
            Polygon poly_city(createPolygon(arr_p));

            
            // poly_city.displayPoints();
            
            vector<Point> centroids;

            for(const auto& path_deflorestation : paths_pd) {
                // cout << "--> " << path_deflorestation << endl;
                ifstream file_d(path_deflorestation);
                string line_d;

                while(getline(file_d, line_d)) {
                    vector<double> arr_d = splitToInt(line_d);
                    Point point_centroid(arr_d[0], arr_d[1]);
                    centroids.push_back(point_centroid);
                }
            }
            for(auto c : centroids) {
                count = poly_city.inPolygon(c) ? count+1 : count;
                // cout << path_city << " ---- " << c.getX() << ", " << c.getY() << endl;  
                // cout << cleanName(path_city) << " Point(" << c.getX() << ", " << c.getY() << ") is " << (poly_city.inPolygon(c) ? "inside" : "outside")  << endl; 
            }
        }
        cout << cleanName(path_city) << " has " << count << endl; 
    }

    return 0;
}