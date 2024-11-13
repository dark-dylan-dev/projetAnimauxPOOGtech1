#include <vector>
#include <ctime>

#include "Animal.h"
#include "Joueur.h"
#include "Jeu.h"

using namespace std;

int main() {
    srand(time(0));

    vector<Animal> animaux;
    int tour = 0;
    bool debugMode = false;

    Joueur joueur;
    joueur.choixDebugMode(debugMode);
    Jeu jeu;
    jeu.Init(animaux);
    jeu.BoucleDeJeu(animaux, tour, debugMode, joueur);

    animaux.clear();

    return 0;
}