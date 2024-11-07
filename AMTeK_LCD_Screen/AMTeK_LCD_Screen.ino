// #include "dragon.h"
#include <Adafruit_GFX.h>       // include Adafruit graphics library
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library
#include "SPI.h"
#include "Boot_screen.h"        // Boot Screen File 
#include "Main_screen.h"        // Main Header File

// For the Adafruit shield, these are the default.
#define TFT_CS    15
#define TFT_DC    2
#define TFT_MOSI  23
#define TFT_CLK   18
#define TFT_RST   4
#define TFT_MISO  19


// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);


void setup() {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  int startX = 0;
  int startY = 0;
  tft.setCursor(startX, startY);
  /*Boot Screen*/
  tft.drawRGBBitmap(
        startX, startY,
        (uint16_t *)Boot_screen1Bm,
        240, 320);
  delay(1000);

  tft.drawRGBBitmap(
        startX, startY,
        (uint16_t *)Boot_screen2Bm,
        240, 320);
  delay(1000);

  tft.drawRGBBitmap(
        startX, startY,
        (uint16_t *)Boot_screen3Bm,
        240, 320);
  delay(1000);

  tft.drawRGBBitmap(
        startX, startY,
        (uint16_t *)Boot_screen4Bm,
        240, 320);
  delay(500);

  // Display the main screen after boot screens
  displayMainScreen();
}

void loop(void) {
  // tft.fillRect (0, 50, 240, 20, ILI9341_BLACK);
  // tft.fillRect (35, 110, 72, 30, ILI9341_BLACK);
  // tft.fillRect (155, 110, 72, 30, ILI9341_BLACK);
  // Update dynamic content
  String alertMsg;
  uint16_t ECO2,TVOC;
  float percalsensorVal, temp, hum;
  alertMsg = "Good";
  ECO2 = 100;
  TVOC = 500;
  percalsensorVal = 100.00;
  temp = 50;
  hum = 80;
  // updateDynamicContent(12, 42, "AQI");
  updateDynamicContent(8, 55, alertMsg);
  // updateDynamicContent(85, 42, "ECo2");
  updateDynamicContent(100, 50, String(ECO2));
  // updateDynamicContent(175, 42, "TVOC");
  updateDynamicContent(175, 50, String(TVOC));
  // updateDynamicContent(68, 95, "Temp");
  updateDynamicContent(40, 115, String(temp) + "C");
  // updateDynamicContent(178, 95, "Hum");
  updateDynamicContent(160, 115, String(hum) + "%");
  // updateDynamicContent(0, 50, "Air Quality:" + String(sensorValue));
  updateDynamicContent(105, 180, String(percalsensorVal) + "%");
  updateDynamicContent(105, 240, String(percalsensorVal) + "%");
  delay(1000); // Add a small delay to prevent the loop from running too fast

}

void displayMainScreen() {
  tft.fillScreen(ILI9341_BLACK);
  int startX = 0;
  int startY = 0;
  tft.setCursor(startX, startY);
  
  /*Main Screen*/
  tft.drawRGBBitmap(
        startX, startY,
        (uint16_t *)Main_screenBm,
        240, 320);
}

void updateDynamicContent(int x, int y, String content) {
  // Set cursor to the specified position
  tft.setCursor(x, y);
  
  tft.setTextColor(ILI9341_BLACK); // Set text color
  tft.setTextSize(2); // Set text size
  tft.print(content);
}
