#pragma once

#include <Arduino.h>
#include <stdint.h>

// Updated by directly fetching from Moonraker
struct RawPrinterData {
    String klipperState; // "ready", "startup", "error", "shutdown"

    float livePosition[3]; // live xyz feed from klipper 

    float speed;
    float extrudeSpeed;

    float extruderTemp;
    float extruderTempTarget;
    float bedTemp;
    float bedTempTarget;

    float fanSpeed;

    float totalDuration;
    float printDuration;
    float estimatedDuration; // M73 slicer estimate returned by moonraker, unit in seconds

    String printState; // standby, printing, paused, complete, error, cancelled

};

// Printer data derived from raw data
struct DerivedPrinterData {
    String extruderStatus; // "heating", "cooling", "atTarget"
    float extruderHeatingRate;

    String bedStatus; // "heating", "cooling", "atTarget"
    float bedHeatingRate;
    
    bool isPrinting;
    bool isPaused;
    bool isComplete;
    bool hasError;

    float remainingPrintTime;

};

class RawDataProcessor {
public:
    DerivedPrinterData process(const RawPrinterData& raw);
    void addTemp(float tempList[], int size, float newTemp);
    
private:
    float extruderTempList[6];
    float bedTempList[6];
    unsigned long previousTempTime;
};