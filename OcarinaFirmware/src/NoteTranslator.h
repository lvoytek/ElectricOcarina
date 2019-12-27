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
    LOW_C = 0,
    LOW_CSHARP,
    LOW_D,
    LOW_EFLAT,
    LOW_E,
    LOW_F,
    FSHARP,
    G,
    GSHARP,
    A,
    HIGH_BFLAT,
    B,
    HIGH_C,
    HIGH_CSHARP,
    HIGH_D,
    HIGH_EFLAT,
    HIGH_E,
    HIGH_F
} Note;

class NoteTranslator
{
public:
    static Note translate(uint16_t coveredHoles);
};

#endif