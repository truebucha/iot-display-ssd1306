 /*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

// #include <SPI.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define OLED_RESET 4
// Adafruit_SSD1306 display(5, 0, 4);

// #define NUMFLAKES 10
// #define XPOS 0
// #define YPOS 1
// #define DELTAY 2


// #define LOGO16_GLCD_HEIGHT 16
// #define LOGO16_GLCD_WIDTH  16
// static const unsigned char PROGMEM logo16_glcd_bmp[] =
// { B00000000, B11000000,
//   B00000001, B11000000,
//   B00000001, B11000000,
//   B00000011, B11100000,
//   B11110011, B11100000,
//   B11111110, B11111000,
//   B01111110, B11111111,
//   B00110011, B10011111,
//   B00011111, B11111100,
//   B00001101, B01110000,
//   B00011011, B10100000,
//   B00111111, B11100000,
//   B00111111, B11110000,
//   B01111100, B11110000,
//   B01110000, B01110000,
//   B00000000, B00110000 };

// // #if (SSD1306_LCDHEIGHT != 64)
// // #error("Height incorrect, please fix Adafruit_SSD1306.h!");
// // #endif



// void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
//   uint8_t icons[NUMFLAKES][3];

//   // initialize
//   for (uint8_t f=0; f< NUMFLAKES; f++) {
//     icons[f][XPOS] = random(display.width());
//     icons[f][YPOS] = 0;
//     icons[f][DELTAY] = random(5) + 1;

//     Serial.print("x: ");
//     Serial.print(icons[f][XPOS], DEC);
//     Serial.print(" y: ");
//     Serial.print(icons[f][YPOS], DEC);
//     Serial.print(" dy: ");
//     Serial.println(icons[f][DELTAY], DEC);
//   }

//   while (1) {
//     // draw each icon
//     for (uint8_t f=0; f< NUMFLAKES; f++) {
//       display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, WHITE);
//     }
//     display.display();
//     delay(200);

//     // then erase it + move it
//     for (uint8_t f=0; f< NUMFLAKES; f++) {
//       display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, BLACK);
//       // move it
//       icons[f][YPOS] += icons[f][DELTAY];
//       // if its gone, reinit
//       if (icons[f][YPOS] > display.height()) {
//         icons[f][XPOS] = random(display.width());
//         icons[f][YPOS] = 0;
//         icons[f][DELTAY] = random(5) + 1;
//       }
//     }
//    }
// }


// void testdrawchar(void) {
//   display.setTextSize(1);
//   display.setTextColor(WHITE);
//   display.setCursor(0,0);

//   for (uint8_t i=0; i < 168; i++) {
//     if (i == '\n') continue;
//     display.write(i);
//     if ((i > 0) && (i % 21 == 0))
//       display.println();
//   }
//   display.display();
//   delay(1);
// }

// void testdrawcircle(void) {
//   for (int16_t i=0; i<display.height(); i+=2) {
//     display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
//     display.display();
//     delay(1);
//   }
// }

// void testfillrect(void) {
//   uint8_t color = 1;
//   for (int16_t i=0; i<display.height()/2; i+=3) {
//     // alternate colors
//     display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
//     display.display();
//     delay(1);
//     color++;
//   }
// }

// void testdrawtriangle(void) {
//   for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) {
//     display.drawTriangle(display.width()/2, display.height()/2-i,
//                      display.width()/2-i, display.height()/2+i,
//                      display.width()/2+i, display.height()/2+i, WHITE);
//     display.display();
//     delay(1);
//   }
// }

// void testfilltriangle(void) {
//   uint8_t color = WHITE;
//   for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5) {
//     display.fillTriangle(display.width()/2, display.height()/2-i,
//                      display.width()/2-i, display.height()/2+i,
//                      display.width()/2+i, display.height()/2+i, WHITE);
//     if (color == WHITE) color = BLACK;
//     else color = WHITE;
//     display.display();
//     delay(1);
//   }
// }

// void testdrawroundrect(void) {
//   for (int16_t i=0; i<display.height()/2-2; i+=2) {
//     display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, WHITE);
//     display.display();
//     delay(1);
//   }
// }

// void testfillroundrect(void) {
//   uint8_t color = WHITE;
//   for (int16_t i=0; i<display.height()/2-2; i+=2) {
//     display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
//     if (color == WHITE) color = BLACK;
//     else color = WHITE;
//     display.display();
//     delay(1);
//   }
// }

// void testdrawrect(void) {
//   for (int16_t i=0; i<display.height()/2; i+=2) {
//     display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
//     display.display();
//     delay(1);
//   }
// }

// void testdrawline() {
//   for (int16_t i=0; i<display.width(); i+=4) {
//     display.drawLine(0, 0, i, display.height()-1, WHITE);
//     display.display();
//     delay(1);
//   }
//   for (int16_t i=0; i<display.height(); i+=4) {
//     display.drawLine(0, 0, display.width()-1, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();
//   for (int16_t i=0; i<display.width(); i+=4) {
//     display.drawLine(0, display.height()-1, i, 0, WHITE);
//     display.display();
//     delay(1);
//   }
//   for (int16_t i=display.height()-1; i>=0; i-=4) {
//     display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();
//   for (int16_t i=display.width()-1; i>=0; i-=4) {
//     display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
//     display.display();
//     delay(1);
//   }
//   for (int16_t i=display.height()-1; i>=0; i-=4) {
//     display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);

//   display.clearDisplay();
//   for (int16_t i=0; i<display.height(); i+=4) {
//     display.drawLine(display.width()-1, 0, 0, i, WHITE);
//     display.display();
//     delay(1);
//   }
//   for (int16_t i=0; i<display.width(); i+=4) {
//     display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE);
//     display.display();
//     delay(1);
//   }
//   delay(250);
// }

// void testscrolltext(void) {
//   display.setTextSize(2);
//   display.setTextColor(WHITE);
//   display.setCursor(10,0);
//   display.clearDisplay();
//   display.println("scroll");
//   display.display();
//   delay(1);

//   display.startscrollright(0x00, 0x0F);
//   delay(2000);
//   display.stopscroll();
//   delay(1000);
//   display.startscrollleft(0x00, 0x0F);
//   delay(2000);
//   display.stopscroll();
//   delay(1000);
//   display.startscrolldiagright(0x00, 0x07);
//   delay(2000);
//   display.startscrolldiagleft(0x00, 0x07);
//   delay(2000);
//   display.stopscroll();
// }

//  void setup1()   {
//   Serial.begin(9600);
//   Serial.println(F("test text"));
  
//   // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
//   display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  // initialize with the I2C addr 0x3D (for the 128x64)
//   // init done
//   Wire.pins(5,4);

//   // Show image buffer on the display hardware.
//   // Since the buffer is intialized with an Adafruit splashscreen
//   // internally, this will display the splashscreen.
//   display.display();
//   delay(2000);

//   // Clear the buffer.
//   display.clearDisplay();

//   // draw a single pixel
//   display.drawPixel(10, 10, WHITE);
//   // Show the display buffer on the hardware.
//   // NOTE: You _must_ call display after making any drawing commands
//   // to make them visible on the display hardware!
//   display.display();
//   delay(2000); 
//   display.clearDisplay();

//   // draw many lines
//   testdrawline();
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // draw rectangles
//   testdrawrect();
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // draw multiple rectangles
//   testfillrect();
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // draw mulitple circles
//   testdrawcircle();
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // draw a white circle, 10 pixel radius
//   display.fillCircle(display.width()/2, display.height()/2, 10, WHITE);
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   testdrawroundrect();
//   delay(2000);
//   display.clearDisplay();

//   testfillroundrect();
//   delay(2000);
//   display.clearDisplay();

//   testdrawtriangle();
//   delay(2000);
//   display.clearDisplay();

//   testfilltriangle();
//   delay(2000);
//   display.clearDisplay();

//   // draw the first ~12 characters in the font
//   testdrawchar();
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // draw scrolling text
//   testscrolltext();
//   delay(2000);
//   display.clearDisplay();

//   // text display tests
//   display.setTextSize(1);
//   display.setTextColor(WHITE);
//   display.setCursor(0,0);
//   display.println("Hello, world!");
//   display.setTextColor(BLACK, WHITE); // 'inverted' text
//   display.println(3.141592);
//   display.setTextSize(2);
//   display.setTextColor(WHITE);
//   display.print("0x"); display.println(0xDEADBEEF, HEX);
//   display.display();
//   delay(2000);
//   display.clearDisplay();

//   // miniature bitmap display
//   display.drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
//   display.display();
//   delay(1);

//   // invert the display
//   display.invertDisplay(true);
//   delay(1000);
//   display.invertDisplay(false);
//   delay(1000);
//   display.clearDisplay();

//   // draw a bitmap icon and 'animate' movement
//   testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
// }

/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 by Daniel Eichhorn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

// Include the correct display library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
// or #include "SH1106.h" alis for `#include "SH1106Wire.h"`
// For a connection via I2C using brzo_i2c (must be installed) include
// #include <brzo_i2c.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Brzo.h"
// #include "SH1106Brzo.h"
// For a connection via SPI include
// #include <SPI.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Spi.h"
// #include "SH1106SPi.h"

// Include custom images
// #include "images.h"

// Initialize the OLED display using SPI
// D5 -> CLK
// D7 -> MOSI (DOUT)
// D0 -> RES
// D2 -> DC
// D8 -> CS
// SSD1306Spi        display(D0, D2, D8);
// or
// SH1106Spi         display(D0, D2);

// Initialize the OLED display using brzo_i2c
// D3 -> SDA
// D5 -> SCL
// SSD1306Brzo display(0x3c, D3, D5);
// or
// SH1106Brzo  display(0x3c, D3, D5);

// Initialize the OLED display using Wire library
SSD1306  display(0x3C, D1, D2);
// SH1106 display(0x3c, D3, D5);


#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup1() {
  Serial.begin(9600);

  while(!Serial);

  Serial.println(F("test"));
  Serial.println();


  // Initialising the UI will init the display too.
  display.connect();
  
  display.init();

  display.displayOn();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void drawFontFaceDemo() {
    // Font Demo1
    // create more fonts at http://oleddisplay.squix.ch/
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 26, "Hello world");
}

void drawTextFlowDemo() {
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawStringMaxWidth(0, 0, 128,
      "Lorem ipsum\n dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore." );
}

void drawTextAlignmentDemo() {
    // Text alignment demo
  display.setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 10, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 22, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 33, "Right aligned (128,33)");
}

void drawRectDemo() {
      // Draw a pixel at given position
    for (int i = 0; i < 10; i++) {
      display.setPixel(i, i);
      display.setPixel(10 - i, i);
    }
    display.drawRect(12, 12, 20, 20);

    // Fill the rectangle
    display.fillRect(14, 14, 17, 17);

    // Draw a line horizontally
    display.drawHorizontalLine(0, 40, 20);

    // Draw a line horizontally
    display.drawVerticalLine(40, 0, 20);
}

void drawCircleDemo() {
  for (int i=1; i < 8; i++) {
    display.setColor(WHITE);
    display.drawCircle(32, 32, i*3);
    if (i % 2 == 0) {
      display.setColor(BLACK);
    }
    display.fillCircle(96, 32, 32 - i* 3);
  }
}

void drawProgressBarDemo() {
  int progress = (counter / 5) % 100;
  // draw the progress bar
  display.drawProgressBar(0, 32, 120, 10, progress);

  // draw the percentage as String
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, String(progress) + "%");
}

// void drawImageDemo() {
//     // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
//     // on how to create xbm files
//     display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
// }

Demo demos[] = {drawFontFaceDemo, drawTextFlowDemo, drawTextAlignmentDemo, drawRectDemo, drawCircleDemo, drawProgressBarDemo};
int demoLength = (sizeof(demos) / sizeof(Demo));
long timeSinceLastModeSwitch = 0;

void loop1() {
  // clear the display
  Serial.print(display.connect());
  display.clear();
  // draw the current demo method
  demos[demoMode]();

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  // write the buffer to the display
  display.display();

  if (millis() - timeSinceLastModeSwitch > DEMO_DURATION) {
    demoMode = (demoMode + 1)  % demoLength;
    timeSinceLastModeSwitch = millis();
  }
  counter++;
  delay(10);
}

/// test 
void setup2()
{
  Wire.begin(5,4);
 
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}
 
void loop2()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}

void loop() {
  // loop2();
  loop1();
  Serial.println(F("loop"));
}

void setup() {
    setup2();
    loop2();
    setup1();
}