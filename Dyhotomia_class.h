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

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    double f(double x);
    int countDyhotomia(double &x);
    int countNewton(double &x);
};
