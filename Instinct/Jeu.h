#ifndef JEU_H
#define JEU_H

#include <vector>

#include "Joueur.h"
#include "Animal.h"

class Jeu {
private:
    bool enCours;
    bool estJour;
    string meteo;
    int test = rand() % 3;
public:
    Jeu() : enCours(true), estJour(true) {}
    ~Jeu() {}

    void Init(std::vector<Animal>& animaux, std::vector<Nourriture>& nourritures);
    void BoucleDeJeu(std::vector<Animal>& animaux, int& tour, bool debug, Joueur& joueur, std::vector<Nourriture>& nourritures);
};

#endif