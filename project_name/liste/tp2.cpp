// utilisation dâ€™objets dâ€™entrÂ´ees-sorties : les inclusions
#include <iostream>
// faciliter le nommage
using namespace std;

#include <string>
// pour utiliser chaines caracteres

//g++ -Wall -Wextra -Werror tp1.cpp -o tp2
//g++ *.cpp -Wall -Wextra -Werror -o tp2

#include "file.h"



#define pi 3.14159265359


class Figure {

protected:
    static int nbFigures;    


// zone publique
public:
// mÂ´ethode dâ€™initialisation
    Figure(){
        nbFigures++;
    }

    virtual int perimetre()=0;

    virtual void afficherCaracteristiques()=0;

    static int nombreFigures(){
        return(nbFigures);
    }


    //desctructeur
    ~Figure(){
        nbFigures--;
    }
};
int Figure::nbFigures = 0;


class Coloriable{

    protected :
        string couleur;

    public :

        Coloriable(string coul){
        couleur=coul;
        }
        string getCouleur(){
            return couleur;
        }
        void setCouleur(string coul){
            couleur=coul;
        }

        ~Coloriable(){
        }
};



class Polygone: public Figure{

    protected:
    int nbCotes;
    

    public:
    Polygone(int nb) :nbCotes(nb){
    }

    void afficherCaracteristiques(){

        cout <<"nb_Cotes = " << nbCotes << endl;  
    }

    ~Polygone(){
    }
};


class Rectangle: public Polygone{
    protected:
    int longueur;
    int largeur;

    public:
    Rectangle(int lg, int lag) :Polygone(4), longueur(lg), largeur(lag){
    }

    int perimetre(){
        return((nbCotes/2)*longueur+(nbCotes/2)*largeur);
    }

    void afficherCaracteristiques(){

        cout <<"nb_Cotes = " << nbCotes << "\nlongueur = " << longueur << "\nlargeur = " << largeur << endl;  
    }
    void modLong(int lg){
        longueur=lg;
    }
    void modLarg(int lag){
        largeur=lag;
    }
    ~Rectangle(){
    }
};


class Carre: public Polygone{

    protected:
    int longueur;

    public:
    Carre(int lg) :Polygone(4), longueur(lg){
    }

    int perimetre(){
        return(nbCotes*longueur);
    }

    void afficherCaracteristiques(){

        cout <<"nb_Cotes = " << nbCotes << "\nlongueur = " << longueur << endl;  
    }
    void modLong(int lg){
        longueur=lg;
    }
    ~Carre(){
    }
};


class TriangleEquilateral: public Polygone{

    protected:
    int longueur;

    public:
    TriangleEquilateral(int lg) :Polygone(3), longueur(lg){
    }

    int perimetre(){
        return(nbCotes*longueur);
    }

    void afficherCaracteristiques(){

        cout <<"nb_Cotes = " << nbCotes << "\nlongueur = " << longueur << endl;  
    }
    void modLong(int lg){
        longueur=lg;
    }
    ~TriangleEquilateral(){
    }
};


class Cercle: public Figure, public Coloriable{
    
    protected:
        int rayon;

    public:
    Cercle(int ra, string color) :Coloriable(color), rayon(ra) {
    }

    int perimetre(){
        return(2*pi*rayon);
    }

    void afficherCaracteristiques(){

        cout <<"rayon = " << rayon << endl;  
    }
    void modRay(int ra){
        rayon=ra;
    }
    ~Cercle(){
    }
    
};


int main(){    

    Rectangle r1(5,6);
    Rectangle* pr1 = &r1;

    Carre ca1(6);
    Carre* pca1 = &ca1;

    TriangleEquilateral te1(8);
    TriangleEquilateral* pte1 = &te1;

    Cercle ce1(3,"miam");
    Cercle* pce1 = &ce1;


    //Figure* tab[]={pr1, pca1, pte1, pce1};

    file<Figure*> liste1(pr1);
    liste1.ajouterCellule(pca1);
    liste1.ajouterCellule(pte1);
    liste1.ajouterCellule(pce1);

    while(!liste1.estVide()){
        Figure *pt = liste1.lireDerniereCellule();        
        pt->afficherCaracteristiques();
        liste1.supprimerDerniereCellule();
    }
    try{
        file<int> listeNulle{};
        listeNulle.supprimerDerniereCellule();
    }
    catch(const exception & e) {cerr << "yooooo what'sup" << endl;}


    /*
    for(unsigned long i=0; i<sizeof(tab)/sizeof(Figure*);i++){
        tab[i]->afficherCaracteristiques();
    }
    cout << "Nombre total de figures = " << Figure::nombreFigures() << endl;

    */

}

