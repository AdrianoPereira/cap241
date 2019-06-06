#include <bits/stdc++.h>
#include "Geometry.hpp"
#include "Utils.hpp"

using namespace std;

int main() {
    vector<string> city_paths = read_dir_instances("./polygons/");
    vector<string> deflorestation_paths = read_dir_instances("./points/");
    int total = 0;

    for(const auto& file_name_city : city_paths) {
        ifstream file_city(file_name_city);
        string line_city;
        vector<Point> cidade;
        int number_points = 0;

        while(getline(file_city, line_city)) {
            vector<double> arr_p = split(line_city);
            
            //
            for(int i=1; i<arr_p.size(); i+=2) {
                Point p(arr_p[i-1], arr_p[i]);
                cidade.push_back(p);
            }

            Polygon poly(cidade);

            for(const auto& file_name_deflorestation: deflorestation_paths) {
                ifstream file_deflorestation(file_name_deflorestation);
                string line_deflorestation;
                vector<Point> desmatamento;

                while(getline(file_deflorestation, line_deflorestation)) {
                    vector<double> centroid = split(line_deflorestation);
                    Point pt(centroid[0], centroid[1]);
                    if(poly.inside(pt)){
                        number_points ++;
                        total++;
                    }
                }
            }   
        }
        cout << cleanName(file_name_city) << "," << number_points <<  "\n";
    }

    cout << "Total de desmatamento no estado do Pará: " << total << endl;
}