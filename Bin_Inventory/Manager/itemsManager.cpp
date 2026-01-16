#include "itemsManager.h"

itemManager::itemManager(){
    Serial.begin(115200);
    grid.initialiser();
}

itemManager::~itemManager(){
    // Destructeur si nécessaire
}

void itemManager::add(int nb_slots, struct coordinates *affected_slots, String name, String value, int quantity){
    ListeItems.ajouterCellule(new item(nb_slots, affected_slots, name, value, quantity));
}

void itemManager::remove(int Id){
    if(Id < 0 || Id >= ListeItems.nombreCellules()){
        return;
    }
    ListeItems.supprimerCelluleN(Id);
}

void itemManager::dell(){
    ListeItems.supprimerDerniereCellule();
}

void itemManager::gridRemoveCells(int nb_slots, struct coordinates *affected_slots){
    // Parcourir la liste chaînée de la fin au début pour éviter les problèmes d'indices lors de la suppression
    for(int i = ListeItems.nombreCellules() - 1; i >= 0; i--){
        item* current = ListeItems.lireCelluleN(i);
        bool toRemove = false;
        
        // Vérifier si au moins un slot de l'item est dans affected_slots
        for(int j = 0; j < current->getNbAffectedSlots(); j++){
            coordinates slot = current->getAffectedSlots()[j];
            for(int k = 0; k < nb_slots; k++){
                if(slot.x == affected_slots[k].x && slot.y == affected_slots[k].y){
                    toRemove = true;
                    break;
                }
            }
            if(toRemove) break;
        }
        
        // Si l'item doit être supprimé, le supprimer
        if(toRemove){
            ListeItems.supprimerCelluleN(i);
        }
    }
}

void itemManager::displayItems(){
    Serial.print("Identifier");
    Serial.print("\t | \t");
    Serial.print("Name");
    Serial.print("\t | \t");
    Serial.print("Value");
    Serial.print("\t | \t");
    Serial.println("Quantity");

    for(int i = 0; i < ListeItems.nombreCellules(); i++){
        item* temp = ListeItems.lireCelluleN(i);
        Serial.print(i);
        Serial.print("\t | \t");
        Serial.print(temp->getName());
        Serial.print("\t | \t");
        Serial.print(temp->getValue());
        Serial.print("\t | \t");
        Serial.println(temp->getQuantity());
    }
}

void itemManager::modifyQuantity(){
    Serial.println("Choose the item you want to modify the quantity from this list:");
    displayItems();

    Serial.println("Enter the ID of the item you want to modify:");
    while (Serial.available() == 0) {}
    String idInput = Serial.readStringUntil('\n');
    idInput.trim();
    int itemId = idInput.toInt();
    if (itemId == 0 && idInput != "0") {
        Serial.println("Invalid ID! Please try again.");
        return;
    }
    Serial.print("You selected item ID: ");
    Serial.println(itemId);

    if (itemId < 0 || itemId >= ListeItems.nombreCellules()) {
        Serial.println("Invalid ID! Please try again.");
        return;
    }

    Serial.println("Enter '=' to set a new quantity, '+' to add, or '-' to subtract:");
    while (Serial.available() == 0) {}
    char operation = Serial.read();
    while (Serial.available() > 0) Serial.read(); // clear buffer
    Serial.print("You selected: ");
    Serial.println(operation);

    Serial.println("Enter the value:");
    while (Serial.available() == 0) {}
    String valInput = Serial.readStringUntil('\n');
    valInput.trim();
    int newValue = valInput.toInt();
    if (newValue == 0 && valInput != "0") {
        Serial.println("Invalid value! Please try again.");
        return;
    }
    Serial.print("You entered: ");
    Serial.println(newValue);

    item* selectedItem = ListeItems.lireCelluleN(itemId);

    switch (operation) {
        case '=':
            selectedItem->setQuantity(newValue);
            Serial.println("Quantity updated!");
            break;
        case '+':
            selectedItem->setQuantity(selectedItem->getQuantity() + newValue);
            Serial.println("Quantity increased!");
            break;
        case '-':
            selectedItem->setQuantity(selectedItem->getQuantity() - newValue);
            Serial.println("Quantity decreased!");
            break;
        default:
            Serial.println("Invalid operation! Please try again.");
    }
}

void itemManager::enlightItem(){
    Serial.println("Choose the item you want to enlighten from this list:");
    displayItems();

    Serial.println("Enter the ID of the item you want to enlighten:");
    while (Serial.available() == 0) {}
    String idInput = Serial.readStringUntil('\n');
    idInput.trim();
    int itemId = idInput.toInt();
    if (itemId == 0 && idInput != "0") {
        Serial.println("Invalid ID! Please try again.");
        return;
    }
    Serial.print("You selected item ID: ");
    Serial.println(itemId);

    if (itemId < 0 || itemId >= ListeItems.nombreCellules()) {
        Serial.println("Invalid ID! Please try again.");
        return;
    }

    item* selectedItem = ListeItems.lireCelluleN(itemId);

    int nbSlots = selectedItem->getNbAffectedSlots();
    coordinates* affectedSlots = selectedItem->getAffectedSlots();

    for (int i = 0; i < nbSlots; i++) {
        int x = affectedSlots[i].x;
        int y = affectedSlots[i].y;
        grid.cells[x][y].led = CRGB::White;
    }
    Serial.println("LEDs updated for the selected item.");
}

void itemManager::actionChoice(){
    Serial.println("Press q to modify a quantity or e to enlight an item of the inventory");

    while (!(Serial.available() > 0)) {}
    int incomingByte = Serial.read();
    // Clear any remaining input in buffer
    while (Serial.available() > 0) Serial.read();
    Serial.print("Received: ");
    Serial.println((char)incomingByte);
    
    switch (incomingByte) {
        case 'q':
            modifyQuantity();
            break;
        case 'e':
            enlightItem();
            break;
        default:
            Serial.print("You entered an incorrect keystroke! ");
    }
}


