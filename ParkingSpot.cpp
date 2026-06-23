#include "iostream"
#include "ParkingSpot.h"

bool ParkingSpot::canFit(VehicleType vt) {
    if (!isFree_) return false;
    switch (type) {
        case SpotType::SMALL: return vt == VehicleType::BIKE;
        case SpotType::MEDIUM: return vt == VehicleType::BIKE || vt == VehicleType::CAR;
        case SpotType::LARGE: return true;
    }
    return false;
};

void ParkingSpot::park() {
    if (!isFree_) throw std::runtime_error("Spot " + spotId + " occupied!");
    isFree_ = false;
}

void ParkingSpot::free() {
    if (isFree_) throw std::runtime_error("Spot " + spotId + " was alrady free!");
    isFree_ = true;
}