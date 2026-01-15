
#ifndef CARACTERISTICS_H
#define CARACTERISTICS_H

#include <string>
using namespace std;

class caracteristics{

protected:
    string name;
    string value;
    unsigned int quantity=0;

public:

    caracteristics(string name, string value, int quantity): name(name), value(value), quantity(quantity) {
    
    }

    ~caracteristics(){
    
    }
/*
    void operator = (const caracteristic truc)const{
        quantity = truc.quantity;
    }
    void operator + (const int addedQuantity)const{
        quantity += addedQuantity;                
    }
    void operator - (const int removedQuantity)const{
        quantity -= removedQuantity;                
    }
    void operator += (const int addedQuantity)const{
        quantity += addedQuantity;                
    }
    void operator -= (const int removedQuantity)const{
        quantity -= removedQuantity;                
    }
*/

    // Opérateur += pour ajouter une quantité
    void operator+=(const int addedQuantity) {
        quantity += addedQuantity;
    }

    // Opérateur -= pour soustraire une quantité
    void operator-=(const int removedQuantity) {
        quantity -= removedQuantity;
    }

    // Opérateur = pour affecter une quantité
    void operator=(const int newQuantity) {
        quantity = newQuantity;
    }


};


#endif