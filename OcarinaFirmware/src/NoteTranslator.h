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

#define FV(f) (1 << f)

#include "HoleSensor.h"
#include <stdint.h>

typedef enum
{
    LOW_C = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(RIGHT_MIDDLE) | 
            FV(RIGHT_RING) | FV(RIGHT_PINKY) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) |
            FV(LEFT_RING) | FV(LEFT_PINKY),

    LOW_CSHARP = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(RIGHT_MIDDLE) | 
                 FV(RIGHT_MIDDLE_B) | FV(RIGHT_RING) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) |
                 FV(LEFT_MIDDLE_B) | FV(LEFT_RING) | FV(LEFT_PINKY),

    LOW_D = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(RIGHT_MIDDLE) | 
            FV(RIGHT_RING) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) | FV(LEFT_RING) |
            FV(LEFT_PINKY),

    LOW_EFLAT = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(RIGHT_MIDDLE) | 
                FV(RIGHT_MIDDLE_B) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) | FV(LEFT_RING) | 
                FV(LEFT_PINKY),

    LOW_E = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(RIGHT_MIDDLE) | 
            FV(LEFT_INDEX) | FV(LEFT_MIDDLE) | FV(LEFT_RING) | FV(LEFT_PINKY),

    LOW_F = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_INDEX) | FV(LEFT_INDEX) |
            FV(LEFT_MIDDLE) | FV(LEFT_RING) | FV(LEFT_PINKY),

    FSHARP = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_RING) | FV(LEFT_INDEX) | 
             FV(LEFT_MIDDLE) | FV(LEFT_RING) | FV(LEFT_PINKY),

    G = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) | 
        FV(LEFT_RING) | FV(LEFT_PINKY),

    GSHARP = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_RING) | FV(LEFT_INDEX) | 
             FV(LEFT_MIDDLE) | FV(LEFT_PINKY),

    A = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(LEFT_INDEX) | FV(LEFT_MIDDLE) | 
        FV(LEFT_PINKY),

    HIGH_BFLAT = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(RIGHT_RING) | FV(LEFT_INDEX) | 
                 FV(LEFT_PINKY),

    B = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(LEFT_INDEX) | FV(LEFT_PINKY),

    HIGH_C = FV(RIGHT_THUMB) | FV(LEFT_THUMB) | FV(LEFT_PINKY),

    HIGH_CSHARP = FV(RIGHT_THUMB) | FV(RIGHT_RING) | FV(LEFT_PINKY),

    HIGH_D = FV(RIGHT_THUMB) | FV(LEFT_PINKY),

    HIGH_EFLAT = FV(RIGHT_RING) | FV(LEFT_PINKY),

    HIGH_E = FV(LEFT_PINKY),

    HIGH_F = 0
} Note;


/*
 * Contains a single function that can translate a 12-bit
 * hole press value into its respective note
 */
class NoteTranslator
{
public:
    /*
     * Translate a 12-bit value to an ocarina note based on 
     * preset fingering layout
     */
    Note translate(uint16_t coveredHoles);
};

#endif