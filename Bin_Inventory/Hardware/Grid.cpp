#include "Grid.h"

void Grid4x4::initialiser() {
    int numeroled =0 ;
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            cells[i][j].capteur = false;  // Capteur inactif
            cells[i][j].led = CRGB::Black;  // LED éteinte
            cells[i][j].numeroleds=numeroled;
            numeroled ++;
        }
    }
}
