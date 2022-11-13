/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Lab 9E
The purpose of this program is to create and delete coordinate objects dynamically.
*/
#include <iostream>
#include <string>
#include <cmath>
class Coord3D { // Sets Coordinates.
public:
    double x;
    double y;
    double z;
};
double length(Coord3D *p) { // Gets length of coordinate.
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}
Coord3D * fartherFromOrigin(Coord3D * p1, Coord3D * p2) {
    if(length(p1) > length(p2)) {
        return p1;
    }
    return p2;
}
void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x += (pvel->x * dt);
    ppos->y += (pvel->y * dt);
    ppos->z += (pvel->z * dt);
}
Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D * coord = new Coord3D;
    coord->x = x;
    coord->y = y;
    coord->z = z;
    return coord;
}
void deleteCoord3D(Coord3D *p) {
    delete p;
}
int main() {
    double x, y, z;
    std::cin >> x >> y >> z;
    Coord3D * pointP = createCoord3D(x, y, z);
    //std::cout << length(&pointP) << std::endl; Part A
    /*std::cin >> x >> y >> z; // Part B
    Coord3D pointQ = {x,y,z};
    std::cout << "address of P" << &pointP << std::endl;
    std::cout << "address of Q" << &pointQ << std::endl;
    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
    std::cout << "ans = " << ans << std::endl; */
    std::cin >> x >> y >> z;
    Coord3D * vel = createCoord3D(x, y, z);
    // move(&pointP, &vel, 2.0);  object pos gets changed | Part C
    move(pointP, vel, 10.0);
    std::cout << (*pointP).x << " " << (*pointP).y << " " << (*pointP).z << std::endl;
    deleteCoord3D(pointP); // release memory
    deleteCoord3D(vel);
    return 0;
}