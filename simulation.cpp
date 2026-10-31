
#include <iostream>
#include <cstdlib>
#include <limits>
#include "simulation.h"

using namespace std;

GardenSimulation::GardenSimulation() {
    soilMoisture = 50.0;
    rainExpected = false;
    simulationDays = 30;
    hasData = false;
}

// Makes random rainfall for each day.
// Each day has a 25% chance of rain, between 2 and 15 mm.
void GardenSimulation::simulateRainfall() {
    int days;

    cout << "\n===== RAINFALL SIMULATION =====\n";
    cout << "Enter number of simulation days (30 or more recommended): ";
    cin >> days;

    if (cin.fail() || days <= 0 || days > MAX_DAYS) {
        cout << "Invalid number of days. Enter 1 to " << MAX_DAYS << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    simulationDays = days;

    // Same starting number every time, so every run gives the same rain
    srand(2140);

    for (int i = 0; i < days; i++) {
        if (rand() % 100 < 25) {
            rainfall[i] = 2 + rand() % 14;
        } else {
            rainfall[i] = 0;
        }
        moisture[i] = 0.0;   // filled in by the soil moisture simulation
    }

    hasData = true;

    int rainyDays = 0;
    int totalRain = 0;

    cout << "\nDay\tRain (mm)\tRain tomorrow?\n";
    for (int day = 1; day <= days; day++) {
        cout << day << "\t" << getRainfallOnDay(day) << "\t\t";
        if (isRainExpectedOnDay(day)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

        if (getRainfallOnDay(day) > 0) {
            rainyDays++;
            totalRain += getRainfallOnDay(day);
        }
    }

    rainExpected = isRainExpectedOnDay(days);

    cout << "\nRainy days: " << rainyDays << " of " << days << "\n";
    cout << "Total rainfall: " << totalRain << " mm\n";
}

// Shows how soil moisture changes each day with rain and no watering.
void GardenSimulation::simulateSoilMoisture() {
    cout << "\n===== SOIL MOISTURE SIMULATION =====\n";

    // Moisture depends on rain, so make the rain first if needed
    if (!hasData) {
        cout << "No rainfall data yet. Running the rainfall simulation first.\n";
        simulateRainfall();
        if (!hasData) {
            return;
        }
    }

    double current = 50.0;
    int dryDays = 0;

    cout << "\nStarting moisture: " << current << "% (no watering)\n";
    cout << "\nDay\tRain (mm)\tMoisture (%)\tStatus\n";

    for (int day = 1; day <= simulationDays; day++) {
        current = nextMoisture(current, day, 0.0);
        moisture[day - 1] = current;

        cout << day << "\t" << getRainfallOnDay(day) << "\t\t" << current << "\t\t";
        if (current < 30.0) {
            cout << "Dry\n";
            dryDays++;
        } else {
            cout << "OK\n";
        }
    }

    soilMoisture = current;

    cout << "\nDry days (below 30%): " << dryDays << " of " << simulationDays << "\n";
    cout << "Final moisture: " << soilMoisture << "%\n";
}

double GardenSimulation::getSoilMoisture() const {
    return soilMoisture;
}

bool GardenSimulation::isRainExpected() const {
    return rainExpected;
}

bool GardenSimulation::hasSimulationData() const {
    return hasData;
}

int GardenSimulation::getSimulationDays() const {
    return simulationDays;
}

int GardenSimulation::getRainfallOnDay(int day) const {
    if (!hasData || day < 1 || day > simulationDays) {
        return 0;
    }
    return rainfall[day - 1];
}

// The forecast: will it rain on the next day?
bool GardenSimulation::isRainExpectedOnDay(int day) const {
    return getRainfallOnDay(day + 1) > 0;
}

double GardenSimulation::getMoistureOnDay(int day) const {
    if (!hasData || day < 1 || day > simulationDays) {
        return 0.0;
    }
    return moisture[day - 1];
}

// Moisture at the end of a day:
// lose 6% to drying, gain 1% per mm of rain, gain 3% per liter of water.
// The result stays between 0% and 100%.
double GardenSimulation::nextMoisture(double currentMoisture, int day,
                                      double waterLiters) const {
    double result = currentMoisture - 6.0
                  + getRainfallOnDay(day) * 1.0
                  + waterLiters * 3.0;

    if (result < 0.0) {
        result = 0.0;
    }
    if (result > 100.0) {
        result = 100.0;
    }
    return result;
}
