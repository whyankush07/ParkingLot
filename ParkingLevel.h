#pragma once
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include "ParkingSpot.h"

class ParkingLevel {    
private:
    int                      levelId;
    std::vector<ParkingSpot> spots;
    std::map<SpotType, int>  freeCount;

public:
    explicit ParkingLevel(int levelId) : levelId(levelId) {}

    void addSpot(const std::string& id, SpotType type);

    ParkingSpot* findSpotForVehicle(VehicleType vt);

    void markOccupied(SpotType type);

    void markFree(SpotType type);

    int  getLevelId() const { return levelId; }

    // Returns {SMALL: free, MEDIUM: free, LARGE: free}
    std::map<SpotType, int> getAvailability() const { return freeCount; }

    int totalFreeSpots() const {
        int total = 0;
        for (auto& kv : freeCount) total += kv.second;
        return total;
    }
};