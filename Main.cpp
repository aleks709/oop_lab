#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    Triangle t;
    cout << "Введіть координати трикутника:" << endl;
    cout << "A (x y): "; cin >> t.A.x >> t.A.y;
    cout << "B (x y): "; cin >> t.B.x >> t.B.y;
    cout << "C (x y): "; cin >> t.C.x >> t.C.y;

    
    if (t.isDegenerate()) {
        cout << "Трикутник вироджений (площа = 0)!" << endl;
    }

    int n;
    cout << "Скільки точок перевірити? "; cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cout << "Точка " << i + 1 << " (x y): "; cin >> p.x >> p.y;

        if (t.isDegenerate()) {
            // Для виродженого трикутника перевіряємо чи точка лежить на тій самій прямій
            if (t.onBorder(p)) {
                cout << "Точка лежить на виродженому трикутнику (прямій)" << endl;
            } else {
                cout << "Точка не належить виродженому трикутнику" << endl;
            }
        } else {
            if (t.onBorder(p)) {
                cout << "Точка лежить на межі трикутника" << endl;
            } else if (t.contains(p)) {
                cout << "Точка належить трикутнику" << endl;
            } else {
                cout << "Точка не належить трикутнику" << endl;
            }
        }
    }

    return 0;
}
