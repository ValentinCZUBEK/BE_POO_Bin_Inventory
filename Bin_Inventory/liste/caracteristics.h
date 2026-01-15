
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

    caracteristics(string name, string value, int quantity): name(name), value(value), quantity(quantity) {
    
    }

    ~caracteristics(){
    
    }



};


#endif