
#ifndef CELLULE_H
#define CELLULE_H


template <typename truc>
class cellule {
    protected:
        cellule<truc> *pCellule = NULL;
        truc contenu;
    
    public:

        cellule(truc cont) :contenu(cont){
            //return(this);
        }

        truc obtenirContenu(){
            return(contenu);
        }

        cellule<truc> *obtenirPostCellule(){
            return(pCellule);
        }

        void associerPostCellule(cellule<truc> *p_cell){
            pCellule=p_cell;            
        }

        ~cellule(){
            contenu = NULL;
        }
};


#endif
