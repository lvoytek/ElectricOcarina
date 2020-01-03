/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 */

#include "NoteTranslator.h"

Note NoteTranslator::translate(uint16_t coveredHoles)
{
    switch (coveredHoles)
    {
        case LOW_C:
        case LOW_CSHARP:
        case LOW_D:
        case LOW_EFLAT:
        case LOW_E:
        case LOW_F:
        case FSHARP:
        case G:
        case GSHARP:
        case A:
        case HIGH_BFLAT:
        case B:
        case HIGH_C:
        case HIGH_CSHARP:
        case HIGH_D:
        case HIGH_EFLAT:
        case HIGH_E:
        case HIGH_F:
            return (Note) coveredHoles;
        
        //Currently returns a low c on invalid fingering, to be changed later
        default:
            return LOW_C;
    }
}