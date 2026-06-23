#include "ParkingLevel.h"
#include <iostream>

void ParkingLevel::addSpot(const std::string& id, SpotType type) {
    ParkingSpot spot(id, type);
    spots.emplace_back(spot);
    freeCount[type]++;
}

ParkingSpot* ParkingLevel::findSpotForVehicle(VehicleType vt) {
    // helper function: Priority order: best-fit first
    auto tryType = [&](SpotType st) -> ParkingSpot* {
        if (freeCount.count(st) && freeCount[st] > 0) {
            for (auto& spot : spots) {
                if (spot.getSpotType() == st && spot.canFit(vt)) return &spot;
            }
        }
        return nullptr;
    };

    ParkingSpot* found = nullptr;
    switch (vt) {
        case VehicleType::BIKE:
            found = tryType(SpotType::SMALL);
            if (!found) found = tryType(SpotType::MEDIUM);
            if (!found) found = tryType(SpotType::LARGE);
            break;
        case VehicleType::CAR:
            found = tryType(SpotType::MEDIUM);
            if (!found) found = tryType(SpotType::LARGE);
            break;
        case VehicleType::TRUCK:
            found = tryType(SpotType::LARGE);
            break;
    }
    return found;
}

void ParkingLevel::markOccupied(SpotType type) {
    if (freeCount[type] <= 0) throw std::logic_error("Free count underflow");
    freeCount[type]--;
}

void ParkingLevel::markFree(SpotType type) {
    freeCount[type]++;
}