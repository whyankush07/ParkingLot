#pragma once
#include "Vehicle.h"

class ParkingSpot {
private:
    std::string spotId;
    SpotType type;
    bool isFree;

public:
    ParkingSpot(std::string id, SpotType stype) : spotId(std::move(id)), type(stype) {}

    bool canFit(VehicleType vt);

    void park();
    void free();

    const std::string& getSpotId() { return spotId; }
    SpotType getSpotType() { return type; }
    bool getIsFree() { return isFree; }
};