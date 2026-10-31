
#ifndef SIMULATION_H
#define SIMULATION_H

const int MAX_DAYS = 365;

class GardenSimulation {
private:
    double soilMoisture;
    bool rainExpected;
    int simulationDays;

    int rainfall[MAX_DAYS];       // mm of rain on each day
    double moisture[MAX_DAYS];    // soil moisture (%) at the end of each day
    bool hasData;                 // true after the rainfall simulation runs

public:
    GardenSimulation();

    void simulateSoilMoisture();
    void simulateRainfall();

    double getSoilMoisture() const;
    bool isRainExpected() const;

    // Daily data used by the controllers and results (day 1 is the first day)
    bool hasSimulationData() const;
    int getSimulationDays() const;
    int getRainfallOnDay(int day) const;
    bool isRainExpectedOnDay(int day) const;
    double getMoistureOnDay(int day) const;
    double nextMoisture(double currentMoisture, int day, double waterLiters) const;
};

#endif
