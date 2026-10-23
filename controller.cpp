
#include <iostream>
#include <limits>
#include "controller.h"

using namespace std;

IrrigationController::IrrigationController() {
    moistureThreshold = 30.0;
    wateringInterval = 2;
    waterPerSession = 5.0;
}

void IrrigationController::runTimerController() {
    int days;
    double totalWater = 0.0;

    cout << "\n===== TIMER CONTROLLER =====\n";
    cout << "Enter number of simulation days: ";
    cin >> days;

    if (cin.fail() || days <= 0) {
        cout << "Invalid number of days.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "\nWatering every " << wateringInterval
         << " days.\n";

    for (int day = 1; day <= days; day++) {
        if (day % wateringInterval == 0) {
            totalWater += waterPerSession;
            cout << "Day " << day
                 << ": Watering - "
                 << waterPerSession << " liters\n";
        } else {
            cout << "Day " << day
                 << ": No watering\n";
        }
    }

    cout << "\nTotal water used: "
         << totalWater << " liters\n";
}

void IrrigationController::runSmartController() {
    cout << "Not implemented yet.\n";
}

void IrrigationController::changeSettings() {
    cout << "Not implemented yet.\n";
}
