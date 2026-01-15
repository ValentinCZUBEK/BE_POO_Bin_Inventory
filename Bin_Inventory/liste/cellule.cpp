#ifndef CELLULE_CPP
#define CELLULE_CPP

#include "cellule.h"

template <typename truc>
cellule<truc>::cellule(truc cont) : contenu(cont) {
    // Constructor
}

template <typename truc>
truc cellule<truc>::obtenirContenu() {
    return contenu;
}

template <typename truc>
cellule<truc>* cellule<truc>::obtenirPostCellule() {
    return pCellule;
}

template <typename truc>
void cellule<truc>::associerPostCellule(cellule<truc>* p_cell) {
    pCellule = p_cell;
}

template <typename truc>
cellule<truc>::~cellule() {
    contenu = NULL;
}

#endif