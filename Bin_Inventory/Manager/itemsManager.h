
#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "../liste/file.h"
#include "item.h"
#include "Grid.h"
#include <string.h>
#include "Arduino.h"

class itemManager{
    protected: 
    Grid4x4 grid;

    private:
    file ListeItems;

    public:

    itemManager();
    ~itemManager();

    void add(int nb_slots, struct coordinates *affected_slots, String name, String value, int quantity);
    void remove(int Id);
    void dell();
    void gridRemoveCells(int nb_slots, struct coordinates *affected_slots);
    void displayItems();
    void modifyQuantity();
    void enlightItem();
    void actionChoice();
};

#endif