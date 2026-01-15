#include "Capteur.h"
#include <Arduino.h>  // inclu digitalRead/digitalWrite

// Broches horizontale (sorties)
const int horizontals[TAILLE] = {2, 3, 4, 5}; //a adapté pour notre carte
// Broches verticale (entrées)
const int vertical[TAILLE] = {6, 7, 8, 9};//a adapté pour notre carte



void initialiserCapteurs() {
    // Initialise les broches des lignes en sortie
    for (int i = 0; i < TAILLE; i++) {
        pinMode(lignes[i], OUTPUT);
        digitalWrite(lignes[i], LOW);  // Désactive les lignes au début
    }

    // Initialise les broches des colonnes en entrée avec pull-down
    for (int i = 0; i < TAILLE; i++) {
        pinMode(colonnes[i], INPUT_PULLUP);
    }
}




void lireBoutonsPoussoirs(Grid4x4 *grille) {
    // Activation de chaque ligne (une par une)
    for (int i = 0; i < TAILLE; i++) {
        digitalWrite(horizontals[i], HIGH);  // Active l'axe horizontale i

        // Vérification de chaque axe vertical 
        for (int j = 0; j < TAILLE; j++) {
            // Met à jour l'état du capteur dans la grille
            grille->cells[i][j].capteur = (digitalRead(vertical[j]) == LOW);
        }

        digitalWrite(horizontals[i], LOW);  // Désactive l'axe horizontale i
    }
}