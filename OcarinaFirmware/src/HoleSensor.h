/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 * 
 * HoleSensor.h
 * Contains a class that uses Adafruit's MPR121 capacitive touch sensor
 * library in order to determine what holes are currently pressed on
 * the ocarina.
 */

#ifndef HOLESENSOR_H
#define HOLESENSOR_H

#include <stdint.h>
#include <Wire.h>
#include <Adafruit_MPR121.h>

typedef enum
{
    RIGHT_THUMB = 0,
    LEFT_THUMB = 1,
    RIGHT_INDEX = 2,
    RIGHT_MIDDLE = 3,
    RIGHT_MIDDLE_B = 4,
    RIGHT_RING = 5,
    RIGHT_PINKY = 6,
    LEFT_INDEX = 7,
    LEFT_MIDDLE = 8,
    LEFT_MIDDLE_B = 9,
    LEFT_RING = 10,
    LEFT_PINKY = 11
} Fingering;

/*
 * Initializes an onboard Adafruit I2C MPR121 touch Sensor and reads
 * the 12 capacitive touch values, translating them to a single 12-bit
 * value for note translation.
 */
class HoleSensor
{
protected:
    Adafruit_MPR121 cap = Adafruit_MPR121();

    boolean isOnline = false;

public:
     /*
     * Runs the setup protocol for the MPR121 Sensor
     */
    boolean begin();

    /*
    * Return the 12-bit value representing pressed holes
    */
    uint16_t getPressed();
};

#endif