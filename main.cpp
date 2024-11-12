#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

bool jour = true;
const int LIMITE_ANIMAUX(25);

class Joueur
{

};

class Animal {
private:
    std::string nom;
    std::string espece;
    std::string regime;
    bool aFaim;
    bool enVie;

protected:
    int x, y;

public:
    Animal(const string& nom, const string& espece, const string& regime)
        : nom(nom), espece(espece), regime(regime), aFaim(false), enVie(true), x(0), y(0) {
        x = rand() % 100;
        y = rand() % 100;
    }

    std::string getNom() const { return nom; }
    std::string getEspece() const { return espece; }
    bool estEnVie() const { return enVie; }
    bool aFaimStatus() const { return aFaim; }
    std::string getRegime() const { return regime; }


    virtual void deplacement() { // Déplacement en [-1;1] par défaut
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }

    float distanceAvec(const Animal& autre) const {
        int dx = x - autre.x;
        int dy = y - autre.y;
        return (float)sqrt(dx * dx + dy * dy);
    }

    virtual void interagir(Animal& autre) {
        aFaim = true;
        if (regime == "predateur" && autre.getRegime() == "proie" && aFaim) {
            if (distanceAvec(autre) < 5.0) {
                std::cout << nom << " chasse " << autre.getNom() << "!\n";
            }
        }
        else if (regime == "proie" && autre.getRegime() == "predateur") {
            if (distanceAvec(autre) < 5.0) {
                std::cout << nom << " essaie de fuir " << autre.getNom() << "!\n";
                x += (x - autre.x);
                y += (y - autre.y);
            }
            else if (distanceAvec(autre) < 1.0f) {
                enVie = false;
                std::cout << nom << " est mort\n";
            }
        }
    }

    void afficherPosition() const {
        std::cout << nom << " (" << espece << ") est à la position (" << x << ", " << y << ")\n";
    }
};

class Lapin : public Animal {
public:
    Lapin(const std::string& nom) : Animal(nom, "Lapin", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};

class Biche : public Animal {
public:
    Biche(const std::string& nom) : Animal(nom, "Biche", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};

class Loup : public Animal {
public:
    Loup(const std::string& nom) : Animal(nom, "Loup", "predateur") {}

    void deplacement() override {
        x += (rand() % 5) - 1;
        y += (rand() % 5) - 1;
    }
};

class Ours : public Animal {
public:
    Ours(const std::string& nom) : Animal(nom, "Ours", "predateur") {}

    void deplacement() override {
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }
};

class Renard : public Animal {
public:
    Renard(const std::string& nom) : Animal(nom, "Renard", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
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
        string noms[25] = { "Loup", "Lapin", "Ours", "Biche", "Renard","espece6", "espece7", "espece8", "espece9", "espece10", "espece11", "espece12", "espece13", "espece14", "espece15", "espece16", "espece17", "espece18", "espece19", "espece20", "espece21", "espece22", "espece23", "espece24", "espece25" };
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
            case 1: animaux.push_back(Loup(nomAnimal));   break; case 6:  break; case 11: break; case 16: break; case 21: break;
            case 2: animaux.push_back(Lapin(nomAnimal));  break; case 7:  break; case 12: break; case 17: break; case 22: break;
            case 3: animaux.push_back(Ours(nomAnimal));   break; case 8:  break; case 13: break; case 18: break; case 23: break;
            case 4: animaux.push_back(Biche(nomAnimal));  break; case 9:  break; case 14: break; case 19: break; case 24: break;
            case 5: animaux.push_back(Renard(nomAnimal)); break; case 10: break; case 15: break; case 20: break; case 25: break;
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


int main() {
    srand(time(0));

    std::vector<Animal> animaux;
    int tour = 0;

    Jeu jeu;
    jeu.Init(animaux);
    jeu.BoucleDeJeu(animaux, tour);

    animaux.clear();

    return 0;
}