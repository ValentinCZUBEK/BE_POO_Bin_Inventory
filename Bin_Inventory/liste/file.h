#ifndef FILE_H
#define FILE_H

#include <stdexcept>
#include "cellule.h"

template <typename chose>
class file {
    protected:
        cellule<chose> *pDeb = NULL;
        cellule<chose> *pFin = NULL;
        int nbCellules = 0;

    public:
        file(chose contenu);
        file();
        void ajouterCellule(chose contenu);
        void supprimerPremiereCellule();
        void supprimerDerniereCellule();
        int nombreCellules();
        bool estVide();
        chose lireDerniereCellule();
        chose lirePremiereCellule();
        chose lireCelluleN(int nCell);
        void supprimerCelluleN(int nCell);

        class Vide : public std::exception {
            public:
                const char* what() const noexcept override {
                    return "Impossible de supprimer un élément d'une file vide.";
                }
        };
};

#include "file.cpp"

#endif