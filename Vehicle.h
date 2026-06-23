#pragma once
#include "Enums.h"

// abstract class
class Vehicle {
public:
    Vehicle(std::string plate, VehicleType type) : licencePlate(std::move(plate)), vtype(type) {};

    virtual ~Vehicle() = default;

    virtual VehicleType getType() const = 0;
    const std::string &getLicence() const { return licencePlate; }

protected:
    VehicleType vtype;
    std::string licencePlate;
};

class Bike : public Vehicle {
    explicit Bike(std::string plate) : Vehicle(std::move(plate), VehicleType::BIKE) {}
    VehicleType getType() const override { return VehicleType::BIKE; }
};

class Car : public Vehicle {
    explicit Car(std::string plate) : Vehicle(std::move(plate), VehicleType::CAR) {}
    VehicleType getType() const override { return VehicleType::CAR; }
};

class Truck : public Vehicle {
    explicit Truck(std::string plate) : Vehicle(std::move(plate), VehicleType::TRUCK) {}
    VehicleType getType() const override { return VehicleType::TRUCK; }
};