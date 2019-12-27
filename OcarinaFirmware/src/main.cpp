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

BlowSensor volumeInput = BlowSensor();
NotePlayer audio = NotePlayer();

void setup()
{
    Serial.begin(9600);
    volumeInput.begin();
    audio.begin();

}

void loop()
{
    audio.playNote(LOW_C, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(LOW_C, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(G, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(G, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(A, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(A, volumeInput.getVolume());
    delay(450);
    audio.stop();
    delay(50);

    audio.playNote(G, volumeInput.getVolume());
    delay(950);
    audio.stop();
    delay(50);
}