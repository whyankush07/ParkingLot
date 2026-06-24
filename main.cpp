#include <iostream>
#include <windows.h>
#include "ParkingLot.h"

void separator(const std::string& title) {
    std::cout << "\n============================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================\n";
}

int main() {

    ParkingLot& lot = ParkingLot::getInstance();
    separator("Setting up Parking Lot (3 levels)");
    
    lot.addLevel(0, 4, 6, 2);
    lot.addLevel(1, 3, 4, 6);
    lot.addLevel(2, 3, 2, 1);
    
    lot.printAvailability();

    separator("Parking Vehicles");

    Bike  b1("DL-01-BK-1001");
    Car   c1("DL-02-CA-2001");
    Car   c2("DL-02-CA-2002");
    Truck t1("HR-03-TR-3001");
    Bike  b2("UP-01-BK-1002");
    Car   c3("DL-02-CA-2003");

    std::vector<std::string> tickets;
 
    try {
        tickets.push_back(lot.parkVehicle(b1));  
        tickets.push_back(lot.parkVehicle(c1));
        tickets.push_back(lot.parkVehicle(c2));
        tickets.push_back(lot.parkVehicle(t1));
        tickets.push_back(lot.parkVehicle(b2));
        tickets.push_back(lot.parkVehicle(c3));
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << "\n";
    }
 
    lot.printAvailability();

    separator("Simulating time passing (2 sec)...");
    Sleep(2000);

    separator("Exiting Vehicles");

    double totalRevenue = 0.0;
    for (const auto& tid : tickets) {
        try {
            totalRevenue += lot.exitVehicle(tid);
        } catch (const std::exception& e) {
            std::cerr << "[ERROR] " << e.what() << "\n";
        }
    }
 
    std::cout << "\nTotal Revenue: Rs." << std::fixed
              << std::setprecision(2) << totalRevenue << "\n";
 
    lot.printAvailability();
 
    separator("Edge Case: Fill all truck spots");
 
    Truck t2("MH-03-TR-3002");
    Truck t3("MH-03-TR-3003");
    Truck t4("MH-03-TR-3004");
    Truck t5("MH-03-TR-3005");  // should fail — no large spots
 
    std::vector<std::string> truckTickets;
    for (auto* t : {&t2, &t3, &t4}) {
        try {
            truckTickets.push_back(lot.parkVehicle(*t));
        } catch (const std::exception& e) {
            std::cerr << "[EXPECTED ERROR] " << e.what() << "\n";
        }
    }
 
    std::cout << "\nTrying to park 4th truck (no LARGE spots left):\n";
    try {
        lot.parkVehicle(t5);
    } catch (const std::exception& e) {
        std::cerr << "[EXPECTED ERROR] " << e.what() << "\n";
    }
 
    lot.printAvailability();
 
    for (const auto& tid : truckTickets)
        lot.exitVehicle(tid);
 
    // ── Edge case: double-exit same ticket ────────────
    separator("Edge Case: Double-exit same ticket");
    Bike b3("KA-01-BK-9001");
    std::string bid = lot.parkVehicle(b3);
    lot.exitVehicle(bid);
    try {
        lot.exitVehicle(bid);  // should throw
    } catch (const std::exception& e) {
        std::cerr << "[EXPECTED ERROR] " << e.what() << "\n";
    }
 
    separator("All scenarios complete ✓");

    return 0;
}