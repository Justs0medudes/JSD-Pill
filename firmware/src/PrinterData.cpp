#include "PrinterData.h"

void RawDataProcessor::addTemp(float tempList[], int size, float newTemp) {
    for (int i = 0; i < size - 1; i++) {
        tempList[i] = tempList[i + 1];
    }
    tempList[size - 1] = newTemp;
}

DerivedPrinterData RawDataProcessor::process(const RawPrinterData& raw) { // & equals refrence to and const makes it read only
    DerivedPrinterData derived{};

    if (!initialized) {
        for (int i = 0; i < tempListLength; i++) {
            extruderTempList[i] = raw.extruderTemp;
            bedTempList[i] = raw.bedTemp;
        }

        initialized = true;
    } else {
        addTemp(extruderTempList, tempListLength, raw.extruderTemp);
        addTemp(bedTempList, tempListLength, raw.bedTemp); 
    }

    derived.extruderHeatingRate = (extruderTempList[tempListLength - 1] - extruderTempList[0]) / ((tempListLength - 1) * updateInterval);
    derived.bedHeatingRate = (bedTempList[tempListLength - 1] - bedTempList[0]) / ((tempListLength - 1) * updateInterval);

    if (derived.extruderHeatingRate >= extruderTempRateThreshold) {
        derived.extruderStatus = "heating";
    } else if (derived.extruderHeatingRate <= -extruderTempRateThreshold) {
        derived.extruderStatus = "cooling";
    } else {
        derived.extruderStatus = "atTarget";
    }

    if (derived.bedHeatingRate > bedTempRateThreshold) {
        derived.bedStatus = "heating";
    } else if (derived.bedHeatingRate < -bedTempRateThreshold) {
        derived.bedStatus = "cooling";
    } else {
        derived.bedStatus = "atTarget";
    }

    // state bools
    derived.isPrinting = (raw.printState == "printing");
    derived.isPaused = (raw.printState == "paused");
    derived.isComplete = (raw.printState == "complete");
    derived.hasError = (raw.printState == "error");

    // calculate remaining time
    derived.remainingPrintTime = (raw.estimatedDuration - raw.printDuration); // units in seconds

    return derived;
}