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

    String printState; // standby, printing, paused, complete, error, cancelled

};

// Printer data derived from raw data
struct DerivedPrinterData {
    bool extruderHeating;
    bool extruderAtTarget;

    bool bedHeating;
    bool bedAtTarget;
    
    bool isPrinting;
    bool isPaused;
    bool isComplete;
    bool hasError;

    float remainingPrintTime;

};