#ifndef FILE_H
#define FILE_H

#include <stdexcept>

#include "cellule.h"

template <typename chose>
class file{
    protected:
        cellule<chose> *pDeb = NULL;
        cellule<chose> *pFin = NULL;
        int nbCellules = 0;


    public:
        
        file(chose contenu){   
            cellule<chose> *cell = new cellule<chose>(contenu);               
            //cellule<chose> cell(contenu);
            pDeb = cell;
            pFin = cell;  
            nbCellules++;           
        }
        file(){                         
        }

        void ajouterCellule(chose contenu){
            cellule<chose> *cell = new cellule<chose>(contenu); 
            if(pDeb == NULL){
                pDeb = cell;
                pFin = cell;
            }
            else{               
                (*pFin).associerPostCellule(cell);               
                pFin = cell;
            }
            nbCellules++;
        }

        void supprimerPremiereCellule(){
           
                if(estVide()) {throw Vide();}
                else{
                    cellule<chose> *nouveau_pDeb = pDeb->obtenirPostCellule();
                    //pDeb = NULL;
                    pDeb = nouveau_pDeb;
                    nbCellules--;
                }
            
            
        }

        void supprimerDerniereCellule(){

            if(estVide()) {throw Vide();}
            else{
                cellule<chose> *pTemp = pDeb;
                cellule<chose> *pTempMoinsUn = pDeb;

                while(pTemp->obtenirPostCellule() != NULL){
                    pTempMoinsUn = pTemp;
                    pTemp = pTemp->obtenirPostCellule();
                }
                //pFin = NULL;
                pFin = pTempMoinsUn;
                pFin->associerPostCellule(NULL);
                nbCellules--;
            }
        }
        
        int nombreCellules(){
            return(nbCellules);
        }

        bool estVide(){
            return(nbCellules==0?true:false);
        }

        chose lireDerniereCellule(){  
            return(pFin->obtenirContenu());
        }

        chose lirePremiereCellule(){  
            return(pDeb->obtenirContenu());
        }

        chose lireCelluleN(int nCell){
            if((estVide()) || (nCell<0) || (nCell>=nbCellules)){
                return(NULL);
            }
            cellule<chose> *pTemp=pDeb;
            for(int i=0;i<=nCell;i++){
                pTemp=pTemp->obtenirPostCellule();
            }
            return(pTemp->obtenirContenu());
        }

        void SupprimerCelluleN(int nCell){
            if((estVide()) || (nCell<0) || (nCell>=nbCellules)){
                return(NULL);
            }
            cellule<chose> *pTempD=pDeb;
            cellule<chose> *pTempF=pDeb;
            for(int i=0;i<nCell;i++){
                pTempD=pTempD->obtenirPostCellule();                
            }
            pTempF=pTempD->obtenirPostCellule();
            pTempF=pTempF->obtenirPostCellule();

            pTempD->associerPostCellule(pTempF);

        }
 



        class Vide :public exception{
            protected:  

            public:
                const char * what() const noexcept override {
                return "Impossible de supprimer un élément d'une file vide.";
            }            
        };

};



#endif