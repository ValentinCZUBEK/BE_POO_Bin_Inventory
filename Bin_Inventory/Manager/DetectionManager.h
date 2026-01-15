#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include <Arduino.h>
#include "../Hardware/Grid.h"
#include "itemsManager.h"

struct coordinates {
    int x;
    int y;
};

class DetectionManager {
private:
    bool etatPrecedentCapteurs[TAILLE][TAILLE];
    bool changementAjoutDetecte;
    bool changementSuppressionDetecte;
    unsigned long lastDetectionTime;
    static const unsigned long DELAI_DETECTION = 500;

public:
    DetectionManager();
    void detecterChangement(Grid4x4 *grille);
    void gererDetection(Grid4x4 *grille, itemManager *manager);
};

#endif
