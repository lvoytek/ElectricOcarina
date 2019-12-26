/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 */

#include "BlowSensor.h"

float BlowSensor::getPressurePSI()
{
    //Attempt reboot
    if(!this->isOnline)
        this->begin();

    //Invalid pressure read
    if(!this->isOnline)
        return -1;

    return this->mprls.readPressure() / 68.947572932;
}

boolean BlowSensor::begin()
{
    this->isOnline = this->mprls.begin();

    if(!this->isOnline)
        return false;
 
    //Get an initial ambient pressure
    float ambientAverage = 0;
    for(uint8_t i = 0; i < 20; i++)
    {
        ambientAverage += this->getPressurePSI();
        delay(200);
    }

    ambientAverage /= 20;
    
    this->setThresholdPressures(ambientAverage+.005, ambientAverage + .1);

    return true;
}

void BlowSensor::setThresholdPressures(float min, float max)
{
    this->thresholdPressure = min;
    this->maxPressure = max;
}

uint8_t BlowSensor::getVolume()
{
    float pressure = this->getPressurePSI();

    if(pressure >= this->maxPressure)
        return 255;

    if(pressure <= this->thresholdPressure)
        return 0;

    float volScalar = (pressure - this->thresholdPressure) / (this->maxPressure - this->thresholdPressure);
    return (uint8_t) (255 * volScalar);
}