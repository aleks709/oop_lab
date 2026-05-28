#pragma once
#include <cmath>

class Dyhotomia { // клас
private:
    double lower_x, upper_x;
    double search_eps;
    double start_node;

    double evaluateFunction(double x); // метод приват
    double calculateDerivative(double x);

public:
    Dyhotomia(); //конструктор
    ~Dyhotomia(); //деструктор

    void setInterval(double left, double right); //метод паблік
    void setPrecision(double eps_val);
    void setInitialGuess(double guess_val);
    
    double runDichotomy();
    double runNewton();
};