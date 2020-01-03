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
#include "NotePlayer.h"
#include "HoleSensor.h"

NoteTranslator trans = NoteTranslator();
BlowSensor volumeInput = BlowSensor();
NotePlayer audio = NotePlayer();
HoleSensor holes = HoleSensor();

void setup()
{
    volumeInput.begin();
    holes.begin();
    audio.begin();
}

uint16_t lastPress = 65535;

void loop()
{
    uint16_t thisPress = holes.getPressed();
    uint8_t thisVolume = volumeInput.getVolume();

    if(thisVolume == 0)
        audio.stop();

    else
    {
        if(thisPress != lastPress)
        {
            audio.stop();
            audio.playNote(trans.translate(thisPress), thisVolume);
        }
        else
        {
            //TODO: Change volume instead of play new
            audio.playNote(trans.translate(thisPress), thisVolume);
        }
        
    }
    delay(10);
}