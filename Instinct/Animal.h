#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <vector>
#include <string>

#include "Nourriture.h"

using namespace std;

class Animal {
private:
    string nom;
    string espece;
    string regime;
    bool aFaim;
    bool enVie;

protected:
    int x, y;

public:
    int id = -1;
    Animal(const std::string& nom, const std::string& espece, const std::string& regime);

    virtual void deplacement();
    void enTrainDeDormir() const;
    float distanceAvec(const Animal& autre) const;
    float distanceAvecNourr(const Nourriture& nourriture) const;
    virtual void interagir(Animal& autre);
    void cherchNourr(Nourriture& nourr, vector<Nourriture>& nourritures);
    void afficherPosition() const;
    void deplacerVers(Animal& AnimalUn, Animal& AnimalDeux);
    void setPosition(int newPosX, int newPosY);
    // GETTERS
    std::string getNom()    const;
    std::string getEspece() const;
    std::string getRegime() const;
    bool estEnVie()         const;
    bool aFaimStatus()      const;
    int getPosX()           const;
    int getPosY()           const;

    // SETTERS
    void setVie(bool etat);
    void setFaim(bool etat);
    void setID(int idSet);
    void setNom(std::string nomSet);
};

#endif
