#include "TransportClasses.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Лабораторна 5. Множинне успадкування ===\n\n";

    //  Звичайні класи з лаб. 4 
    Car car("Toyota", 120);
    Bus bus("Bogdan", 70, 40);
    Truck truck("MAN", 80, 12);
    ElectricCar electricCar("Tesla", 85);
    electricCar.SetSpeed(90, 110);

    cout << "\n--- Поліморфізм (лаб. 4) ---\n";
    Transport *transport;

    transport = &car;         transport->ShowInfo(); transport->Move(); cout << "\n";
    transport = &bus;         transport->ShowInfo(); transport->Move(); cout << "\n";
    transport = &truck;       transport->ShowInfo(); transport->Move(); cout << "\n";
    transport = &electricCar; transport->ShowInfo(); transport->Move(); cout << "\n";

    //  Ромбоподібне наслідування (лаб. 5) 
    cout << "--- Ромбоподібне наслідування ---\n";
    cout << "Створення BusTruck:\n";

    BusTruck bt("Mercedes", 90, 20, 5, "Туристичні перевезення");

    cout << "\nІнформація:\n";
    bt.ShowInfo();
    bt.Move();

    cout << "\n--- Перевірка: Transport створився ОДИН раз ---\n";
    Transport *t1 = static_cast<Bus*>(&bt);
    Transport *t2 = static_cast<Truck*>(&bt);
    cout << "Адреса Transport через Bus:   " << t1 << "\n";
    cout << "Адреса Transport через Truck: " << t2 << "\n";
    cout << (t1 == t2 ? "Адреси однакові — virtual спрацювало!" : "Адреси різні — помилка!") << "\n";

    cout << "\nЗнищення об'єктів:\n";
    return 0;
}
