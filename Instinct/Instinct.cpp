#include <vector>
#include <ctime>

#include "Animal.h"
#include "Joueur.h"
#include "Jeu.h"
#include "Nourriture.h"

using namespace std;

int main() {
    srand(time(NULL));

    vector<Animal> animaux;
    vector<Nourriture> nourritures;

    int tour = 0;
    bool debugMode = false;

    Joueur joueur;
    joueur.choixDebugMode(debugMode);

    Jeu jeu;
    jeu.Init(animaux, nourritures);
    jeu.BoucleDeJeu(animaux, tour, debugMode, joueur,nourritures);

    animaux.clear();
    nourritures.clear();

    return 0;
}