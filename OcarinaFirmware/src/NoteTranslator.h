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