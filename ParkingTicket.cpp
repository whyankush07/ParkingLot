#include <cmath>
#include <ctime>
#include <iostream>
#include "ParkingTicket.h"

double ParkingTicket::CloseTicket() {
    if (isClosed) {
        throw std::runtime_error("Ticket " + ticketId + " is already closed");
    }
    exitTime = std::time(nullptr);
    isClosed = true;
    return CalculateFee();
}

double ParkingTicket::CalculateFee() const {
    time_t end = isClosed ? exitTime : std::time(nullptr);
    double secs = std::difftime(end, entryTime);
    double hours = secs / 3600.0;
    // Minimum 1-hour charge; ceiling for partial hours
    double billable = (hours < 1.0) ? 1.0 : std::ceil(hours);
    return billable * hourlyRate(vehicle->getType());
}