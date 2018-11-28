// Helper functions for music
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO

    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    return 8 * numerator / denominator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Parse string into a note and its octave
    int semitone = 0;
    int octave = 0;
    char accidental;

    // Calculate frequency of note in given octave
    if (strlen(note) == 3)
    {
        octave = atoi(&note[2]);
        accidental = note[1];

        if (accidental == '#')
        {
            semitone += 1;
        }
        else if (accidental == 'b')
        {
            semitone -= 1;
        }
    }
    else if (strlen(note) == 2)
    {
        octave = atoi(&note[1]);
    }

    semitone += (octave - 4) * 12;

    char letter = note[0];
    switch (letter)
    {
        case 'C' :
            semitone -= 9;
            break;
        case 'D' :
            semitone -= 7;
            break;
        case 'E' :
            semitone -= 5;
            break;
        case 'F' :
            semitone -= 4;
            break;
        case 'G' :
            semitone -= 2;
            break;
        case 'A' :
            semitone += 0;
            break;
        case 'B' :
            semitone += 2;
            break;
    }

    // Return frequency
    float frequency = (440.0 * pow(2, (semitone / 12.0)));
    frequency = round(frequency);
    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

