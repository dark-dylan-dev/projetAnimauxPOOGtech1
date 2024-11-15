#include <iostream>
#include <vector>

#include "Jeu.h"
#include "Joueur.h"
#include "Animal.h"
#include "AnimalDerive.h"
#include "Nourriture.h"
#include "CentrerTexte.h"

using namespace std;

void Jeu::Init(vector<Animal>& animaux, vector<Nourriture>& nourritures) {

    const int NB_NOURRITURE = 500; // Grille de 100x100, 10.000 cases -> 500 nourritures = 5%
    std::string typeNourriture[7] = { "fruits", "champignons","insectes","feuilles","cadavre","bambou","canne a sucre" };
    for (int i = 0; i < NB_NOURRITURE; i++) {
        nourritures.push_back(Nourriture(typeNourriture[rand() % 7]));
    }

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
        for (unsigned int i = 0; i < animaux.size(); ++i) {
            animaux[i].id = i + 1; // 1, 2, 3... animaux.size()
        }
    }
    // Affichage des infos des animaux crées
    cout << "Infos des animaux crees :" << endl;
    for (unsigned int i = 0; i < animaux.size(); ++i) {
        cout << endl << " - Nom : " << animaux[i].getNom() << endl;
        cout << "   - Espece : " << animaux[i].getEspece() << endl;
        cout << "   - Regime alimentaire : " << animaux[i].getRegime() << endl;
    }
}

void Jeu::BoucleDeJeu(vector<Animal>& animaux, int& tour, bool debug, Joueur& joueur, vector<Nourriture>& nourritures) {
    const int rayonReperageAnimaux = 15;
    const int rayonReperageNourriture = 20;
    int nbInteractions = 0;

    string periode;
    bool seNourrit = false;
    while (true) {
        if (!debug) { system("cls"); }
        tour++;
        estJour ? periode = "Jour" : periode = "Nuit";
        string affichageTour = "Tour : " + to_string(tour);
        string affichagePeriode = "Meteo : " + periode;
        string affichageSaisonDesAmours = "Saison des amours > " + to_string(joueur.compteurAmour) + " jour(s) restant(s)";
        test = rand() % 5;
        if (test == 0) { meteo = "Beau temps"; }
        if (test == 1) { meteo = "Pluie"; }
        if (test == 2) { meteo = "Tempete"; }
        if (test == 3) { meteo = "Orage"; }
        if (test == 4) { meteo = "Nuageux"; }
        if (test == 5) { meteo = "Venteux"; }
        // --- AFFICHAGES INFOS EN-TETE --- //
        cout << affichageTour << endl;
        cout << affichagePeriode << endl;
        if (joueur.saisonDesAmours && joueur.compteurAmour > 0) {
            cout << affichageSaisonDesAmours << endl;
            joueur.incrCompteur();
        }
        cout << meteo << endl;
        // --- FIN AFFICHAGE EN-TETE -- //
        int choixJoueur = joueur.afficherInfos(animaux);
        if (joueur.choixJoueur(choixJoueur, animaux) == 'Q') { exit(0); }
        for (unsigned int i = 0; i < animaux.size(); ++i) {
            if (animaux[i].estEnVie()) {
                estJour ? animaux[i].deplacement() : animaux[i].enTrainDeDormir();
                if (debug) { animaux[i].afficherPosition(); }
                //--- RECHERCHE D'ANIMAUX ---//
                for (int x = -rayonReperageAnimaux; x < rayonReperageAnimaux; ++x) {
                    for (int y = -rayonReperageAnimaux; y < rayonReperageAnimaux; ++y) {
                        for (auto& animal : animaux) {
                            if (animal.estEnVie() == true && (animaux[i].getPosX() - animal.getPosX()) == x && (animaux[i].getPosY() - animal.getPosY()) == y) {
                                if (x != 0 && y != 0) {
                                    animaux[i].interagir(animal);
                                    nbInteractions++;
                                    if (animal.estEnVie() == false) { seNourrit = true; }
                                    goto sortie;
                                }
                            }
                        }
                    }
                }
            }
            //--- RECHERCHE DE NOURRITURE (si aucun animal rencontré) ---//
            if (nbInteractions == 0 && animaux[i].aFaimStatus() && animaux[i].estEnVie()) { //check si vivant pour qu'une proie chassée dans le meme tour ne puisse pas manger de la nourriture
                for (int x = -rayonReperageNourriture; x < rayonReperageNourriture; ++x) {
                    for (int y = -rayonReperageNourriture; y < rayonReperageNourriture; ++y) {
                        for (auto& nourriture : nourritures) {
                            if (nourriture.getEtat() == true && (animaux[i].getPosX() - nourriture.getPosX()) == x && (animaux[i].getPosY() - nourriture.getPosY()) == y) {
                                animaux[i].cherchNourr(nourriture, nourritures);
                                if (nourriture.getEtat() == false) { seNourrit = true; } // si y'a eu contact dans l'interaction alors l'animal a mangé
                                goto sortie;
                            }
                        }
                    }
                }
            }
        sortie:
            nbInteractions = 0;
            if (!seNourrit && animaux[i].aFaimStatus()) //si l'animal a faim mais ne s'est pas nourrit
                animaux[i].setFaimCount(1); //on compte le nombre de demi journées passées sans manger
            else {
                animaux[i].setFaimCount(0);
            }
            seNourrit = false;
            if (animaux[i].getFaimCount() == 20) //surement trop grand comme nombre ?
                animaux[i].setVie(false);
            if (!animaux[i].aFaimStatus()) { animaux[i].setPasFaim(1); }
            if (animaux[i].getPasFaim() == 4) {
                animaux[i].setFaim(true);
                animaux[i].setPasFaim(0);
            }
        }
        system("PAUSE");
        estJour = !estJour;
    }
}
