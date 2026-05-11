#pragma once
#include <string>
using namespace std;

class Transport {
protected:
    string brand;
    int speed;

public:
    Transport();
    Transport(string b, int s);
    virtual ~Transport();

    int SetBrand(string b);
    int SetSpeed(int s);
    int SetSpeed(int minSpeed, int maxSpeed);

    virtual void ShowInfo() const;
    virtual void Move() const;
};

class Car : public Transport {
public:
    Car(string b, int s);
    void ShowInfo() const;
    void Move() const;
};

// virtual public Transport  для уникнення diamond problem
class Bus : virtual public Transport {
protected:
    int passengers;

public:
    Bus();
    Bus(string b, int s, int p);
    virtual ~Bus();

    int SetPassengers(int p);
    void ShowInfo() const;
    void Move() const;
};

// virtual public Transport  для уникнення diamond problem
class Truck : virtual public Transport {
protected:
    int loadCapacity;

public:
    Truck();
    Truck(string b, int s, int load);
    virtual ~Truck();

    int SetLoadCapacity(int load);
    void ShowInfo() const;
    void Move() const;
};

class ElectricCar : public Transport {
private:
    int battery;

public:
    ElectricCar(string b, int batteryPower);
    int SetBattery(int batteryPower);
    void ShowInfo() const;
    void Move() const;
};

// Ромбоподібне наслідування: Bus + Truck -> один Transport
class BusTruck : public Bus, public Truck {
private:
    string purpose;

public:
    BusTruck(string b, int s, int p, int load, string purp);
    virtual ~BusTruck();

    int SetPurpose(string purp);
    void ShowInfo() const;
    void Move() const;
};
