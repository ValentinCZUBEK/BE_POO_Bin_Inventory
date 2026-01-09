
#ifndef CARACTERISTICS_H
#define CARACTERISTICS_H

#include <string>
using namespace std;

class caracteristics{

protected:
    string name;
    string value;
    int quantity=0;

public:

    caracteristics(string nm, string vl, int qty): name(nm), value(vl), quantity(qty) {
    
    }

    ~caracteristics(){
    
    }



};


#endif