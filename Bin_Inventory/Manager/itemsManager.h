
#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "file.h"

#include "item.h"

#include "Arduino.h"

class itemManager{
    protected: 

    public:

    itemManager(){
        file ListeItems();

        Serial.begin(115200);
    }

    ~itemManager();


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
        //cout << "Identifier" << "\t | \t" << "name" << "\t | \t" << "value" << "\t | \t" << "quantity" << endl;
        Serial.print("Identifier");
        Serial.print("\t | \t");
        Serial.print("Name");
        Serial.print("\t | \t");
        Serial.print("Value");
        Serial.print("\t | \t");
        Serial.println("Quantity");

        for(int i=0;i<ListeItems.nombreCellules();i++){
            item temp = ListeItems.lireCelluleN(i);
            //cout << i << "\t | \t" << temp->name << "\t | \t" << temp->value << "\t | \t" << temp->quantity << endl;
            //à remplacer par un serial.print :
            Serial.print(i);
            Serial.print("\t | \t");
            Serial.print(temp->name);
            Serial.print("\t | \t");
            Serial.print(temp->value);
            Serial.print("\t | \t");
            Serial.println(temp->quantity);
        }
    }

    void modifyQuantity(){
        Serial.println("Choose the item you to modify the quantity from this list :")
        displayItems();

//Attendre que l'utilisateur entre l'ID de l'item
    Serial.println("Enter the ID of the item you want to modify:");
    while (Serial.available() == 0) {}
    int itemId = Serial.parseInt();
    Serial.print("You selected item ID: ");
    Serial.println(itemId);

    // Vérifier si l'ID est valide
    if (itemId < 0 || itemId >= ListeItems.nombreCellules()) {
        Serial.println("Invalid ID! Please try again.");
        return;
    }

    // Afficher les options de modification
    Serial.println("Enter '=' to set a new quantity, '+' to add, or '-' to subtract:");
    while (Serial.available() == 0) {}
    char operation = Serial.read();
    Serial.print("You selected: ");
    Serial.println(operation);

    // Demander la valeur à appliquer
    Serial.println("Enter the value:");
    while (Serial.available() == 0) {}
    int newValue = Serial.parseInt();
    Serial.print("You entered: ");
    Serial.println(newValue);

    // Récupérer l'item sélectionné
    item* selectedItem = ListeItems.lireCelluleN(itemId);

    // Appliquer la modification
    switch (operation) {
        case '=':
            selectedItem->caracteristic = newValue; // Utilise l'opérateur =
            Serial.println("Quantity updated!");
            break;
        case '+':
            selectedItem->caracteristic += newValue; // Utilise l'opérateur +=
            Serial.println("Quantity increased!");
            break;
        case '-':
            selectedItem->caracteristic -= newValue; // Utilise l'opérateur -=
            Serial.println("Quantity decreased!");
            break;
        default:
            Serial.println("Invalid operation! Please try again.");
    }
        }


        switch (incomingByte)
        {
            case '=':
                item.caracteristic = newValue;                
                break;
            case '+':
                item.caracteristic += newValue;
                break;
            case '-':
                item.caracteristic -= newValue;
                break;
            default:
                Serial.print("You entered an incorrect keystroke ! ");
                //Serial.println(incomingByte,char);
        }

        




        
        


    }

    void enlightItem(){


    }

    void waitForInput(){
        //une fois qu'on appuie sur entrée
        //on affiche tout ce qu'il y a dans la liste chainee

        Serial.println("Press q to modify a quantity or d to enlight an item of the inventory");

        int incomingByte = 0;

        while (!(Serial.available() > 0)) {     //on attend qu'il y ai qqch dans sur le port série
        }
        incomingByte = Serial.read(); // read the incoming byte:
        Serial.print("Received:");
        Serial.println(incomingByte,char);
        
        switch (incomingByte)
        {
            case 'q':
                modifyQuantity();
                break;
            case 'i':
                enlightItem();
                break;
            default:
                Serial.print("You entered an incorrect keystroke ! ");
                //Serial.println(incomingByte,char);
        }
            
        
    }

};



#endif