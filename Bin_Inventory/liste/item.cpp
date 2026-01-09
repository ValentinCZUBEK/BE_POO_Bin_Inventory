
#include "item.h"

item::item(int nb_sl, struct coordinates *aff_sl, string nm, string vl, int qty): bin(nb_sl, aff_sl), caracteristics(nm, vl, qty){
    
}