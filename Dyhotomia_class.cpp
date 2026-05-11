#include "Dyhotomia_class.h"
#include <cmath>

Dyhotomia_class::Dyhotomia_class(double a, double b, double eps)
    : a(a), b(b), eps(eps) {}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    this->a = vol_a;
    this->b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    this->eps = vol_eps;
}

// f(x) = x + sqrt(x) + x^(1/3) - 2.5  (варіант 9)
double Dyhotomia_class::f(double x) {
    return x + sqrt(x) + pow(x, 1.0 / 3.0) - 2.5;
}

int Dyhotomia_class::countDyhotomia(double &x) {
    double left = a;
    double right = b;
    double c;

    if (f(left) * f(right) > 0) {
        return -1;
    }

    while (fabs(right - left) > eps) {
        c = (left + right) / 2.0;

        if (f(left) * f(c) < 0) {
            right = c;
        } else {
            left = c;
        }
    }

    x = (left + right) / 2.0;
    return 0;
}

int Dyhotomia_class::countNewton(double &x) {
    double x_next;
    double h = 0.00001;
    double derivative;
    int maxIterations = 10000; // захист від нескінченного циклу
    int iteration = 0;

    x = b;

    while (iteration < maxIterations) {
        derivative = (f(x + h) - f(x)) / h;

        if (derivative == 0) {
            return -1;
        }

        x_next = x - f(x) / derivative;

        if (fabs(x_next - x) < eps) {
            x = x_next;
            return 0;
        }

        x = x_next;
        iteration++;
    }

    return -1; // не знайшов корінь за maxIterations ітерацій
}
