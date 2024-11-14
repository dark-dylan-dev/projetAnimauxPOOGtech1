#ifndef JEU_H
#define JEU_H

#include <vector>
#include "Joueur.h"
#include "Animal.h"

class Jeu {
private:
    bool enCours;
    bool estJour;
    int mangerConte;
public:
    Jeu() : enCours(true), estJour(true), mangerConte(0){}
    ~Jeu() {}

    void Init(std::vector<Animal>& animaux, std::vector<Nourriture>& nourritures);
    void BoucleDeJeu(std::vector<Animal>& animaux, int& tour, bool debug, Joueur& joueur, std::vector<Nourriture>& nourritures);

    int getMangerConte() const { return mangerConte; }
    void setMangerConte(int manger) { mangerConte = manger; }
};

#endif
