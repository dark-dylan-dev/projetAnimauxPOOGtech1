#ifndef JEU_H
#define JEU_H

#include <vector>
#include "Joueur.h"
#include "Animal.h"

class Jeu {
private:
    bool enCours;
    bool estJour;
public:
    Jeu() : enCours(true), estJour(true) {}
    ~Jeu() {}

    void Init(std::vector<Animal>& animaux);
    void BoucleDeJeu(std::vector<Animal>& animaux, int& tour, bool debug, Joueur& joueur);
};

#endif