# Smart Irrigation Controller

## Project Overview

This project is a C++ smart irrigation controller that simulates garden watering based on soil moisture and expected rainfall. The goal is to compare a smart watering system with a traditional timer-based controller to determine potential water savings.

The program uses a text-based interface and simulated data, so no physical hardware is required.

## Team Members

- Claire — Project Leader, Soil Moisture and Rainfall Simulation, Results and CSV Output
- Nyesha — Timer Controller, Smart Controller, Main Menu, and Settings

## Features

1. Soil Moisture Simulation — Stub
2. Rainfall Simulation — Stub
3. Timer Controller — Implemented
4. Smart Controller — Stub
5. Compare Water Usage — Stub
6. Save Results to CSV — Stub
7. Change Settings — Stub
8. Exit — Implemented

Unfinished features currently display "Not implemented yet."

## File Structure

- `main.cpp` — Main menu and switch statement
- `controller.h` — IrrigationController class declaration
- `controller.cpp` — Timer controller implementation and other controller stubs
- `simulation.h` — GardenSimulation class declaration
- `simulation.cpp` — Simulation stubs
- `results.h` — ResultsManager class declaration
- `results.cpp` — Results and CSV stubs

## Build Instructions

Requirements:
- C++17-compatible compiler (g++)
- Terminal or VS Code

Compile using:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp controller.cpp simulation.cpp results.cpp -o irrigation
```

Run using:

```bash
./irrigation
```

## Current Implementation

The timer controller waters the garden every two days, using five liters per watering session.

For a 10-day simulation:
- Watering days: 2, 4, 6, 8, 10
- Total water used: 25 liters

## Future Development

- Complete soil moisture and rainfall simulations.
- Implement smart watering decisions.
- Compare water consumption between controllers.
- Export results to CSV.
- Add configurable watering settings.
- Test and debug the completed program.