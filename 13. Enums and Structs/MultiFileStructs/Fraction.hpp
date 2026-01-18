#pragma once

// Defining a new type: Fraction
// Just a definition, not initialization (note this must be defined in every file it is used in)
// No forward declarations, as such there are many identical definitions of this struct
// If we keep including this header in other files

struct Fraction
{
    int numerator {};
    int denominator {};
};  // Note semicolon at the end of the user defined type