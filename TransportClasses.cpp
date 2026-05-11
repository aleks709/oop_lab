#include "TransportClasses.h"
#include <iostream>
using namespace std;

// --- Transport ---

Transport::Transport() {
    brand = "Невідома марка";
    speed = 0;
    cout << "Конструктор Transport\n";
}

Transport::Transport(string b, int s) {
    brand = b;
    speed = s;
    cout << "Конструктор Transport\n";
}

Transport::~Transport() {
    cout << "Деструктор Transport\n";
}

int Transport::SetBrand(string b) { brand = b; return 1; }
int Transport::SetSpeed(int s) { speed = s; return 1; }
int Transport::SetSpeed(int minSpeed, int maxSpeed) {
    speed = (minSpeed + maxSpeed) / 2;
    return 1;
}

void Transport::ShowInfo() const {
    cout << "Транспорт марки " << brand << ", швидкість " << speed << " км/год.\n";
}

void Transport::Move() const {
    cout << "Транспорт рухається.\n";
}

// --- Car ---

Car::Car(string b, int s) : Transport(b, s) {}

void Car::ShowInfo() const {
    cout << "Автомобіль марки " << brand << ", швидкість " << speed << " км/год.\n";
}

void Car::Move() const {
    cout << "Автомобіль іде по дорозі.\n";
}

// --- Bus ---

Bus::Bus() : Transport() {
    passengers = 0;
    cout << "Конструктор Bus\n";
}

Bus::Bus(string b, int s, int p) : Transport(b, s) {
    passengers = p;
    cout << "Конструктор Bus\n";
}

Bus::~Bus() {
    cout << "Деструктор Bus\n";
}

int Bus::SetPassengers(int p) { passengers = p; return 1; }

void Bus::ShowInfo() const {
    cout << "Автобус марки " << brand << ", швидкість " << speed
         << " км/год, пасажирів " << passengers << ".\n";
}

void Bus::Move() const {
    cout << "Автобус зупиняється на зупинках.\n";
}

// --- Truck ---

Truck::Truck() : Transport() {
    loadCapacity = 0;
    cout << "Конструктор Truck\n";
}

Truck::Truck(string b, int s, int load) : Transport(b, s) {
    loadCapacity = load;
    cout << "Конструктор Truck\n";
}

Truck::~Truck() {
    cout << "Деструктор Truck\n";
}

int Truck::SetLoadCapacity(int load) { loadCapacity = load; return 1; }

void Truck::ShowInfo() const {
    cout << "Вантажівка марки " << brand << ", швидкість " << speed
         << " км/год, вантажність " << loadCapacity << " тонн.\n";
}

void Truck::Move() const {
    cout << "Вантажівка перевозить вантаж.\n";
}

// --- ElectricCar ---

ElectricCar::ElectricCar(string b, int batteryPower) : Transport(b, 0) {
    battery = batteryPower;
}

int ElectricCar::SetBattery(int batteryPower) { battery = batteryPower; return 1; }

void ElectricCar::ShowInfo() const {
    cout << "Електромобіль марки " << brand << ", батарея " << battery
         << " кВт*год, швидкість " << speed << " км/год.\n";
}

void ElectricCar::Move() const {
    cout << "Електромобіль іде майже безшумно.\n";
}

// --- BusTruck ---
// При virtual наслідуванні конструктор Transport викликається тут, один раз

BusTruck::BusTruck(string b, int s, int p, int load, string purp)
    : Transport(b, s), Bus(), Truck() {
    passengers = p;
    loadCapacity = load;
    purpose = purp;
    cout << "Конструктор BusTruck\n";
}

BusTruck::~BusTruck() {
    cout << "Деструктор BusTruck\n";
}

int BusTruck::SetPurpose(string purp) { purpose = purp; return 1; }

void BusTruck::ShowInfo() const {
    cout << "Автобус-вантажівка марки " << brand << ", швидкість " << speed
         << " км/год, пасажирів " << passengers
         << ", вантажність " << loadCapacity << " тонн"
         << ", призначення: " << purpose << ".\n";
}

void BusTruck::Move() const {
    cout << "Автобус-вантажівка перевозить і людей, і вантаж.\n";
}
