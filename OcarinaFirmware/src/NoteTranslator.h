/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 * 
 * NoteTranslator.h
 * Defines the note values that the ocarina produces and translates hole
 * presses into the proper 12-hole ocarina notes
 */

#ifndef NOTETRANSLATOR_H
#define NOTETRANSLATOR_H

#include <stdint.h>

typedef enum
{
    LOW_G = 0,
    LOW_A,
    LOW_BFLAT,
    LOW_B,
    LOW_C,
    LOW_CSHARP,
    LOW_D,
    LOW_EFLAT,
    E,
    F,
    FSHARP,
    HIGH_G,
    GSHARP,
    HIGH_A,
    HIGH_BFLAT,
    HIGH_B,
    HIGH_C,
    HIGH_CSHARP,
    HIGH_D,
    HIGH_EFLAT
} Note;

class NoteTranslator
{
public:
    static Note translate(uint16_t coveredHoles);
};

NoteTranslator Translation;
#endif