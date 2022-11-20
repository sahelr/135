/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.16
The program takes a point and finds the distance.
*/
#include <iostream>
#include <cmath>
class Point {
    public:
    double x;
    double y;
};
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main() {
    double x, y;
    std::cin >> x >> y;
    Point p = {x,y};
    std::cin >> x >> y;
    Point o = {x,y};
    std::cout << distance(p, o);
    return 0;
}