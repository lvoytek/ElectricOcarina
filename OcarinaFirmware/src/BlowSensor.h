/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 * 
 * BlowSensor.h
 * Contains a class that uses Adafruit's MPRLS pressure sensor library
 * to determine the incoming ocarina air pressure, and therefore the 
 * relative output volume.
 */

#ifndef BLOWSENSOR_H
#define BLOWSENSOR_H

#include <Wire.h>
#include <Adafruit_MPRLS.h>

/*
 * Initializes an onboard Adafruit I2C MPRLS Pressure Sensor and reads
 * pressure measurements from it, translating them in to volume 
 * percentages.
 */
class BlowSensor
{
protected:

    Adafruit_MPRLS mprls = Adafruit_MPRLS(-1, -1);

    boolean isOnline = false;

    //The minimum required pressure in PSI to play a note
    float thresholdPressure = 13.9;

    //The pressure value that produces the maximum volume level
    float maxPressure = 14.4;

    /*
     * Gets the current blow pressure in PSI
     */
    float getPressurePSI();
public:
    /*
     * Runs the setup protocol for the MPRLS Sensor
     */
    boolean begin();

    /*
     * Sets the minimum pressure in which a note will be played
     * and the pressure for the maximum possible volume
     */
    void setThresholdPressures(float min, float max);

    /*
     * Get the current note volume, on a scale of 0 to 255
     * where 255 is the max volume and 0 is no sound
     */
    uint8_t getVolume();
};

#endif