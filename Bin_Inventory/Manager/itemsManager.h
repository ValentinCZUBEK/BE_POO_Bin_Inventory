
#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "file.h"


class itemManager{
    protected: 

    public:

    itemManager(){
        file ListeItems();
    }

    ~itemManager();
/*
    int IdExists(int Id){        
        int IdsArray[ListeItems.nombreCellules()];
        for(int i=0;i<ListeItems.nombreCellules();i++){
            IdsArray[i]=ListeItems.lireCelluleN(i)->identifier;
        }
        for(int i=0;i<ListeItems.nombreCellules();i++){
            if(IdsArray[i]=Id){
                return(i);
            }
        }
        return(-1);
    }
*/

    void add(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity){

        ListeItems.ajouterCellule(new item(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity));         
    }

    void remove(int Id){
        if(Id<0 || Id >= ListeItems.nombreCellules()){
            return;
        }
        SupprimerCelluleN(Id);
    }
    
    void dell(){
        ListeItems.supprimerDerniereCellule();
    }









    void updateLeds(){

    }

    void displayItems(){

        for(int i=0;i<ListeItems.nombreCellules();i++){
            ListeItems.lireCelluleN(i)
            cout << 
            //à remplacer par un serial.print
            
        }
    }

    void waitForInput(){
        //une fois qu'on appuie sur entrée
        //on affiche tout ce qu'il y a dans la liste chainee
        

    }


};



#endif