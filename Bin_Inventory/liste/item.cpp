
#include "item.h"

item::item(int nb_slots, struct coordinates *affected_slots, String name, String value, int quantity): bin(nb_slots, affected_slots), caracteristics(name, value, quantity){
    
}