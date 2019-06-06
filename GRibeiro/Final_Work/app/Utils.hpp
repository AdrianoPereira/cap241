#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <vector>
#include <string>
#include <iostream>
#include <sstream> 
#include <iterator>
#include <cstring>
#include <dirent.h>
#include "Geometry.hpp"

std::vector<double> split(std::string str) {
    std::istringstream iss(str);
    std::vector<std::string> sans(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    std::vector<double> ans;
    
    for(auto s : sans) {
        ans.push_back(atof(s.c_str()));
    }
    
    return ans;
}

Point createPoint(std::vector<double> points) {
    Point ans(points[0], points[1]);
    return ans;
}

Polygon createPolygon(std::vector<double> points) {
    std::vector<Point> pts;
    for(int i=0; i<points.size(); i++) {
        double x = points[i], y = points[++i];
        Point p(x, y);
        pts.push_back(p);
    }
    Polygon ans(pts);
    return ans;
}

std::vector<std::string> read_dir_instances(const std::string& input_dir) {
    DIR *p_DIR;
    struct dirent *entry;
    std::vector<std::string> ans;

    char input_dir_char[1024];
    strncpy(input_dir_char, input_dir.c_str(), sizeof(input_dir_char));
    input_dir_char[sizeof(input_dir_char) - 1] = 0;

    if ((p_DIR = opendir(input_dir_char)) != NULL) {
        while ((entry = readdir(p_DIR))) {
            int len = static_cast<int>(strlen(entry->d_name));
            const char *last_four = &entry->d_name[len-4];
            if ((strcmp(entry->d_name, "..") != 0) && ((strcmp(last_four, ".txt") == 0)))
                ans.push_back(std::string(input_dir)+std::string(entry->d_name));
        }
        closedir(p_DIR);
    }
    return ans;
}

std::string cleanName(std::string str) {
    int x;
    std::string ans = "";

    for(x=str.size()-1; x>0; x--)
        if(str[x] == '/') break; 
    
    for(int y=x+1; y<str.size(); y++)
        ans+=str[y];
    
    return ans;
}

#endif