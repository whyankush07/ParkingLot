#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include <stdexcept>
#include <string>
#include <iomanip>
#include <sstream>
#include "ctime"

class ParkingTicket {
private:
    std::string ticketId;
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryTime;
    time_t exitTime;
    double fee;
    bool isClosed;

public:
    ParkingTicket(std::string id, Vehicle* v, ParkingSpot* s)
    : ticketId(std::move(id))
    , vehicle(v)
    , spot(s)
    , entryTime(std::time(nullptr))
    , exitTime(0)
    , fee(0.0)
    ,isClosed(false) {};

    double CloseTicket();
    double CalculateFee() const;

    // Accessors
    const std::string& getId()       const { return ticketId; }
    Vehicle*           getVehicle()  const { return vehicle; }
    ParkingSpot*       getSpot()     const { return spot; }
    time_t             getEntry()    const { return entryTime; }
    time_t             getExit()     const { return exitTime; }
    double             getFee()      const { return fee; }
    bool               getIsClosed()   const { return isClosed; }

    static std::string formatTime(time_t t) {
        std::tm* tm = std::localtime(&t);
        std::ostringstream ss;
        ss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};