#include "Led.h"

/*
Je ne l'utilise pas, je garde pour que mon binome puisse s'en inspiré 
void mettreAJourLEDs(Grid4x4 *grille, CRGB *leds) {
    // Met à jour les couleurs des LEDs en fonction des capteurs
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille->cells[i][j].capteur) {
                grille->cells[i][j].led = CRGB::Red;
            } else {
                grille->cells[i][j].led = CRGB::Black;
            }
        }
    }
*/

//Définition pour utilisation de fast_leds
#define DATA_PIN 10
#define INTERVALE_RAFRAICHISSEMENT 200

extern CRGB leds[NUM_LEDS];  // Les Leds physiques sont déclaré dans projet_name.ino
static unsigned long dernierRafraichissement = 0;  // Dernier moment de rafraîchissement
static CRGB etatPrecedentLEDs[NUM_LEDS];  // État précédent des LEDs pour comparaison



// Je commence en initialisant les LEDs physiques
void initialiserLEDs() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.show();

    //initialise l'état précédent des leds 
    for (int i=0 ; i < NUM_LEDS ; i++) {
        etatPrecedentLEDs[i] = CRGB :: Black;
    }
}

// Vérification et mise à jour des LEDs en physiques, en fonction de l'état de la grille
void mettreAJourLEDs(Grid4x4 *grille) {
    unsigned long maintenant = millis();
    //Rafraichissement toute les 200ms 
    if (maintenant - dernierRafraichissement >= INTERVALE_RAFRAICHISSEMENT){
        dernierRafraichissement = maintenant ;
        bool changementDetecte = false;
        //Je m'occupe maintenant de la mise a jour de la LED en fonction de notre grid.
        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                int numLed = grille->cells[i][j].numeroleds;  // Utilise le numéro de LED stocké
                leds[numLed] = grille->cells[i][j].led;  // Applique la couleur

                if (leds[numLed] != etatPrecedentLEDs[numLed]) {
                    etatPrecedentLEDs[numLed] = leds[numLed];
                    changementDetecte = true;
                }
            }
        }
        if (changementDetecte = true){
            FastLED.show();  // Met à jour les LEDs
        }
    }
}
