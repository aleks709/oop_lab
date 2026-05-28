#include "Header.h"
#include <iostream>

int main() {

    std::cout << "Обчислення кореня рівняння методами дихотомії та Ньютона" << std::endl;

    Dyhotomia *solver = new Dyhotomia(); //обʼєкт

    solver->setInterval(0.0, 2.0);
    solver->setPrecision(0.00001);
    solver->setInitialGuess(50.0); 

    double res_dichotomy = solver->runDichotomy();
    std::cout << "Результат дихотомії: " << res_dichotomy << "\n" << std::endl;
    double res_newton = solver->runNewton();
    std::cout << "Результат Ньютона: " << res_newton << std::endl;   

    delete solver;

    return 0;
}
