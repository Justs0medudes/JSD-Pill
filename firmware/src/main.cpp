#include <Arduino.h>
#include <TFT_eSPI.h>
#include "FakeData.h"
#include "gfx_fonts/JetBrainsMono_Regular48pt7b.h"
#include "gfx_fonts/JetBrainsMono_Regular40pt7b.h"
#include "gfx_fonts/JetBrainsMono_Regular36pt7b.h"
#include "gfx_images/ready.h"

TFT_eSPI tft = TFT_eSPI();

/*
// example tft raw actions
// tft.init();
// tft.setRotation(1);
// tft.fillScreen(TFT_BLACK); // black
// // tft.setTextColor(TFT_WHITE);
// // tft.setFreeFont(&JetBrainsMono_Regular36pt7b);
// // tft.setTextDatum(MC_DATUM);
// tft.setSwapBytes(true);
// tft.pushImage(0, 31, width, height, squintingBitmap);
// tft.pushImage(84, 31, width, height, sleepingBitmap);
// tft.pushImage(168, 31, width, height, sleepyBitmap);
*/

uint8_t height = 72;
uint8_t width = 72;

void setup() {

}

void loop() {

}
