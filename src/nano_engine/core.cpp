/*
    MIT License

    Copyright (c) 2018, Alexey Dynda

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

#include "core.h"

///////////////////////////////////////////////////////////////////////////////
////// NANO ENGINE BASE CLASS /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

static const uint8_t ENGINE_DEFAULT_FPS = 30;

/** Duration between frames in milliseconds */
uint8_t   NanoEngineBase::m_frameDurationMs = 1000/ENGINE_DEFAULT_FPS;
/** Current fps */
uint8_t   NanoEngineBase::m_fps = ENGINE_DEFAULT_FPS;
/** Current cpu load in percents */
uint8_t   NanoEngineBase::m_cpuLoad = 0;
/** Last timestamp in milliseconds the frame was updated on oled display */
uint32_t  NanoEngineBase::m_lastFrameTs;
/** Callback to call if specific tile needs to be updated */
TNanoEngineOnDraw NanoEngineBase::m_onDraw = nullptr;
/** Callback to call if buttons state needs to be updated */
TNanoEngineGetButtons NanoEngineBase::m_onButtons = nullptr;
/** Callback to call before starting oled update */
TLoopCallback NanoEngineBase::m_loop = nullptr;

NanoEngineBase::NanoEngineBase()
{
}

void NanoEngineBase::begin()
{
    m_lastFrameTs = millis();
}

void NanoEngineBase::setFrameRate(uint8_t fps)
{
    m_fps = fps;
    m_frameDurationMs = 1000/fps;
}

bool NanoEngineBase::nextFrame()
{
    bool needUpdate = (uint32_t)(millis() - m_lastFrameTs) >= m_frameDurationMs;
    if (needUpdate && m_loop) m_loop();
    return needUpdate;
}

bool NanoEngineBase::pressed(uint8_t buttons)
{
    return (m_onButtons() & buttons) == buttons;
}

bool NanoEngineBase::notPressed(uint8_t buttons)
{
    return (m_onButtons() & buttons) == 0;
}

void NanoEngineBase::connectCustomKeys(TNanoEngineGetButtons handler)
{
    m_onButtons = handler;
}

void NanoEngineBase::connectArduboyKeys()
{
    m_onButtons = arduboyButtons;
}

uint8_t NanoEngineBase::s_zkeypadPin;

uint8_t NanoEngineBase::zkeypadButtons()
{
    int buttonValue = analogRead(s_zkeypadPin);
    if (buttonValue < 100) return BUTTON_RIGHT;
    if (buttonValue < 200) return BUTTON_UP;
    if (buttonValue < 400) return BUTTON_DOWN;
    if (buttonValue < 600) return BUTTON_LEFT;
    if (buttonValue < 800) return BUTTON_A;
    /** Z-keypad has only 5 analog buttons: no button B */
    return BUTTON_NONE;
}

void NanoEngineBase::connectZKeypad(uint8_t analogPin)
{
    NanoEngineBase::s_zkeypadPin = analogPin;
    m_onButtons = zkeypadButtons;
}

uint8_t NanoEngineBase::arduboyButtons()
{
    uint8_t buttons;
    /* Arduboy buttons available only for Atmega32U4 platform */
    #if defined(__AVR_ATmega32U4__)
    // down, up, left right
    buttons = (((~PINF) & 0B11110000)>>4);
    // A (left)
    buttons |= (((~PINE) & 0B01000000) >> 2);
    // B (right)
    buttons |= (((~PINB) & 0B00010000) << 1);
    #else
    buttons = 0;
    #endif
    return buttons;
}
