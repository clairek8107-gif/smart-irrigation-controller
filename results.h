
#ifndef RESULTS_H
#define RESULTS_H

class ResultsManager {
private:
    double timerWaterUsed;
    double smartWaterUsed;

public:
    ResultsManager();

    void compareWaterUsage();
    void saveResultsToCSV();
};

#endif
