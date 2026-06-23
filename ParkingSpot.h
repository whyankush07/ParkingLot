#pragma once
#include "Vehicle.h"

class ParkingSpot {
private:
    std::string spotId;
    SpotType type;
    bool isFree_;

public:
    ParkingSpot(std::string id, SpotType stype) : spotId(std::move(id)), type(stype), isFree_(true) {}

    bool canFit(VehicleType vt);

    void park();
    void free();

    const std::string& getSpotId() { return spotId; }
    SpotType getSpotType() { return type; }
    bool isFree() { return isFree_; }
};