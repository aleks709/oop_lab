#include "Header.h"
#include <cmath>
#include <iostream>

Dyhotomia::Dyhotomia() {} //конструктор

Dyhotomia::~Dyhotomia() { //десктруктор
    std::cout << "Об'єкт класу Dyhotomia видалено." << std::endl;
}

double Dyhotomia::evaluateFunction(double x) { //метод private
        return (x * x) / 4.0 + x - 1.2502;
    }

double Dyhotomia::calculateDerivative(double x) {
        const double delta = 1e-7;
        return (evaluateFunction(x + delta) - evaluateFunction(x)) / delta;
    }

void Dyhotomia::setInterval(double left, double right) { // public метод
    lower_x = left;
    upper_x = right;
}

void Dyhotomia::setPrecision(double eps_val) {
    search_eps = eps_val;
}

void Dyhotomia::setInitialGuess(double guess_val) {
    start_node = guess_val;
}

double Dyhotomia::runDichotomy() {
    double x1 = lower_x;
    double x2 = upper_x;
    double middle_point;
    int loop_count = 0;

    if (!(evaluateFunction(x1) * evaluateFunction(x2) >= 0)) {
        while (std::abs(x2 - x1) > search_eps) {
            loop_count++;
            middle_point = (x1 + x2) / 2.0;
            
            if (evaluateFunction(x1) * evaluateFunction(middle_point) < 0)
                x2 = middle_point;
            else
                x1 = middle_point;
        }
        std::cout << "[Dichotomy]: Розрахунок завершено за " << loop_count << " кроків." << std::endl;
        return (x1 + x2) / 2.0;
    }
    else {
        std::cout << "[Dichotomy]: Неможливо знайти корінь на цьому проміжку." << std::endl;
        return 0.0;
    }
}

double Dyhotomia::runNewton() {
    double current_root = start_node;
    double next_root;

    for (int iter = 0; iter < 100; iter++) {
        std::cout << "  Крок №" << (iter + 1) << " -> x = " << current_root 
                  << ", f(x) = " << evaluateFunction(current_root) << std::endl;
        
        double f_prime = this->calculateDerivative(current_root);

        if (std::abs(f_prime) < 1e-12) {
            std::cout << "[Newton]: Помилка: нульова похідна" << std::endl;
            break;
        }

        next_root = current_root - evaluateFunction(current_root) / f_prime;

        if (std::abs(next_root - current_root) < search_eps) {
            std::cout << "[Newton]: Збіжність досягнута за " << (iter + 1) << " кроків." << std::endl;
            return next_root;
        }

        current_root = next_root;
    }
    return current_root;
}