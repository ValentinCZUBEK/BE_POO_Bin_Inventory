#ifndef FILE_CPP
#define FILE_CPP

#include "file.h"

template <typename chose>
file<chose>::file(chose contenu) {
    cellule<chose>* cell = new cellule<chose>(contenu);
    pDeb = cell;
    pFin = cell;
    nbCellules++;
}

template <typename chose>
file<chose>::file() {
    // Default constructor
}

template <typename chose>
void file<chose>::ajouterCellule(chose contenu) {
    cellule<chose>* cell = new cellule<chose>(contenu);
    if (pDeb == NULL) {
        pDeb = cell;
        pFin = cell;
    } else {
        pFin->associerPostCellule(cell);
        pFin = cell;
    }
    nbCellules++;
}

template <typename chose>
void file<chose>::supprimerPremiereCellule() {
    if (estVide()) {
        return;
    } else {
        cellule<chose>* nouveau_pDeb = pDeb->obtenirPostCellule();
        delete pDeb;  // Assuming we need to delete the node
        pDeb = nouveau_pDeb;
        nbCellules--;
    }
}

template <typename chose>
void file<chose>::supprimerDerniereCellule() {
    if (estVide()) {
        return;
    } else {
        cellule<chose>* pTemp = pDeb;
        cellule<chose>* pTempMoinsUn = pDeb;

        while (pTemp->obtenirPostCellule() != NULL) {
            pTempMoinsUn = pTemp;
            pTemp = pTemp->obtenirPostCellule();
        }
        delete pFin;  // Delete the last node
        pFin = pTempMoinsUn;
        if (pFin != NULL) {
            pFin->associerPostCellule(NULL);
        } else {
            pDeb = NULL;  // If it was the only element
        }
        nbCellules--;
    }
}

template <typename chose>
int file<chose>::nombreCellules() {
    return nbCellules;
}

template <typename chose>
bool file<chose>::estVide() {
    return nbCellules == 0;
}

template <typename chose>
chose file<chose>::lireDerniereCellule() {
    if (estVide()) {
        return NULL;
    }
    return pFin->obtenirContenu();
}

template <typename chose>
chose file<chose>::lirePremiereCellule() {
    if (estVide()) {
        return NULL;
    }
    return pDeb->obtenirContenu();
}

template <typename chose>
chose file<chose>::lireCelluleN(int nCell) {
    if (estVide() || nCell < 0 || nCell >= nbCellules) {
        return NULL;
    }
    cellule<chose>* pTemp = pDeb;
    for (int i = 0; i < nCell; i++) {
        pTemp = pTemp->obtenirPostCellule();
    }
    return pTemp->obtenirContenu();
}

template <typename chose>
void file<chose>::supprimerCelluleN(int nCell) {
    if (estVide() || nCell < 0 || nCell >= nbCellules) {
        return;
    }
    if (nCell == 0) {
        supprimerPremiereCellule();
        return;
    }
    cellule<chose>* pTempD = pDeb;
    for (int i = 0; i < nCell - 1; i++) {
        pTempD = pTempD->obtenirPostCellule();
    }
    cellule<chose>* toDelete = pTempD->obtenirPostCellule();
    cellule<chose>* next = toDelete->obtenirPostCellule();
    pTempD->associerPostCellule(next);
    if (toDelete == pFin) {
        pFin = pTempD;
    }
    delete toDelete;
    nbCellules--;
}

#endif