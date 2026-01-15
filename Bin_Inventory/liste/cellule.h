
#ifndef CELLULE_H
#define CELLULE_H

template <typename truc>
class cellule {
    protected:
        cellule<truc> *pCellule = NULL;
        truc contenu;
    
    public:

        cellule(truc cont);
        truc obtenirContenu();
        cellule<truc> *obtenirPostCellule();
        void associerPostCellule(cellule<truc> *p_cell);
        ~cellule();
};

#include "cellule.cpp"

#endif
