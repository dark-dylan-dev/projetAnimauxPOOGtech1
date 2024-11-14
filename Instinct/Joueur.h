#ifndef JOUEUR_H
#define JOUEUR_H

#include "CentrerTexte.h"
#include "Animal.h"
#include <vector>

class Joueur
{
private:
    string menu[8] = { "1. Nourrir", "2. Tuer", "3. Provoquer un conflit", "4. Reproduction", "5. Creer un animal", "6. Rapprocher deux animaux", "7. Ne rien faire", "8. Quitter"};
public:
    void choixDebugMode(bool& debugMode);
    int afficherInfos(std::vector<Animal>& animaux) const;
    void afficherInfosSolo(std::vector<Animal>& animaux);
    int WhileCinFail(unsigned int var, std::vector<Animal>& animaux);
    char choixJoueur(int choix, std::vector<Animal>& animaux);
};

#endif
