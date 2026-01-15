
#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "file.h"


struct itemAndIdentifier{
    int identifier;
    class item item;
    
};

class itemManager{
    protected: 

    public:

    itemManager(){
        file ListeItems();
    }

    ~itemManager();

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

    void add(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity){
        int NewId=0;
        bool found=false;
        while(!found){
            if(IdExists(NewId) != -1){
                NewId++;
            }
            else{
                found=true; 
            }                      
        }

        struct itemAndIdentifier temporary;
        temporary.identifier = NewId;
        temporary.item = new item(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity);

        ListeItems.ajouterCellule(temporary);         
    }
    void remove(int Id){
        if(IdExists(Id) = -1){
            return;
        }
        SupprimerCelluleN(IdExists(Id));
    }
    
    void dell(){
        ListeItems.supprimerDerniereCellule();
    }

    void updateLeds(){

    }

    void displayItems(){

        int IdsArray[ListeItems.nombreCellules()];
        for(int i=0;i<ListeItems.nombreCellules();i++){
            IdsArray[i]=ListeItems.lireCelluleN(i)->identifier;
        }
        for(int i=0;i<ListeItems.nombreCellules();i++){
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