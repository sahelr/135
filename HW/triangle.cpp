/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.18
The program takes a triangle and finds the perimeter.
*/
#include <iostream>
#include <cmath>
class Point {
    public:
    double x;
    double y;
};
class Triangle {
    public:
        Point a;
        Point b;
        Point c;
};
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double perimeter(Triangle t) {
    return distance(t.a, t.b) + distance(t.c, t.b) + distance(t.a, t.c);
}
int main() {
    double x, y;
    std::cin >> x >> y;
    Point o = {x,y};
    std::cin >> x >> y;
    Point p = {x,y};
    std::cin >> x >> y;
    Point q = {x,y};
    Triangle r = {o,p,q};
    std::cout << perimeter(r);
    return 0;
}