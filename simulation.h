
#ifndef SIMULATION_H
#define SIMULATION_H

class GardenSimulation {
private:
    double soilMoisture;
    bool rainExpected;
    int simulationDays;

public:
    GardenSimulation();

    void simulateSoilMoisture();
    void simulateRainfall();

    double getSoilMoisture() const;
    bool isRainExpected() const;
};

#endif
