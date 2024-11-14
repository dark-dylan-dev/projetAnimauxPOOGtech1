#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>

#include "Animal.h"
#include "CentrerTexte.h"

class Joueur
{
private:
    string menu[10] = { "1. Nourrir", "2. Tuer", "3. Provoquer un conflit", "4. Reproduction", "5. Creer un animal", "6. Rapprocher deux animaux", "7. Saison des amours", "8. Effets meteorologiques", "9. Ne rien faire", "10. Quitter" }; 
public:
    bool saisonDesAmours = false;
    int compteurAmour = 0;
    int tailleMap = 100;
    bool getPeriodeDeReproduction() const;
    void setPeriodeDeReproduction(bool prd);
    void incrCompteur();
    void choixDebugMode(bool& debugMode);
    void CreerUnAnimal(std::vector<Animal>& animaux);
    int afficherInfos(std::vector<Animal>& animaux) const;
    void afficherInfosSolo(std::vector<Animal>& animaux);
    int WhileCinFail(unsigned int var, std::vector<Animal>& animaux);
    char choixJoueur(int choix, std::vector<Animal>& animaux);
    void effetTornade(vector<Animal>& animaux, int tailleMap);
    void effetMeteorite(vector<Animal>& animaux, int tailleMap);
};

#endif
