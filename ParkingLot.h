#pragma once
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <atomic>
#include <iostream>
#include <iomanip>
#include "Vehicle.h"
#include "ParkingLevel.h"
#include "ParkingTicket.h"

class ParkingLot {
private:
    ParkingLot() = default;
    std::vector<ParkingLevel> levels;

    std::atomic<int> ticketCounter{0};
    std::map<std::string, ParkingTicket> activeTickets;

    std::string generateTicketId() {
        return "TKT" + std::to_string(++ticketCounter);
    }

public:
// singleton-pattern
    static ParkingLot& getInstance() {
        static ParkingLot instance;
        return instance;
    }

    ParkingLot(const ParkingLot&) = delete;
    ParkingLot& operator=(const ParkingLot&) = delete;

    void addLevel(int levelId, int smallSpots, int mediumSpots, int largeSpots);
    // core operations
    std::string parkVehicle(Vehicle& vehicle);
    double exitVehicle(const std::string& ticketId);

    void printAvailability() const;
};