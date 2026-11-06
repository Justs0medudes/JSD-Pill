#include <Arduino.h>
#include <LovyanGFX.hpp>
#include "display.hpp"
// #include "PrinterData.h"
// #include "FakeData.h"
#include "gfx_fonts/JetBrainsMono_Regular48pt7b.h"
#include "gfx_fonts/JetBrainsMono_Regular40pt7b.h"
#include "gfx_fonts/JetBrainsMono_Regular36pt7b.h"
#include "gfx_images/ready.h"

// RawDataProcessor processor;
// unsigned long lastUpdate = 0;

int width = 72;
int height = 72;

void setup()
{
    // Start serial if available
    Serial.begin(115200);
    delay(1000); // Wait for serial to initialize

    // example tft raw actions
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK); // black

    tft.setTextColor(TFT_WHITE);
    tft.setFont(&JetBrainsMono_Regular36pt7b);
    tft.setTextDatum(MC_DATUM);
}

void loop()
{
    tft.setSwapBytes(true);
    tft.pushImage(0, 31, width, height, squintingBitmap);
    tft.pushImage(84, 31, width, height, sleepingBitmap);
    tft.pushImage(168, 31, width, height, sleepyBitmap);
    delay(3000);
    tft.fillScreen(TFT_BLACK);

    tft.drawString("215°C", 120, 67);
    delay(3000);
    tft.fillScreen(TFT_BLACK);
    // if (millis() - lastUpdate >= 2000) {
    //     lastUpdate = millis();

    //     // Get the next fake printer snapshot
    //     RawPrinterData raw = getFakePrinterData();

    //     // Process it
    //     DerivedPrinterData derived = processor.process(raw);

    //     // Print results
    //     Serial.print("Extruder: ");
    //     Serial.print(raw.extruderTemp);
    //     Serial.print(" C | ");
    //     Serial.print(derived.extruderHeatingRate);
    //     Serial.print(" C/s | ");
    //     Serial.println(derived.extruderStatus);

    //     Serial.print("Bed: ");
    //     Serial.print(raw.bedTemp);
    //     Serial.print(" C | ");
    //     Serial.print(derived.bedHeatingRate);
    //     Serial.print(" C/s | ");
    //     Serial.println(derived.bedStatus);

    //     Serial.print("Print state: ");
    //     Serial.println(raw.printState);

    //     Serial.print("Remaining: ");
    //     Serial.print(derived.remainingPrintTime);
    //     Serial.println(" s");

    //     Serial.println();

    //}
}
