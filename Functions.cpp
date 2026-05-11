#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

// Векторний добуток для перевірки належності
double crossProduct(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}


bool Triangle::isDegenerate() const {
    return fabs(crossProduct(A, B, C)) < 1e-9;
}

bool Triangle::onBorder(const Point &P) const {
    double d1 = fabs(crossProduct(A, B, P));
    double d2 = fabs(crossProduct(B, C, P));
    double d3 = fabs(crossProduct(C, A, P));
    return d1 < 1e-9 || d2 < 1e-9 || d3 < 1e-9;
}

bool Triangle::contains(const Point &P) const {
    if (isDegenerate()) {
        return false;
    }

    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}
