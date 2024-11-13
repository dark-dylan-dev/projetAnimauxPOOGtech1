#include <iostream>
#include <vector>

#include "Jeu.h"
#include "Joueur.h"
#include "Animal.h"
#include "AnimalDerive.h"

using namespace std;

void Jeu::Init(vector<Animal>& animaux) {
    int nombreDAnimaux(0);
    cout << "Combien d'animaux voulez-vous creer dans votre partie (entre 3 et 25) ? > ";
    cin >> nombreDAnimaux;
    while (cin.fail() || nombreDAnimaux < 3 || nombreDAnimaux > 25) {
        cin.clear();
        cin.ignore(9999, '\n');
        cout << endl << "Veuillez entrer un nombre valide d'animaux a creer, entre 3 et 25 > ";
        cin >> nombreDAnimaux;
    }
    int choix;
    cout << "---" << endl << "Les espces apres Loup sont juste des exmples pour l'instant" << endl << "---" << endl;
    string noms[25] = { "Loup", "Lapin", "Ours", "Biche", "Renard","Chevre", "Cheval", "Lynx", "Panda", "Tigre", "Koala", "Ecureuil", "Puma", "Coyote", "Rat", "Bison", "Lama", "Aigle", "Elephant", "Fennec", "Jaguar", "Zebre", "Castor", "Lion", "Capybara" };
    string nomAnimal;
    for (int i = 0; i < nombreDAnimaux; ++i) {
        cout << "Quel espece voulez-vous donner a votre nouvel animal ?" << endl;
        for (int i = 0; i < 25; ++i) { // Affichage des choix d'espèces
            if (i < 8)
                cout << " - " << i + 1 << ".  " << noms[i] << endl;
            if (i > 8)
                cout << " - " << i + 1 << ". " << noms[i] << endl;
        }
        // Création de l'animal avec l'espèce choisie
        cout << endl << "Votre choix > ";
        cin >> choix;
        while (cin.fail() || choix < 1 || choix > 25) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << endl << "Veuillez entrer un choix correct, entre 1 et 25 > ";
            cin >> choix;
        }
        cout << endl << "Quel est le nom que vous voulez donner a votre nouveau " << noms[choix - 1] << " ? > ";
        cin >> nomAnimal;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << endl << "Veuillez donner un nom valide a votre animal > ";
            cin >> nomAnimal;
        }
        cout << endl;
        // Ajout de l'animal crée dans le vecteur animaux
        switch (choix) { // A changer mardi avec les noms des espèces (vide pour l'instant)
        case 1: animaux.push_back(Loup(nomAnimal));   break; case 6: animaux.push_back(Chevre(nomAnimal)); break; case 11: animaux.push_back(Koala(nomAnimal));    break; case 16: animaux.push_back(Bison(nomAnimal));    break; case 21: animaux.push_back(Jaguar(nomAnimal));   break;
        case 2: animaux.push_back(Lapin(nomAnimal));  break; case 7: animaux.push_back(Cheval(nomAnimal)); break; case 12: animaux.push_back(Ecureuil(nomAnimal)); break; case 17: animaux.push_back(Lama(nomAnimal));     break; case 22: animaux.push_back(Zebre(nomAnimal));    break;
        case 3: animaux.push_back(Ours(nomAnimal));   break; case 8: animaux.push_back(Lynx(nomAnimal));   break; case 13: animaux.push_back(Puma(nomAnimal));     break; case 18: animaux.push_back(Aigle(nomAnimal));    break; case 23: animaux.push_back(Castor(nomAnimal));   break;
        case 4: animaux.push_back(Biche(nomAnimal));  break; case 9: animaux.push_back(Panda(nomAnimal));  break; case 14: animaux.push_back(Coyote(nomAnimal));   break; case 19: animaux.push_back(Elephant(nomAnimal)); break; case 24: animaux.push_back(Lion(nomAnimal));     break;
        case 5: animaux.push_back(Renard(nomAnimal)); break; case 10: animaux.push_back(Tigre(nomAnimal)); break; case 15: animaux.push_back(Rat(nomAnimal));      break; case 20: animaux.push_back(Fennec(nomAnimal));   break; case 25: animaux.push_back(Capybara(nomAnimal)); break;
        default: break;
        }
        for (int i = 0; i < animaux.size(); ++i) {
            animaux[i].id = i + 1; // 1, 2, 3... animaux.size()
        }
    }
    // Affichage des infos des animaux crées
    cout << "Infos des animaux crees :" << endl;
    for (int i = 0; i < animaux.size(); ++i) {
        cout << endl << " - Nom : " << animaux[i].getNom() << endl;
        cout << "   - Espece : " << animaux[i].getEspece() << endl;
        cout << "   - Regime alimentaire : " << animaux[i].getRegime() << endl;
    }
}

void Jeu::BoucleDeJeu(vector<Animal>& animaux, int& tour, bool debug, Joueur& joueur) {
    const int rayonReperage = 25;
    while (tour < 10) {
        if (!debug) { system("cls"); }
        tour++;
        cout << endl << "Tour : " << tour << endl;
        int choixJoueur = joueur.afficherInfos(animaux);
        joueur.choixJoueur(choixJoueur, animaux);
        for (int i = 0; i < animaux.size(); ++i) {
            estJour ? animaux[i].deplacement() : animaux[i].enTrainDeDormir();
            if (debug) { animaux[i].afficherPosition(); }
            //--- RECHERCHE D'ANIMAL DANS UN RAYON DE (rayonReperage) blocs ---//
            int* idVus = new int[animaux.size()];
            for (int l = 0; l < animaux.size(); ++l) { idVus[l] = -1; }
            int j = i + 1;
            if (j == animaux.size()) { j = 0; }
            for (int x = -rayonReperage; x < rayonReperage; ++x) {
                for (int y = -rayonReperage; y < rayonReperage; ++y) {
                    if ((animaux[i].getPosX() - animaux[j].getPosX()) == x && (animaux[i].getPosY() - animaux[j].getPosY()) == y) {
                        for (int k = 0; k < animaux.size(); ++k)
                            for (int k2 = 0; k2 < animaux.size(); ++k2)
                                if (idVus[k] == k2) { break; }
                        idVus[i] = animaux[i].id;
                        animaux[i].interagir(animaux[j]);
                        // Intéragit si et seulement si l'animal n'a jamais été concerné pendant cette itération
                    }
                }
            }
            delete[] idVus;
            //--- FIN DE RECHERCHE ---//
        }
        system("PAUSE");
        estJour = !estJour;
    }
}