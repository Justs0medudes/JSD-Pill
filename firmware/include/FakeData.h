#pragma once

#include "PrinterData.h"

const RawPrinterData fakeRawData = {
    .klipperState = "ready",

    .livePosition = {120.0f, 80.0f, 5.0f},

    .speed = 100.0f,
    .extrudeSpeed = 5.0f,

    .extruderTemp = 185.0f,
    .extruderTempTarget = 200.0f,

    .bedTemp = 58.0f,
    .bedTempTarget = 60.0f,

    .fanSpeed = 0.65f,

    .totalDuration = 5420.0f,
    .printDuration = 3180.0f,

    .printState = "printing"
};

const DerivedPrinterData fakeDerivedData = {
    .extruderHeating = true,
    .extruderAtTarget = false,

    .bedHeating = true,
    .bedAtTarget = false,

    .isPrinting = true,
    .isPaused = false,
    .isComplete = false,
    .hasError = false,

    .remainingPrintTime = 60.0f
};