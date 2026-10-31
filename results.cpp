
#include <iostream>
#include <fstream>
#include "results.h"

using namespace std;

ResultsManager::ResultsManager() {
    timerWaterUsed = 0.0;
    smartWaterUsed = 0.0;
    simulation = nullptr;
}

// Shows how much water the smart controller saved compared to the timer.
void ResultsManager::compareWaterUsage() {
    cout << "\n===== WATER USAGE COMPARISON =====\n";

    if (timerWaterUsed == 0.0 || smartWaterUsed == 0.0) {
        cout << "Run both the timer controller (3) and smart controller (4) first.\n";
        return;
    }

    double saved = timerWaterUsed - smartWaterUsed;
    int percentSaved = (int)(saved / timerWaterUsed * 100);

    cout << "Timer controller: " << timerWaterUsed << " liters\n";
    cout << "Smart controller: " << smartWaterUsed << " liters\n";
    cout << "Water saved: " << saved << " liters (" << percentSaved << "%)\n";
}

// Saves the results to irrigation_results.csv (opens in Excel).
void ResultsManager::saveResultsToCSV() {
    cout << "\n===== SAVE RESULTS TO CSV =====\n";

    ofstream file("irrigation_results.csv");
    if (!file) {
        cout << "Error: could not create the CSV file.\n";
        return;
    }

    // Water totals
    file << "Controller,Water Used (liters)\n";
    file << "Timer," << timerWaterUsed << "\n";
    file << "Smart," << smartWaterUsed << "\n";
    file << "Saved," << timerWaterUsed - smartWaterUsed << "\n";

    // One row per day, if a simulation has been run
    if (simulation != nullptr && simulation->hasSimulationData()) {
        file << "\nDay,Rain (mm),Rain Tomorrow,Soil Moisture (%)\n";

        for (int day = 1; day <= simulation->getSimulationDays(); day++) {
            file << day << ","
                 << simulation->getRainfallOnDay(day) << ",";
            if (simulation->isRainExpectedOnDay(day)) {
                file << "Yes,";
            } else {
                file << "No,";
            }
            file << simulation->getMoistureOnDay(day) << "\n";
        }
    }

    file.close();
    cout << "Results saved to irrigation_results.csv\n";
}

void ResultsManager::setTimerWaterUsed(double liters) {
    timerWaterUsed = liters;
}

void ResultsManager::setSmartWaterUsed(double liters) {
    smartWaterUsed = liters;
}

void ResultsManager::setSimulation(GardenSimulation* sim) {
    simulation = sim;
}
