
#ifndef ITEM_H
#define ITEM_H

#include "bin.h"
#include "caracteristics.h"

class item: public bin, public caracteristics{

protected:

public:

    item(int nb_sl, struct coordinates *aff_sl, string nm, string vl, int qty): bin(nb_sl, aff_sl), caracteristics(nm, vl, qty){}

    ~item(){

    }

};


#endif