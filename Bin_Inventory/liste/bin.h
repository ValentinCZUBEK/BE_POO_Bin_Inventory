
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

    bin(int nb_sl, struct coordinates *aff_sl){

    }

    ~bin(){
    
    }



};


#endif