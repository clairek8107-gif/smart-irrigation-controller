
#ifndef RESULTS_H
#define RESULTS_H

#include "simulation.h"

class ResultsManager {
private:
    double timerWaterUsed;
    double smartWaterUsed;
    GardenSimulation* simulation;   // points to the garden data for the CSV

public:
    ResultsManager();

    void compareWaterUsage();
    void saveResultsToCSV();

    // The controllers call these to give their total water use
    void setTimerWaterUsed(double liters);
    void setSmartWaterUsed(double liters);
    void setSimulation(GardenSimulation* sim);
};

#endif
