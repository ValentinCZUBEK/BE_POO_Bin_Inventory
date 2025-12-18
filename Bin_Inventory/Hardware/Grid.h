#ifndef GRID_H
#define GRID_H

#include <FastLED.h>

#define TAILLE 4
#define NUM_LEDS (TAILLE * TAILLE)

struct Cellule {
    bool capteur;
    CRGB led;
};

struct Grid4x4 {
    Cellule cells[TAILLE][TAILLE];
    void initialiser();  // Initialise capteurs + LEDs
};

#endif
