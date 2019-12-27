/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 */

#include "NotePlayer.h"

void NotePlayer::begin()
{
    AudioMemory(120);
    this->sgtl5000_1.enable();
	this->sgtl5000_1.volume(0.8);
    this->ocarinaTable.setInstrument(Ocarina);
    this->ocarinaTable.amplitude(1);
    this->amp.gain(1);
}

void NotePlayer::playNote(Note note, uint8_t volume)
{
    this->amp.gain(volume/255.0);
    switch(note)
    {
        case LOW_C:
            this->ocarinaTable.playFrequency(500);
            break;

        case LOW_D:
            this->ocarinaTable.playFrequency(567);
            break;

        case LOW_E:
            this->ocarinaTable.playFrequency(625);
            break;

        case LOW_F:
            this->ocarinaTable.playFrequency(678);
            break;

        case G:
            this->ocarinaTable.playFrequency(745);
            break;

        case A:
            this->ocarinaTable.playFrequency(854);
            break;

        case B:
            this->ocarinaTable.playFrequency(969);
            break;

        case HIGH_C:
            this->ocarinaTable.playFrequency(1043);
            break;

        case HIGH_D:
            this->ocarinaTable.playFrequency(1111);
            break;

        case HIGH_E:
            this->ocarinaTable.playFrequency(1248);
            break;

        case HIGH_F:
            this->ocarinaTable.playFrequency(1288);
            break;

        case LOW_CSHARP:
            this->ocarinaTable.playFrequency(521);
            break;
        
        case LOW_EFLAT:
            this->ocarinaTable.playFrequency(610);
            break;

        case FSHARP:
            this->ocarinaTable.playFrequency(707);
            break;

        case GSHARP:
            this->ocarinaTable.playFrequency(819);
            break;

        case HIGH_BFLAT:
            this->ocarinaTable.playFrequency(920);
            break;

        case HIGH_CSHARP:
            this->ocarinaTable.playFrequency(1070);
            break;

        case HIGH_EFLAT:
            this->ocarinaTable.playFrequency(1184);
            break;
    }
}

void NotePlayer::stop()
{

}