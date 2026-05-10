#pragma once
#include <cmath>

class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;

public:
    Dyhotomia_class(double a, double b, double eps);
    ~Dyhotomia_class();

    void setAB(double a, double b);
    void setEps(double eps);

    double f(double x);
    int countDyhotomia(double &x);
    int countNewton(double &x);
};
