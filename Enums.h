#pragma once
#include "string"

enum class VehicleType { BIKE, CAR, TRUCK };
enum class SpotType { SMALL, MEDIUM, LARGE };

inline std::string vehicleTypeStr(VehicleType t) {
    switch (t) {
        case VehicleType::BIKE: return "Bike";
        case VehicleType::CAR:  return "Car";
        case VehicleType::TRUCK: return "Truck";
        default: return "Unknown";
    }
}

inline std::string spotTypeStr(SpotType t) {
    switch (t) {
        case SpotType::SMALL: return "Small";
        case SpotType::MEDIUM: return "Medium";
        case SpotType::LARGE: return "Large";
        default: return "Unknown";
    }
}

inline double hourlyRate(VehicleType t) {
    switch (t) {
        case VehicleType::BIKE: return 10.0;
        case VehicleType::CAR: return 20.0;
        case VehicleType::TRUCK: return 40.0;
        default: return 0.0;
    }
}