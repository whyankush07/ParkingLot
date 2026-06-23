#include "ParkingLot.h"
#include "iostream"

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

void ParkingLot::printAvailability() const {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║       Parking Lot Availability       ║\n";
    std::cout << "╠════════╦══════════╦════════╦═════════╣\n";
    std::cout << "║ Level  ║  Small   ║ Medium ║  Large  ║\n";
    std::cout << "╠════════╬══════════╬════════╬═════════╣\n";

    for (const auto &level : levels)
    {
        auto av = level.getAvailability();
        std::cout << "║   " << level.getLevelId() << "    ║"
                  << std::setw(5) << av[SpotType::SMALL] << "     ║"
                  << std::setw(4) << av[SpotType::MEDIUM] << "    ║"
                  << std::setw(5) << av[SpotType::LARGE] << "    ║\n";
    }
    std::cout << "╚════════╩══════════╩════════╩═════════╝\n\n";
}