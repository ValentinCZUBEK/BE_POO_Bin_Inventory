
#ifndef ITEM_H
#define ITEM_H

#include "bin.h"
#include "caracteristics.h"

class item: public bin, public caracteristics{

protected:

public:

    item(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity);

    ~item(){

    }

};


#endif