#include "ParkingLot.h"
#include <iostream>

void ParkingLot::addLevel(int levelId, int smallSpots, int mediumSpots, int largeSpots) {
    levels.emplace_back(levelId);
    auto& level = levels.back();
    int index = 0;

    auto prefix = "L" + std::to_string(levelId) + "-";

    for (int i = 0; i < smallSpots; i++) {
        level.addSpot(prefix + "S" + std::to_string(++index), SpotType::SMALL);
    }
    for (int i = 0; i < mediumSpots; i++) {
        level.addSpot(prefix + "M" + std::to_string(++index), SpotType::MEDIUM);
    }
    for (int i = 0; i < largeSpots; i++) {
        level.addSpot(prefix + "L" + std::to_string(++index), SpotType::LARGE);
    }
}

std::string ParkingLot::parkVehicle(Vehicle& vehicle) {
    // 1. find ParkingSpot
    // 2. Generate Ticket
    for (auto& level: levels) {
        ParkingSpot* spot = level.findSpotForVehicle(vehicle.getType());
        if (spot) {
            spot->park();
            level.markOccupied(spot->getSpotType());


            std::string ticketId_ = generateTicketId();
            activeTickets.emplace(
                ticketId_,
                ParkingTicket(ticketId_, &vehicle, spot)
            );

            std::cout << "[ENTRY] Ticket: " << ticketId_
                          << " | " << vehicleTypeStr(vehicle.getType())
                          << " (" << vehicle.getLicense() << ")"
                           << " -> Spot " << spot->getSpotId()
                          << " | Level " << level.getLevelId()
                          << " | Entry: " << ParkingTicket::formatTime(
                                activeTickets.at(ticketId_).getEntry())
                          << "\n";

            return ticketId_;
        }
    }
    throw std::runtime_error("No available spot for " +
                                  vehicleTypeStr(vehicle.getType()));
}

double ParkingLot::exitVehicle(const std::string& ticketId_) {
    // 1. validate ticket
    // 2. free spot, mark level unoccupied
    auto it = activeTickets.find(ticketId_);
    if (it == activeTickets.end()) {
        throw std::runtime_error("Ticket not found: " + ticketId_);
    }

    ParkingTicket& ticket = it->second;
    if (ticket.getIsClosed()) {
        throw std::runtime_error("Ticket already used: " + ticketId_);
    }

    ParkingSpot* spot = ticket.getSpot();
    for (auto& level: levels) {
        if (spot->getSpotId().find("L" + std::to_string(level.getLevelId())) == 0) {
            spot->free();
            level.markFree(spot->getSpotType());
            break;
        }
    }

    double fee = ticket.CloseTicket();

    std::cout << "[EXIT]  Ticket: " << ticketId_
                  << " | " << vehicleTypeStr(ticket.getVehicle()->getType())
                  << " (" << ticket.getVehicle()->getLicense() << ")"
                  << " | Spot " << spot->getSpotId()
                  << " | Entry: " << ParkingTicket::formatTime(ticket.getEntry())
                  << " | Exit: "  << ParkingTicket::formatTime(ticket.getExit())
                   << " | Fee: Rs."  << std::fixed << std::setprecision(2) << fee
                  << "\n";

    activeTickets.erase(it);

    return fee;
}

void ParkingLot::printAvailability() const {
    std::cout << "\n--- Availability ---\n";
    for (const auto &level : levels)
    {
        auto av = level.getAvailability();
        std::cout << "  Level " << level.getLevelId()
                  << ": Small=" << av[SpotType::SMALL]
                  << "  Medium=" << av[SpotType::MEDIUM]
                  << "  Large=" << av[SpotType::LARGE] << "\n";
    }
    std::cout << "\n";
}