#include "TransportClasses.h"
#include <iostream>
using namespace std;


int main() {
    cout << "Лабораторна 5. Множинне успадкування" << "\n";
    cout << "Створення об'єкта:" << "\n";

    UniversalTransport machine("Mercedes", 90, 6, 12, 8, "Туристичні роботи");

    cout << "\nІнформація про об'єкт:" << "\n";
    machine.ShowInfo();

    cout << "\nПеревірка virtual успадкування:" << "\n";

    Transport *baseFromLand      = &machine;
    Transport *baseFromPassenger = &machine;
    Transport *baseFromCargo     = &machine;

    cout << "Адреса Transport через LandTransport: "      << baseFromLand      << "\n";
    cout << "Адреса Transport через PassengerTransport: " << baseFromPassenger << "\n";
    cout << "Адреса Transport через CargoTransport: "     << baseFromCargo     << "\n";
    cout << "Всі адреси однакові, бо базовий клас Transport створився один раз." << "\n";

    cout << "\nЗміна даних через різні гілки успадкування:" << "\n";
    LandTransport      *landPart      = &machine;
    PassengerTransport *passengerPart = &machine;
    CargoTransport     *cargoPart     = &machine;

    landPart->SetBrand("MAN");
    passengerPart->SetSpeed(75);

    cout << "Після зміни через різні гілки (linia успадкування):" << "\n";
    cargoPart->ShowTransport();

    cout << "\nПояснення:" << "\n";
    cout << "Клас UniversalTransport успадковується від трьох батьківських класів." << "\n";
    cout << "Усі вони мають спільний базовий клас Transport." << "\n";
    cout << "Завдяки virtual успадкуванню клас Transport створюється тільки один раз." << "\n";
    cout << "Якби virtual не було, виникло б дублювання базового класу Transport." << "\n";

    cout << "\nОб'єкт знищено." << "\n";

    return 0;
}
