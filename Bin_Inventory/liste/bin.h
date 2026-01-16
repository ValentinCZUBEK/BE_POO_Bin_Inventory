
#ifndef BIN_H
#define BIN_H

struct coordinates{
    int x;
    int y;
};


class bin{

protected:
    int nb_affected_slots;
    struct coordinates *affected_slots;

public:
    bin(int nb_slots, struct coordinates *affected_slots);
    int getNbAffectedSlots() { return nb_affected_slots; }
    coordinates* getAffectedSlots() { return affected_slots; }
    ~bin(){
        delete[] affected_slots;
    }



};


#endif