#include <Arduino.h>
#include <LovyanGFX.hpp>
#include "display.hpp"
// #include "PrinterData.h"
// #include "FakeData.h"
#include "gfx_fonts/gfx_fonts.h"
#include "gfx_images/ready.h"

// RawDataProcessor processor;
// unsigned long lastUpdate = 0;

int width = 72;
int height = 72;

const GFXfont* fontList[] = {
    &JetbrainsMono_Regular6pt,
    &JetbrainsMono_Regular8pt,
    &JetbrainsMono_Regular10pt,
    &JetbrainsMono_Regular12pt,
    &JetbrainsMono_Regular14pt,
    &JetbrainsMono_Regular16pt,
    &JetbrainsMono_Regular18pt,
    &JetbrainsMono_Regular20pt,
    &JetbrainsMono_Regular22pt,
    &JetbrainsMono_Regular24pt,
    &JetbrainsMono_Regular26pt,
    &JetbrainsMono_Regular28pt,
    &JetbrainsMono_Regular36pt,
    &JetbrainsMono_Regular48pt
};

const char* pages[] = {
    "\xB0 \xB1 \xB2",
    "\xB3 \xB5 \xB8",
    "\xB9 \xBA \xBB",
    "\xBC \xBD \xBE",
    "\xBF"
};

const int fontCount = sizeof(fontList) / sizeof(fontList[0]);
const int pageCount = sizeof(pages) / sizeof(pages[0]);


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
    tft.setTextDatum(MC_DATUM);
}

void loop()
{
    // tft.setSwapBytes(true);
    // tft.pushImage(0, 31, width, height, squintingBitmap);
    // tft.pushImage(84, 31, width, height, sleepingBitmap);
    // tft.pushImage(168, 31, width, height, sleepyBitmap);
    // delay(3000);
    // tft.fillScreen(TFT_BLACK);

    for (int p = 0; p < pageCount; p++) {

        for (int f = 0; f < fontCount; f++) {

            tft.fillScreen(TFT_BLACK);

            tft.setFreeFont(fontList[f]);

            tft.drawString(pages[p], 120, 67);

            delay(500);
        }
    }

    // if (millis() - lastUpdate >= 2000) {
    //     lastUpdate = millis();lma

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
