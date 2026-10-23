
#include <iostream>
#include "simulation.h"

using namespace std;

GardenSimulation::GardenSimulation() {
    soilMoisture = 50.0;
    rainExpected = false;
    simulationDays = 30;
}

void GardenSimulation::simulateSoilMoisture() {
    cout << "Not implemented yet.\n";
}

void GardenSimulation::simulateRainfall() {
    cout << "Not implemented yet.\n";
}

double GardenSimulation::getSoilMoisture() const {
    return soilMoisture;
}

bool GardenSimulation::isRainExpected() const {
    return rainExpected;
}
