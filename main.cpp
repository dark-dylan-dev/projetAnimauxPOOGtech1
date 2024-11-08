#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool jour = true;
const int LIMITE_ANIMAUX(25);

class Joueur
{
private:

public:

};

class Animal {
private:
    string nom;
    string espece;
    string regime;
    bool enVie;
    bool aFaim;
public:

    Animal(string nom, string espece, string regime, bool enVie, bool aFaim) : nom(nom), espece(espece), regime(regime), enVie(enVie), aFaim(aFaim) {}

    void mourir()
    {
        if (!enVie) { cout << nom << " est mort" << endl; }
    }

    void attaquer(Animal& cible)
    {
        cout << nom << " attaque " << cible.getNom() << endl;
        cible.mourir();
    }

    // GETTERS

    string getNom() { return nom; }
    string getEspece() { return espece; }
    string getRegime() { return regime; }
    bool getEnVie() { return enVie; }
    bool getAFaim() { return aFaim; }
};

class Loup : public Animal
{
public:
    Loup(string nom) : Animal(nom, "Loup", "carivore", true, false) {}
};

class Jeu {
private:
    bool enCours;
public:
    Jeu() : enCours(true) {}
    ~Jeu() { enCours = false; }

    void Init(vector<Animal>& animaux) {
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
        string noms[25] = { "Loup", "espece2", "espece3", "espece4", "espece5","espece6", "espece7", "espece8", "espece9", "espece10", "espece11", "espece12", "espece13", "espece14", "espece15", "espece16", "espece17", "espece18", "espece19", "espece20", "espece21", "espece22", "espece23", "espece24", "espece25" };
        string nomAnimal;
        for (int i = 0; i < nombreDAnimaux; ++i) {
            cout << "Quel espece voulez-vous donner a votre nouvel animal ?" << endl;
            for (int i = 0; i < LIMITE_ANIMAUX; ++i) { // Affichage des choix d'espèces
                if (i < 8)
                    cout << " - " << i + 1 << ".  " << noms[i] << endl;
                if (i > 8)
                    cout << " - " << i + 1 << ". " << noms[i] << endl;
            }
            // Création de l'animal avec l'espèce choisie
            cout << endl << "Votre choix > ";
            cin >> choix;
            while (cin.fail() || choix < 1 || choix > LIMITE_ANIMAUX) {
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
            case 1: animaux.push_back(Loup(nomAnimal)); break; case 6:  break; case 11: break; case 16: break; case 21: break;
            case 2:                                     break; case 7:  break; case 12: break; case 17: break; case 22: break;
            case 3:                                     break; case 8:  break; case 13: break; case 18: break; case 23: break;
            case 4:                                     break; case 9:  break; case 14: break; case 19: break; case 24: break;
            case 5:                                     break; case 10: break; case 15: break; case 20: break; case 25: break;
            default: break;
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
};

int main()
{
    vector<Animal> animaux;

    Jeu jeu;
    jeu.Init(animaux);

    return 0;
}