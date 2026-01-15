
#include "item.h"

item::item(int nb_slots, struct coordinates *affected_slots, string name, string value, int quantity): bin(nb_slots, affected_slots), caracteristics(name, value, quantity){
    
}