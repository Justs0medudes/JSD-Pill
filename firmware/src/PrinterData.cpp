#include "PrinterData.h"

const int tempListLength = 6; // data from -10 to +0 seconds
const float updateInterval = 2.0; // 2 seconds
float tempRateThreshold = 2.0; // 2 Celsius

void RawDataProcessor::addTemp(float tempList[], int size, float newTemp) {
    for (int i = 0; i < size - 1; i++) {
        tempList[i] = tempList[i + 1];
    }
    tempList[size - 1] = newTemp;
}

DerivedPrinterData RawDataProcessor::process(const RawPrinterData& raw) { // & equals refrence to and const makes it read only
    DerivedPrinterData derived{};

    addTemp(extruderTempList, tempListLength, raw.extruderTemp);
    derived.extruderHeatingRate = (extruderTempList[tempListLength - 1] - extruderTempList[0]) / ((tempListLength - 1) * updateInterval);

    addTemp(bedTempList, tempListLength, raw.bedTemp);
    derived.bedHeatingRate = (bedTempList[tempListLength - 1] - bedTempList[0]) / ((tempListLength - 1) * updateInterval);

    if (derived.extruderHeatingRate > tempRateThreshold) {
        derived.extruderStatus = "heating";
    } else if (derived.extruderHeatingRate < -tempRateThreshold) {
        derived.extruderStatus = "cooling";
    } else {
        derived.extruderStatus = "atTarget";
    }

    if (derived.bedHeatingRate > tempRateThreshold) {
        derived.bedStatus = "heating";
    } else if (derived.bedHeatingRate < -tempRateThreshold) {
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