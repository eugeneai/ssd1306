/*
    MIT License

    Copyright (c) 2016-2019, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 *   Attiny85 PINS
 *             ____
 *   RESET   -|_|  |- 3V
 *   SCL (3) -|    |- (2)
 *   SDA (4) -|    |- (1)
 *   GND     -|____|- (0)
 *
 *   Atmega328 PINS: connect LCD to A4/A5
 */

#include "ssd1306.h"

const uint8_t Owl [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
0x0A, 0x05, 0x0D, 0x01, 0x01, 0x03, 0x87, 0xFE, 0xFE, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0E,
0x08, 0x0C, 0x0C, 0x0C, 0x0E, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x30,
0x98, 0xDE, 0xE6, 0xE7, 0xF7, 0xD7, 0xD6, 0x56, 0x56, 0xD7, 0xD7, 0x5F, 0xDF, 0x3F, 0x3F, 0x2F,
0x9F, 0xD7, 0xDF, 0x6F, 0x6B, 0x6B, 0x7F, 0xF7, 0xF3, 0xF3, 0xE0, 0xEC, 0x98, 0x30, 0xE0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x70, 0x70, 0x60,
0x40, 0x60, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xE0, 0xF0, 0xE0, 0x40, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFB, 0xE0,
0xDF, 0xB1, 0xEF, 0x5F, 0xB9, 0xB0, 0xA0, 0xE6, 0x6E, 0x2E, 0xB6, 0xB9, 0x9F, 0xAF, 0xA0, 0xA7,
0xBF, 0x99, 0xB6, 0xB6, 0xA6, 0xA6, 0xB0, 0xB0, 0xA9, 0xDF, 0xCF, 0xF0, 0x7F, 0x77, 0xFD, 0x01,
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0xEE, 0xB3, 0x7D, 0xBE, 0x7F, 0xC7, 0x87, 0xB7,
0xB7, 0xB7, 0xCD, 0x7D, 0x83, 0x93, 0xFB, 0xCD, 0xB5, 0x35, 0xA5, 0x87, 0xCE, 0xFE, 0x1C, 0xF9,
0xC3, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x3F, 0x3C, 0x73,
0xEF, 0x9E, 0x7E, 0xFD, 0xFD, 0xED, 0xAD, 0xFD, 0xDD, 0xFF, 0xBF, 0xFF, 0x5F, 0xDF, 0xEF, 0xFF,
0xFF, 0xFF, 0x6F, 0xFF, 0xDF, 0xEF, 0xFD, 0xDD, 0xFD, 0xBC, 0xFE, 0x7E, 0xBF, 0xEF, 0x7B, 0x3E,
0x1F, 0x0F, 0x07, 0x00, 0x00, 0x0E, 0x1F, 0x3C, 0x77, 0x5F, 0x3D, 0x7D, 0xFB, 0xFB, 0x7A, 0xFA,
0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0x7E, 0xFE, 0xBF, 0xFD, 0xF5, 0xF5, 0xF6, 0xFA, 0xFB, 0xDF,
0x67, 0x78, 0x3C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xC0, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x40, 0x00, 0x10, 0x38, 0x80, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x81, 0x83, 0x83, 0x87, 0xE7, 0xEF, 0xEF, 0xEB, 0xFF, 0xF7, 0xDF,
0xFA, 0xFE, 0xFF, 0xEB, 0xEE, 0xEE, 0xE7, 0x67, 0x63, 0x61, 0x60, 0x60, 0x60, 0xE0, 0xE0, 0xE0,
0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x71, 0x73, 0x7B,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7F, 0x77, 0x76, 0x73, 0x73, 0x71, 0x71, 0x70, 0x71, 0x70,
0x70, 0x70, 0x70, 0x70, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF1, 0xF1, 0xF1, 0xE0, 0xE0,
0xE8, 0xEC, 0xEE, 0xE7, 0xE2, 0xE4, 0xE8, 0xD0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
0x10, 0x10, 0x10, 0x10, 0x1F, 0x13, 0xA1, 0xAD, 0xC8, 0x49, 0x47, 0x42, 0x40, 0xC0, 0xDC, 0x78,
0x60, 0x60, 0x20, 0x21, 0x31, 0x30, 0x11, 0x1A, 0x1B, 0x0B, 0x0D, 0x0C, 0x04, 0x06, 0x06, 0x06,
0x03, 0x03, 0x03, 0x13, 0x31, 0x71, 0x71, 0x61, 0x81, 0x81, 0x41, 0x20, 0x26, 0x0C, 0x1C, 0x30,
0x78, 0x00, 0x00, 0x84, 0xC4, 0x84, 0x84, 0x0C, 0x04, 0x02, 0x02, 0x01, 0x01, 0x07, 0x0E, 0x0E,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xE0, 0xC0, 0xC0, 0x00, 0x00, 0x81, 0x81, 0x81, 0x41, 0x41,
0x21, 0x21, 0x13, 0x13, 0x13, 0x03, 0x0B, 0x0B, 0x0B, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x00, 0x00, 0x06, 0x07, 0x03, 0x03, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0C, 0x40, 0xEE, 0x79,
0x35, 0x02, 0x08, 0x08, 0x04, 0x04, 0x02, 0x1F, 0x3D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
0x04, 0x24, 0x00, 0x0D, 0x30, 0x31, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0xC6, 0xC6, 0x36, 0x68, 0x44,
0xB4, 0xA0, 0x52, 0x62, 0x02, 0x02, 0x02, 0x00, 0x01, 0x03, 0x32, 0x7A, 0x3E, 0x1A, 0x02, 0x02,
0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x1D, 0x3D, 0x1D, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/**
 * Soba bitmap source is generated via script from https://github.com/robertgallup/bmp2hex
 * MIT license
 */
const uint8_t Soba [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80,
0x09, 0x00, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00,
0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x30, 0x03,
0x00, 0x00, 0x00, 0x98, 0x01, 0x00, 0xf8, 0x00,
0xcc, 0x00, 0x00, 0xde, 0x03, 0x66, 0x00, 0x80,
0x07, 0x0f, 0x33, 0x00, 0xc0, 0x01, 0x9c, 0x19,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff,
0xff, 0xff, 0x07, 0xe0, 0xff, 0xff, 0xff, 0x07,
0xe0, 0xff, 0xff, 0xff, 0x07, 0xe0, 0xff, 0xff,
0xff, 0x07, 0xe0, 0xff, 0xff, 0xff, 0x07, 0xc0,
0xff, 0xff, 0xff, 0x03, 0xc0, 0xff, 0xff, 0xff,
0x03, 0x80, 0xff, 0xff, 0xff, 0x01, 0x80, 0xff,
0xff, 0xff, 0x01, 0x00, 0xff, 0xff, 0xff, 0x00,
0x00, 0xfe, 0xff, 0x7f, 0x00, 0x00, 0xfc, 0xff,
0x3f, 0x00, 0x00, 0xf8, 0xff, 0x1f, 0x00, 0x00,
0xf0, 0xff, 0x0f, 0x00, 0x00, 0xc0, 0xff, 0x03,
0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup()
{
    ssd1306_128x64_i2c_init();
}


void loop()
{
    ssd1306_fillScreen(0x00);
    ssd1306_drawBitmap(0, 0, 128, 64, Owl);
    delay(3000);
    ssd1306_fillScreen(0x00);
    ssd1306_drawXBitmap(0, 0, 40, 32, Soba);
    delay(3000);
}




