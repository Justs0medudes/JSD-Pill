#pragma once

#include "PrinterData.h"

RawPrinterData getFakePrinterData() {
    RawPrinterData data;

    data.klipperState = "ready";

    data.livePosition[0] = 125.4;
    data.livePosition[1] = 87.2;
    data.livePosition[2] = 12.6;

    data.speed = 60.0;
    data.extrudeSpeed = 5.0;

    data.extruderTemp = 205.3;
    data.extruderTempTarget = 210.0;

    data.bedTemp = 58.7;
    data.bedTempTarget = 60.0;

    data.fanSpeed = 0.45;

    data.totalDuration = 3600.0;
    data.printDuration = 1420.0;

    data.printState = "printing";

    return data;
}