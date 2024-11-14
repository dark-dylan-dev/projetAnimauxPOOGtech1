#include <iostream>
#include <vector>

#include "Joueur.h"
#include "Animal.h"
#include "CentrerTexte.h"

using namespace std;

void Joueur::choixDebugMode(bool& debugMode) {
    cout << "Debug mode [y/N] ? > ";
    std::string ans;
    cin >> ans;
    while (cin.fail() || (ans != "y" && ans != "N"))
    {
        cin.clear();
        cin.ignore(9999, '\n');
        system("cls");
        cout << "Debug mode [y/N] ? > ";
        cin >> ans;
    }
    if (ans == "y") {
        debugMode = true;
    }
    else {
        system("cls");
    }
}

int Joueur::afficherInfos(vector<Animal>& animaux) const {
    int choix(0);
    for (int i = 0; i < 8; ++i) {
        centrerTexte(menu[i]);
        cout << endl;
    }
    cout << "\nQue voulez-vous faire durant ce tour ? > ";
    cin >> choix;
    while (cin.fail() || choix < 1 || choix > 8) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Fais un choix correct, entre 1 et 8 > ";
        cin >> choix;
    }
    return choix;
}
void Joueur::afficherInfosSolo(vector<Animal>& animaux) {
    for (unsigned int i = 0; i < animaux.size(); ++i) {
        if (animaux[i].estEnVie() == false) { continue; }
        if (i < 9) { cout << endl << " - " << animaux[i].id << ". " << animaux[i].getNom() << " (" << animaux[i].getEspece() << ")"; }
        else { cout << endl << " - " << animaux[i].id << "." << animaux[i].getNom() << " (" << animaux[i].getEspece() << ")"; }
    }
    cout << endl;
}
int Joueur::WhileCinFail(unsigned int var, vector<Animal>& animaux) {
    while (cin.fail() || var < 1 || var > animaux.size()) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
        cin >> var;
    }
    return var;
}
char Joueur::choixJoueur(int choix, vector<Animal>& animaux) {
    unsigned int choixSpecifique(0);
    unsigned int choixAnimalUn(0), choixAnimalDeux(0);
    int choixRandom;
    string animauxRandEspece[2]; string animauxRandRegime[2];
    string especeDuBebe; string regimeDuBebe; string nomDuBebe;
    switch (choix) {
    case 1: // Option : 'Nourrir' -> Rajouter des vérifications
        cout << "Tu as choisi de nourrir un animal, quel animal veux-tu nourrir ? ";
        afficherInfosSolo(animaux);
        cout << "Ton choix > ";
        cin >> choixSpecifique;
        if (cin.fail() || choixSpecifique < 1 || choixSpecifique > animaux.size()) { choixSpecifique = WhileCinFail(choixSpecifique, animaux); }
        if (animaux[choixSpecifique - 1].aFaimStatus()) { cout << animaux[choixSpecifique - 1].getNom() << " n'a pas besoin de manger pour l'instant" << endl; break; }
        animaux[choixSpecifique - 1].setFaim(true);
        cout << " - Tu as rempli la pense de " << animaux[choixSpecifique - 1].getNom() << endl;
        break;
    case 2: // Option : 'Tuer' -> Rajouter des vérifications
        cout << "Tu as choisi de tuer un animal, quel animal veux-tu tuer ? ";
        afficherInfosSolo(animaux);
        cout << "Ton choix > ";
        cin >> choixSpecifique;
        if (cin.fail() || choixSpecifique < 1 || choixSpecifique > animaux.size()) { choixSpecifique = WhileCinFail(choixSpecifique, animaux); }
        animaux[choixSpecifique - 1].setVie(false);
        cout << " - Tu as ote la vie de " << animaux[choixSpecifique - 1].getNom() << endl;
        break;
    case 3: // Option : 'Provoquer un conflit' -> Rajouter des vérifications
        cout << "Tu as choisi de provoquer un conflit entre deux animaux, lesquels veux-tu se faire affronter ?";
        afficherInfosSolo(animaux);
        cout << "Ton choix pour le combattant numero 1 > ";
        cin >> choixAnimalUn;
        if (cin.fail() || choixAnimalUn < 1 || choixAnimalUn > animaux.size()) { choixAnimalUn = WhileCinFail(choixAnimalUn, animaux); }
        cout << endl << "Ton choix pour le combattant numero 2 > ";
        cin >> choixAnimalDeux;
        while (cin.fail() || choixAnimalDeux < 1 || choixAnimalDeux > animaux.size() || choixAnimalDeux == choixAnimalUn) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " et different du combattant numero 1 > ";
            cin >> choixAnimalDeux;
        }
        if (animaux[choixAnimalUn - 1].getRegime() == "neutre" || animaux[choixAnimalDeux - 1].getRegime() == "neutre") {
            cout << endl << "Les capybaras ne se battent jamais" << endl;
            break; 
        }
        if (animaux[choixAnimalUn - 1].getRegime() != animaux[choixAnimalDeux - 1].getRegime()) {
            // L'un des combattant est prédateur, l'autre une proie -> le prédateur tue et mange la proie
            if (animaux[choixAnimalUn - 1].getRegime() == "predateur") {
                cout << endl << " - " << animaux[choixAnimalUn - 1].getNom() << " (" << animaux[choixAnimalUn - 1].getEspece() << ") a battu " <<
                    animaux[choixAnimalDeux - 1].getNom() << " (" << animaux[choixAnimalDeux - 1].getEspece() << ")" << endl;
                animaux[choixAnimalDeux - 1].setVie(false);
                break;
            }
            cout << endl << " - " << animaux[choixAnimalDeux - 1].getNom() << " (" << animaux[choixAnimalDeux - 1].getEspece() << ") a battu " <<
                animaux[choixAnimalUn - 1].getNom() << " (" << animaux[choixAnimalUn - 1].getEspece() << ")" << endl;
            animaux[choixAnimalUn - 1].setVie(false);
        }
        else if (animaux[choixAnimalUn - 1].getRegime() == "predateur") { 
            // Les deux combattants sont des prédateurs -> issue aléatoire
            int combattants[2] = { choixAnimalUn, choixAnimalDeux };
            unsigned int choixRandom = rand() % 2;
            animaux[combattants[choixRandom]].setVie(false);
            if (choixRandom == 0) {
                cout << endl << " - " << animaux[choixAnimalDeux - 1].getNom() << " (" << animaux[choixAnimalDeux - 1].getEspece() << ") a battu "
                    << animaux[choixAnimalUn - 1].getNom() << " (" << animaux[choixAnimalUn - 1].getEspece() << ")" << endl;
                break;
            }
            cout << endl << " - " << animaux[choixAnimalUn - 1].getNom() << " (" << animaux[choixAnimalUn - 1].getEspece() << ") a battu "
                << animaux[choixAnimalDeux - 1].getNom() << " (" << animaux[choixAnimalDeux - 1].getEspece() << ")" << endl;
        }
        else { 
            // Les deux combattants sont des proies -> ils se font la paix
            cout << endl << "Les deux proies " << animaux[choixAnimalUn - 1].getNom()   << " (" << animaux[choixAnimalUn - 1].getEspece()   << ") et" 
                                               << animaux[choixAnimalDeux - 1].getNom() << " (" << animaux[choixAnimalDeux - 1].getEspece() << ") se font la paix!" << endl;
        }
        break;
    case 4: // Option : 'Reproduction'
        cout << "Tu as choisi de se faire reproduire entre eux deux animaux\n   - Attention : Reproduction possible uniquement si les deux animaux ont le meme regime alimentaire" << endl;
        afficherInfosSolo(animaux);
        cout << "Quels animaux veux-tu se faire reproduire ? \n\n - Animal 1 > ";
        cin >> choixAnimalUn;
        if (cin.fail() || choixAnimalUn < 1 || choixAnimalUn > animaux.size()) { choixAnimalUn = WhileCinFail(choixAnimalUn, animaux); }
        cout << endl << " - Animal 2 > ";
        cin >> choixAnimalDeux;
        while (cin.fail() || choixAnimalDeux < 1 || choixAnimalDeux > animaux.size() || choixAnimalDeux == choixAnimalUn) {
            if (choixAnimalDeux == choixAnimalUn) { cout << "Un animal ne peut pas se reproduire lui meme\n"; }
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
            cin >> choixAnimalDeux;
        }
        animauxRandEspece[0] = animaux[choixAnimalUn-1].getEspece(); animauxRandEspece[1] = animaux[choixAnimalDeux-1].getEspece();
        animauxRandRegime[0] = animaux[choixAnimalUn-1].getRegime(); animauxRandRegime[1] = animaux[choixAnimalDeux-1].getRegime();
        choixRandom = rand() % 2; // A fixer
        especeDuBebe = animauxRandEspece[choixRandom];
        regimeDuBebe = animauxRandRegime[choixRandom];
        nomDuBebe = animaux[choixRandom].getNom() + " Jr.";
        animaux.push_back(Animal::Animal(nomDuBebe, especeDuBebe, regimeDuBebe));
        cout << endl << nomDuBebe << " (" << especeDuBebe << ", " << regimeDuBebe << ") est le resultat de l'amour passionnel entre "
            << animaux[choixAnimalUn - 1].getNom() << " et " << animaux[choixAnimalDeux - 1].getNom() << endl;
        break;
    case 5: // Option : 'Creer un animal'
    cout << "Tu as choisis de créer un nouvel animal\n";
    afficherInfosSolo(animaux);
    cout << "Choisis l'animal que tu veux créer" <<
    break;
    case 6: // Option : 'Rapprocher deux animaux'
    cout << "Tu as choisis de rapprocher deux animaux\n";
    afficherInfosSolo(animaux);
    cout << "Quels animaux veux-tu rapprocher ? \n\n - Animal 1 >";
    cin >> choixAnimalUn;
    if (cin.fail() || choixAnimalUn < 1 || choixAnimalUn > animaux.size()) { choixAnimalUn = WhileCinFail(choixAnimalUn, animaux); }
    cout << endl << " - Animal 2 > ";
    cin >> choixAnimalDeux;
    while (cin.fail() || choixAnimalDeux < 1 || choixAnimalDeux > animaux.size() || choixAnimalDeux == choixAnimalUn) {
        if (choixAnimalDeux == choixAnimalUn) { cout << "Un animal ne peut pas se rapprocher de lui même\n"; }
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
        cin >> choixAnimalDeux;
    }
    break;
    case 7: // Option : 'Ne rien faire'
        break;
    case 8: // Option : 'Quitter'
        return 'Q';
    default:
        break;
    }
    return ' ';
}
