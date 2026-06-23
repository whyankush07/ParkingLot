#pragma once
#include "string"

enum class VehicleType { BIKE, CAR, TRUCK };
enum class SpotType { SMALL, MEDIUM, LARGE };

inline std::string VehicleTypeStr(VehicleType t) {
    switch (t) {
        case VehicleType::BIKE: return "Bike";
        case VehicleType::CAR:  return "Car";
        case VehicleType::TRUCK: return "Truck";
    }
}

inline std::string SpotTypeStr(SpotType t) {
    switch (t) {
        case SpotType::SMALL: return "Small";
        case SpotType::MEDIUM: return "Medium";
        case SpotType::LARGE: return "Large";
    }
}

inline double hourlyRate(VehicleType t) {
    switch (t) {
        case VehicleType::BIKE: return 10.0;
        case VehicleType::CAR: return 20.0;
        case VehicleType::TRUCK: return 40.0;
    }
}