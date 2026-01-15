#include "DetectionManager.h"

// Constructeur
DetectionManager::DetectionManager() :
    changementAjoutDetecte(false),
    changementSuppressionDetecte(false),
    lastDetectionTime(0) {

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            etatPrecedentCapteurs[i][j] = false;
        }
    }
}

// Méthode pour détecter les changements (non bloquante)
void DetectionManager::detecterChangement(Grid4x4 *grille) {
    // Lire l'état actuel des capteurs
    lireBoutonsPoussoirs(grille);

    // Détection des ajouts (0 à 1)
    if (!changementAjoutDetecte) {
        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                if (grille->cells[i][j].capteur && !etatPrecedentCapteurs[i][j]) {
                    changementAjoutDetecte = true;
                    lastDetectionTime = millis();
                    return;
                }
            }
        }
    }

    // Détection des suppressions (1 à 0)
    if (!changementSuppressionDetecte) {
        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                if (!grille->cells[i][j].capteur && etatPrecedentCapteurs[i][j]) {
                    changementSuppressionDetecte = true;
                    lastDetectionTime = millis();
                    return;
                }
            }
        }
    }
}

// Méthode pour gérer la détection et interagir avec l'utilisateur
void DetectionManager::gererDetection(Grid4x4 *grille, itemManager *manager) {
    // Gestion de l'ajout
    if (changementAjoutDetecte) {
        if (millis() - lastDetectionTime >= DELAI_DETECTION) {
            lireBoutonsPoussoirs(grille);

            int nb_slots = 0;
            struct coordinates affected_slots[TAILLE * TAILLE];

            // Enregistrer les capteurs passés de 0 à 1
            for (int i = 0; i < TAILLE; i++) {
                for (int j = 0; j < TAILLE; j++) {
                    if (grille->cells[i][j].capteur && !etatPrecedentCapteurs[i][j]) {
                        affected_slots[nb_slots].x = i;
                        affected_slots[nb_slots].y = j;
                        nb_slots++;
                    }
                }
            }

            // Demander les infos à l'utilisateur pour l'ajout
            Serial.println("Nouvelle boîte détectée !");
            Serial.print("Nombre de slots affectés : ");
            Serial.println(nb_slots);

            Serial.println("Entrez le nom de l'item :");
            while (Serial.available() == 0) {}
            String nom = Serial.readStringUntil('\n');
            nom.trim();

            Serial.println("Entrez la valeur de l'item :");
            while (Serial.available() == 0) {}
            String valeur = Serial.readStringUntil('\n');
            valeur.trim();

            Serial.println("Entrez la quantité de l'item :");
            while (Serial.available() == 0) {}
            int quantite = Serial.parseInt();

            // Ajouter l'item au gestionnaire
            manager->add(nb_slots, affected_slots, nom, valeur, quantite);

            // Mettre à jour l'état précédent
            for (int i = 0; i < TAILLE; i++) {
                for (int j = 0; j < TAILLE; j++) {
                    etatPrecedentCapteurs[i][j] = grille->cells[i][j].capteur;
                }
            }

            Serial.println("Item ajouté avec succès !");
            changementAjoutDetecte = false;
        }
    }
    // Gestion de la suppression
    else if (changementSuppressionDetecte) {
        if (millis() - lastDetectionTime >= DELAI_DETECTION) {
            lireBoutonsPoussoirs(grille);

            int nb_slots = 0;
            struct coordinates affected_slots[TAILLE * TAILLE];

            // Enregistrer les capteurs passés de 1 à 0
            for (int i = 0; i < TAILLE; i++) {
                for (int j = 0; j < TAILLE; j++) {
                    if (!grille->cells[i][j].capteur && etatPrecedentCapteurs[i][j]) {
                        affected_slots[nb_slots].x = i;
                        affected_slots[nb_slots].y = j;
                        nb_slots++;
                    }
                }
            }

            // Supprimer les cellules désactivées
            manager->gridRemoveCells(nb_slots, affected_slots);

            // Mettre à jour l'état précédent
            for (int i = 0; i < TAILLE; i++) {
                for (int j = 0; j < TAILLE; j++) {
                    etatPrecedentCapteurs[i][j] = grille->cells[i][j].capteur;
                }
            }

            Serial.println("Cellules supprimées avec succès !");
            changementSuppressionDetecte = false;
        }
    }
}
