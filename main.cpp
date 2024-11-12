#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

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
    int x, y;

public:

    Animal(string nom, string espece, string regime, bool enVie, bool aFaim, int x, int y) : nom(nom), espece(espece), regime(regime), enVie(enVie), aFaim(aFaim), posX(x), posY(y) {
        x = rand() % 100;
        y = rand() % 100;
        enVie = true;
        aFaim = false;
    }

    void mourir() const
    {
        if (!enVie) 
        { 
            cout << nom << " est mort" << endl; 
            enVie = false;
        }
    }

    void attaquer(Animal& cible) const
    {
        cout << nom << " attaque " << cible.getNom() << endl;
        cible.mourir();
    }

    void afficherPosition(Animal& concerne) const {
        cout << " - [DEBUG] : " << concerne.getNom() << " (" << concerne.getEspece() << ") se trouve en x : " << concerne.x << " y : " << concerne.y << endl;
    }

    virtual void deplacement() { // Plage de déplacement en [-1;1] par défaut
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }

    virtual void interagir(Animal& autre) {
        if (regime == "predateur" && autre.getRegime() == "proie" && aFaim) { // Est un prédateur
            if (distanceAvec(autre) < 5.0) {
                std::cout << nom << " chasse " << autre.getNom() << "!\n";
            }
        }
        else if (regime == "proie" && autre.getRegime() == "predateur") { // Est une proie
            if (distanceAvec(autre) < 5.0) {
                std::cout << nom << " essaie de fuir " << autre.getNom() << "!\n";
                x += (x - autre.x);
                y += (y - autre.y);
            }
        }
    }

    // GETTERS

    string getNom()       { return nom;    }
    string getEspece()    { return espece; }
    string getRegime()    { return regime; }
    bool getEnVie() const { return enVie;  }
    bool getAFaim() const { return aFaim;  }
    float distanceAvec(const Animal& autre) const {
        int dx = x - autre.x;
        int dy = y - autre.y;
        return (float)sqrt(dx * dx + dy * dy);
    }

    // SETTERS

    void setFaim() { aFaim = true; }
};

class Loup : public Animal {
public:
    Loup(string nom) : Animal(nom, "Loup", "predateur") {}

    void deplacement() override {
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }
};

class Lapin : public Animal {
public:
    Lapin(string nom) : Animal(nom, "Lapin", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
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
        string noms[25] = { "Loup", "Lapin", "espece3", "espece4", "espece5","espece6", "espece7", "espece8", "espece9", "espece10", "espece11", "espece12", "espece13", "espece14", "espece15", "espece16", "espece17", "espece18", "espece19", "espece20", "espece21", "espece22", "espece23", "espece24", "espece25" };
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
            case 1: animaux.push_back(Loup(nomAnimal));  break; case 6:  break; case 11: break; case 16: break; case 21: break;
            case 2: animaux.push_back(Lapin(nomAnimal)); break; case 7:  break; case 12: break; case 17: break; case 22: break;
            case 3:                                      break; case 8:  break; case 13: break; case 18: break; case 23: break;
            case 4:                                      break; case 9:  break; case 14: break; case 19: break; case 24: break;
            case 5:                                      break; case 10: break; case 15: break; case 20: break; case 25: break;
            default: break;
            }
        }
        // Affichage des infos des animaux crées
        cout << "Infos des animaux crees :" << endl;
        for (int i = 0; i < animaux.size(); ++i) {
            cout << endl << " - Nom : "                  << animaux[i].getNom()    << endl;
            cout <<         "   - Espece : "             << animaux[i].getEspece() << endl;
            cout <<         "   - Regime alimentaire : " << animaux[i].getRegime() << endl;
        }
    }

    void BoucleDeJeu(vector<Animal>& animaux, int& tour) {
        while (tour < 10)
        {
            tour++; // On commence au tour n°1
            cout << endl << "Tour : " << tour << endl;
            for (int i = 0; i < animaux.size(); ++i) {
                animaux[i].deplacement();
                animaux[i].afficherPosition();
                for (int j = i + 1; j < animaux.size(); ++j) {
                    animaux[i].interagir(animaux[j]);
                }
                animaux[(animaux.size() - 1)].interagir(animaux[0]); // Le cas ou le dernier interagit avec le premier (impossible dans la boucle for)
            }
        }
    }
};

int main()
{
    vector<Animal> animaux;
    int tour = 0;

    Jeu jeu;
    jeu.Init(animaux);
    jeu.BoucleDeJeu(animaux, tour);

    animaux.clear();

    return 0;
}
