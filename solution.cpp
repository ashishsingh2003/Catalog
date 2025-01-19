#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <bits/stdc++.h>
unsigned long long decodeValue(const std::string& value, int base) {
    unsigned long long result = 0;
    for (char digit : value) {
        int num;
        if (isdigit(digit)) {
            num = digit - '0';  
        } else {
            num = digit - 'a' + 10;  
        result = result * base + num;
    }
    return result;
}


long long lagrangeInterpolation(const std::vector<std::pair<int, long long>>& points) {
    long long result = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        long long xi = points[i].first;
        long long yi = points[i].second;

       
        long long term = yi;
        for (size_t j = 0; j < points.size(); ++j) {
            if (i != j) {
                long long xj = points[j].first;
                term *= -xj;
                term /= (xi - xj);
            }
        }
        result += term;
    }
    return result;
}

int main() {
   
    int n = 10;
    int k = 7;  

   
    std::vector<std::pair<int, long long>> points;

    

   
    points.push_back({1, decodeValue("13444211440455345511", 6)});

    
    points.push_back({2, decodeValue("aed7015a346d63", 15)});

   
    points.push_back({3, decodeValue("6aeeb69631c227c", 15)});

   
    points.push_back({4, decodeValue("e1b5e05623d881f", 16)});

   
    points.push_back({5, decodeValue("316034514573652620673", 8)});

    points.push_back({6, decodeValue("2122212201122002221120200210011020220200", 3)});

    
    points.push_back({7, decodeValue("20120221122211000100210021102001201112121", 3)});

    points.push_back({8, decodeValue("20220554335330240002224253", 6)});

    
    points.push_back({9, decodeValue("45153788322a1255483", 12)});

    
    points.push_back({10, decodeValue("1101613130313526312514143", 7)});

  
    long long secret_c = lagrangeInterpolation(points);

    
    std::cout << " c is: " << secret_c << std::endl;

    return 0;
}
