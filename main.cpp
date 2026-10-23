#include "controller.h"
#include <iostream>
#include <limits>
#include "simulation.h"
#include "results.h"
using namespace std;

// Function declarations
void simulateSoilMoisture();
void simulateRainfall();
void runTimerController();
void runSmartController();
void compareWaterUsage();
void saveResultsToCSV();
void changeSettings();

void showMenu() {
    cout << "\n===== SMART IRRIGATION CONTROLLER =====\n";
    cout << "1. Run Soil Moisture Simulation\n";
    cout << "2. Run Rainfall Simulation\n";
    cout << "3. Run Timer Controller\n";
    cout << "4. Run Smart Controller\n";
    cout << "5. Compare Water Usage\n";
    cout << "6. Save Results to CSV\n";
    cout << "7. Change Settings\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
IrrigationController controller;
GardenSimulation simulation;
ResultsManager results; 
int main() {
    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

       
switch (choice) {
    case 1:
        simulation.simulateSoilMoisture();
        break;

    case 2:
        simulation.simulateRainfall();
        break;

    case 3:
        controller.runTimerController();
        break;

    case 4:
        controller.runSmartController();
        break;

    case 5:
        results.compareWaterUsage();
        break;

    case 6:
        results.saveResultsToCSV();
        break;

    case 7:
        controller.changeSettings();
        break;

    case 0:
        cout << "Exiting program...\n";
        break;

    default:
        cout << "Invalid choice. Try again.\n";
}


    } while (choice != 0);

    return 0;
}




