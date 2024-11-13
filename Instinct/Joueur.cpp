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
    for (int i = 0; i < 7; ++i) {
        centrerTexte(menu[i]);
        cout << endl;
    }
    cin >> choix;
    while (cin.fail() || choix < 1 || choix > 7) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Fais un choix correct, entre 1 et 7 > ";
        cin >> choix;
    }
    return choix;
}
void Joueur::afficherInfosSolo(vector<Animal>& animaux) {
    for (int i = 0; i < animaux.size(); ++i) {
        if (animaux[i].estEnVie() == false) { continue; }
        if (i < 9) { cout << endl << " - " << animaux[i].id << ". " << animaux[i].getNom() << " (" << animaux[i].getEspece() << ")"; }
        else { cout << endl << " - " << animaux[i].id << "." << animaux[i].getNom() << " (" << animaux[i].getEspece() << ")"; }
    }
    cout << endl;
}
char Joueur::choixJoueur(int choix, vector<Animal>& animaux) {
    int choixSpecifique(0);
    int choixCombattantUn(0), choixCombattantDeux(0);
    switch (choix) {
    case 1:
        cout << "Tu as choisi de nourrir un animal, quel animal veux-tu nourrir ? ";
        afficherInfosSolo(animaux);
        cout << "Ton choix > ";
        cin >> choixSpecifique;
        while (cin.fail() || choixSpecifique < 1 || choixSpecifique > animaux.size()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
            cin >> choixSpecifique;
        }
        animaux[choixSpecifique - 1].setFaim(true);
        cout << " - Tu as rempli la pense de " << animaux[choixSpecifique - 1].getNom() << " (" << animaux[choixSpecifique - 1].getEspece() << ")" << endl;
        break;
    case 2:
        cout << "Tu as choisi de tuer un animal, quel animal veux-tu tuer ? ";
        afficherInfosSolo(animaux);
        cout << "Ton choix > ";
        cin >> choixSpecifique;
        while (cin.fail() || choixSpecifique < 1 || choixSpecifique > animaux.size()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
            cin >> choixSpecifique;
        }
        animaux[choixSpecifique - 1].setVie(false);
        cout << " - Tu as ote la vie de " << animaux[choixSpecifique - 1].getNom() << " (" << animaux[choixSpecifique - 1].getEspece() << ")" << endl;
        break;
    case 3:
        cout << "Tu as choisi de provoquer un conflit entre deux animaux, lesquels veux-tu se faire affronter ?";
        afficherInfosSolo(animaux);
        cout << "Ton choix pour le combattant numero 1 > ";
        cin >> choixCombattantUn;
        while (cin.fail() || choixCombattantUn < 1 || choixCombattantUn > animaux.size()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " > ";
            cin >> choixCombattantUn;
        }
        cout << "Ton choix pour le combattant numero 2 > ";
        cin >> choixCombattantDeux;
        while (cin.fail() || choixCombattantDeux < 1 || choixCombattantDeux > animaux.size() || choixCombattantDeux == choixCombattantUn) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Fais un choix correct, entre 1 et " << animaux.size() << " et different du combattant numero 1 > ";
            cin >> choixCombattantDeux;
        }
        if (animaux[choixCombattantUn - 1].getRegime() == "neutre") {
            animaux[choixCombattantDeux - 1].setVie(false);
            break;
        }
        if (animaux[choixCombattantDeux - 1].getRegime() == "neutre") {
            animaux[choixCombattantUn - 1].setVie(false);
            break;
        }
        if (animaux[choixCombattantUn - 1].getRegime() != animaux[choixCombattantDeux - 1].getRegime()) {
            if (animaux[choixCombattantUn - 1].getRegime() == "predateur") {
                cout << " - " << animaux[choixCombattantUn - 1].getNom() << " (" << animaux[choixCombattantUn - 1].getEspece() << ") a battu " <<
                    animaux[choixCombattantDeux - 1].getNom() << " (" << animaux[choixCombattantDeux - 1].getEspece() << ")" << endl;
                animaux[choixCombattantDeux - 1].setVie(false);
                break;
            }
            cout << " - " << animaux[choixCombattantDeux - 1].getNom() << " (" << animaux[choixCombattantDeux - 1].getEspece() << ") a battu " <<
                animaux[choixCombattantUn - 1].getNom() << " (" << animaux[choixCombattantUn - 1].getEspece() << ")" << endl;
            animaux[choixCombattantUn - 1].setVie(false);
        }
        else if (animaux[choixCombattantUn - 1].getRegime() == "predateur") {
            int combattants[2] = { choixCombattantUn, choixCombattantDeux };
            int choixRandom = rand() % 2;
            animaux[combattants[choixRandom]].setVie(false);
            if (choixRandom == 0) {
                cout << " - " << animaux[choixCombattantDeux - 1].getNom() << " (" << animaux[choixCombattantDeux - 1].getEspece() << ") a battu "
                    << animaux[choixCombattantUn - 1].getNom() << " (" << animaux[choixCombattantUn - 1].getEspece() << ")" << endl;
                break;
            }
            cout << " - " << animaux[choixCombattantUn - 1].getNom() << " (" << animaux[choixCombattantUn - 1].getEspece() << ") a battu "
                << animaux[choixCombattantDeux - 1].getNom() << " (" << animaux[choixCombattantDeux - 1].getEspece() << ")" << endl;
        }
        else {
            cout << "Les deux proies " << animaux[choixCombattantUn - 1].getNom() << " (" << animaux[choixCombattantUn - 1].getEspece() << ") et" << animaux[choixCombattantDeux - 1].getNom() << " (" << animaux[choixCombattantDeux - 1].getEspece() << ") se font la paix!" << endl;
        }
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        return 'Q'; // QUIT
    default:
        break;
    }
    return ' ';
}