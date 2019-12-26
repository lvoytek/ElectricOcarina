/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 * 
 * main.cpp
 * Handles communication between sensors and keeps track of incoming
 * blow and hole-cover data
 */

#include <Arduino.h>
#include "NoteTranslator.h"
#include "BlowSensor.h"

BlowSensor volumeInput = BlowSensor();

void setup()
{
    Serial.begin(9600);
    volumeInput.begin();
}

void loop()
{
    Serial.println(volumeInput.getVolume());
    delay(1000);
}