#ifndef KC_DOCTOR_H
#define KC_DOCTOR_H

#include "definitions.h"

#include <stdio.h>

namespace KC {

struct Location {
        const Sym *sourcePath;
        struct Point {
                Nat64 row;
                Nat64 column;
        } start;
        Point end;
};

struct Diagnosis {
        Location location;
        const enum class Severity {
                MILD,
                MODERATE,
                SEVERE,
        } severity;
        const enum class Disease {
#include "diseases.defs"
        } disease;
        const Sym *note;

public:
        Diagnosis(Location location = {}, Severity severity = Severity::MILD,
                  Disease disease = Disease::UNKNOWN_TOKEN,
                  const Sym *note= "TEMPERARY DIAGNOSTIC")
                : location(location), severity(severity),
                  disease(disease), note(note) {
                puts(note);
        }
};

}

#endif // KC_DOCTOR_HPP
