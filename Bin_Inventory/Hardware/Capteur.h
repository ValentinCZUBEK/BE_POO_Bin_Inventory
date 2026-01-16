#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "Grid.h"  // Pour utiliser Grid4x4


// Initialise les broches des capteurs
void initialiserCapteurs();


// Lit l'état des BP et met à jour la grille
void lireBoutonsPoussoirs(Grid4x4 *grille);

#endif