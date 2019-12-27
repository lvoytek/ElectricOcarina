/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 * 
 * NotePlayer.h
 * Uses predefined 16-bit ocarina notes in memory and plays the correct
 * one over I2S based on the enum note input, handles initial, sustain,
 * and stop versions of the note.
 */

#ifndef NOTEPLAYER_H
#define NOTEPLAYER_H

#include "Ocarina_samples.h"
#include "NoteTranslator.h"

class NotePlayer
{
protected:
    //The Ocarina note wavetable
    AudioSynthWavetable ocarinaTable;

    //The I2S Output Stream
    AudioOutputI2S i2s;

    //Connectors between the ocarina wavetable and I2S
    AudioConnection conn1 = AudioConnection(ocarinaTable, 0, i2s, 0);
    AudioConnection conn2 = AudioConnection(ocarinaTable, 0, i2s, 1);

public:
    /*
     * Initializes the Ocarina wavetable
     */
    void begin();

    /*
     * Play a note at a given frequency and volume specified by the
     * enum note type and 0-255 volume value
     */
    void playNote(Note note, uint8_t volume);

    /*
     * Stop any currently playing note
     */
    void stop();
};


#endif