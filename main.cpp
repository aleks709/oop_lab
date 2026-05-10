#include <iostream>
#include "Dyhotomia_class.h"

int main() {
    Dyhotomia_class *obj = new Dyhotomia_class(0.4, 1.0, 0.0001);

    double x = 0;

    if (obj->countDyhotomia(x) == 0) {
        std::cout << "Method Dyhotomia: x = " << x << std::endl;
    } else {
        std::cout << "Method Dyhotomia: no root found" << std::endl;
    }

    if (obj->countNewton(x) == 0) {
        std::cout << "Method Newton:    x = " << x << std::endl;
    } else {
        std::cout << "Method Newton: no root found" << std::endl;
    }

    delete obj;
    return 0;
}
