#pragma once

#include "printerdata.h"

RawPrinterData getFakePrinterData() {
    static RawPrinterData data;

    static float extruderTemp = 180.0;
    static float bedTemp = 45.0;

    static int tick = 0;

    // Simulate temperature rising
    extruderTemp += 3.0;
    bedTemp += 1.0;

    // Stop at target
    if (extruderTemp > 210.0) {
        extruderTemp = 210.0;
    }

    if (bedTemp > 60.0) {
        bedTemp = 60.0;
    }

    data.klipperState = "ready";

    data.livePosition[0] = 125.4;
    data.livePosition[1] = 87.2;
    data.livePosition[2] = 12.6;

    data.speed = 60.0;
    data.extrudeSpeed = 5.0;

    data.extruderTemp = extruderTemp;
    data.extruderTempTarget = 210.0;

    data.bedTemp = bedTemp;
    data.bedTempTarget = 60.0;

    data.fanSpeed = 0.45;

    data.totalDuration = 3600.0;
    data.printDuration = tick * 2.0;

    data.printState = "printing";

    tick++;

    return data;
}