#pragma once
#include <cmath>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    bool contains(const Point &P) const;
    bool isDegenerate() const;
    bool onBorder(const Point &P) const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
double crossProduct(Point O, Point A, Point B);