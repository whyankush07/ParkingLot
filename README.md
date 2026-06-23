# Parking Lot LLD

A low-level design implementation of a multi-level parking lot system in modern C++ (C++17).

## Features

- **Multi-level parking** with configurable spot counts per level
- **Vehicle hierarchy** — `Bike`, `Car`, `Truck` (extensible via abstract `Vehicle` base)
- **Best-fit spot allocation** — each vehicle is assigned the smallest spot it can fit (e.g. bike → SMALL first, then MEDIUM, then LARGE)
- **Ticket-based entry/exit** — generates unique ticket IDs, tracks entry/exit timestamps, calculates fees
- **Hourly billing** — ₹10/hr (Bike), ₹20/hr (Car), ₹40/hr (Truck); minimum 1-hour charge, partial hours rounded up
- **Singleton `ParkingLot`** — single instance manages all levels and active tickets
- **Availability display** — prints a formatted table of free spots per level

## Class Overview

| Class | Responsibility |
|---|---|
| `Vehicle` (abstract) | Base class with license plate and type |
| `Bike`, `Car`, `Truck` | Concrete vehicle types |
| `ParkingSpot` | A single spot with a type (SMALL/MEDIUM/LARGE) and free/occupied state |
| `ParkingLevel` | A floor of spots; finds the best-fit spot for a vehicle |
| `ParkingLot` | Singleton facade; manages levels, parking, and exit flow |
| `ParkingTicket` | Tracks vehicle, spot, entry/exit times, and fee calculation |

## Build & Run

```bash
g++ -std=c++17 -Wall -Wextra -o parking_lot main.cpp *.cpp
./parking_lot
```

Or use the provided script:

```bash
./run.sh
```

## Sample Output

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Setting up Parking Lot (3 levels)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

╔══════════════════════════════════════╗
║       Parking Lot Availability       ║
╠════════╦══════════╦════════╦═════════╣
║ Level  ║  Small   ║ Medium ║  Large  ║
╠════════╬══════════╬════════╬═════════╣
║   0    ║    4     ║   6    ║    2    ║
║   1    ║    3     ║   4    ║    6    ║
║   2    ║    3     ║   2    ║    1    ║
╚════════╩══════════╩════════╩═════════╝

[ENTRY] Ticket: TKT1 | Bike (DL-01-BK-1001) → Spot L0-S1 | Level 0 | Entry: 2026-06-23 12:00:00
...
```
