
#ifndef CONTROLLER_H
#define CONTROLLER_H

class IrrigationController {
private:
    double moistureThreshold;
    int wateringInterval;
    double waterPerSession;

public:
    IrrigationController();

    void runTimerController();
    void runSmartController();
    void changeSettings();
};

#endif
