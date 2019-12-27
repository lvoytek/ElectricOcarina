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
    this->ocarinaTable.setInstrument(Ocarina);
    this->ocarinaTable.amplitude(1);
}

void NotePlayer::playNote(Note note, uint8_t volume)
{

}

void NotePlayer::stop()
{
    
}