#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

bool jour = true;
const int LIMITE_ANIMAUX(25);

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
        std::cout << nom << " (" << espece << ") est a la position (" << x << ", " << y << ")\n";
    }
};

class Joueur
{

};

class Lapin : public Animal {
public:
    Lapin(const std::string& nom) : Animal(nom, "Lapin", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};

class Chevre : public Animal {
public:
    Chevre(const std::string& nom) : Animal(nom, "Chevre", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
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

class Cheval : public Animal {
public:
    Cheval(const std::string& nom) : Animal(nom, "Cheval", "proie") {}

    void deplacement() override {
        x += (rand() % 10) - 2;
        y += (rand() % 10) - 2;
    }
};

class Lynx : public Animal {
public:
    Lynx(const std::string& nom) : Animal(nom, "Lynx", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};

class Panda : public Animal {
public:
    Panda(const std::string& nom) : Animal(nom, "Panda", "proie") {}

    void deplacement() override {
        x += (rand() % 3) - 2;
        y += (rand() % 3) - 2;
    }
};

class Tigre : public Animal {
public:
    Tigre(const std::string& nom) : Animal(nom, "Tigre", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};

class Koala : public Animal {
public:
    Koala(const std::string& nom) : Animal(nom, "Koala", "proie") {}

    void deplacement() override {
        x += (rand() % 3) - 2;
        y += (rand() % 3) - 2;
    }
};

class Ecureuil : public Animal {
public:
    Ecureuil(const std::string& nom) : Animal(nom, "Ecureuil", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
    }
};

class Puma : public Animal {
public:
    Puma(const std::string& nom) : Animal(nom, "Puma", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
    }
};

class Coyote : public Animal {
public:
    Coyote(const std::string& nom) : Animal(nom, "Coyote", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
    }
};

class Rat : public Animal {
public:
    Rat(const std::string& nom) : Animal(nom, "Rat", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
    }
};

class Bison : public Animal {
public:
    Bison(const std::string& nom) : Animal(nom, "Bison", "predateur") {}

    void deplacement() override {
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }
};

class Lama : public Animal {
public:
    Lama(const std::string& nom) : Animal(nom, "Lama", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};

class Aigle : public Animal {
public:
    Aigle(const std::string& nom) : Animal(nom, "Aigle", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};

class Elephant : public Animal {
public:
    Elephant(const std::string& nom) : Animal(nom, "Elephant", "proie") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
    }
};

class Fennec : public Animal {
public:
    Fennec(const std::string& nom) : Animal(nom, "Fennec", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};

class Jaguar : public Animal {
public:
    Jaguar(const std::string& nom) : Animal(nom, "Jaguar", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};

class Zebre : public Animal {
public:
    Zebre(const std::string& nom) : Animal(nom, "Zebre", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};

class Castor : public Animal {
public:
    Castor(const std::string& nom) : Animal(nom, "Castor", "proie") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
    }
};

class Lion : public Animal {
public:
    Lion(const std::string& nom) : Animal(nom, "Lion", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};

class Capybara : public Animal {
public:
    Capybara(const std::string& nom) : Animal(nom, "Capybara", "proie") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
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
        string noms[25] = { "Loup", "Lapin", "Ours", "Biche", "Renard","Chevre", "Cheval", "Lynx", "Panda", "Tigre", "Koala", "Ecureuil", "Puma", "Coyote", "Rat", "Bison", "Lama", "Aigle", "Elephant", "Fennec", "Jaguar", "Zebre", "Castor", "Lion", "Capybara" };
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
            case 1: animaux.push_back(Loup(nomAnimal));   break; case 6: animaux.push_back(Chevre(nomAnimal)); break; case 11: animaux.push_back(Koala(nomAnimal)); break; case 16: animaux.push_back(Bison(nomAnimal)); break; case 21: animaux.push_back(Jaguar(nomAnimal)); break;
            case 2: animaux.push_back(Lapin(nomAnimal));  break; case 7: animaux.push_back(Cheval(nomAnimal)); break; case 12: animaux.push_back(Ecureuil(nomAnimal)); break; case 17: animaux.push_back(Lama(nomAnimal)); break; case 22: animaux.push_back(Zebre(nomAnimal)); break;
            case 3: animaux.push_back(Ours(nomAnimal));   break; case 8: animaux.push_back(Lynx(nomAnimal)); break; case 13: animaux.push_back(Puma(nomAnimal)); break; case 18: animaux.push_back(Aigle(nomAnimal)); break; case 23: animaux.push_back(Castor(nomAnimal)); break;
            case 4: animaux.push_back(Biche(nomAnimal));  break; case 9: animaux.push_back(Panda(nomAnimal)); break; case 14: animaux.push_back(Coyote(nomAnimal)); break; case 19: animaux.push_back(Elephant(nomAnimal)); break; case 24: animaux.push_back(Lion(nomAnimal)); break;
            case 5: animaux.push_back(Renard(nomAnimal)); break; case 10: animaux.push_back(Tigre(nomAnimal)); break; case 15: animaux.push_back(Rat(nomAnimal)); break; case 20: animaux.push_back(Fennec(nomAnimal)); break; case 25: animaux.push_back(Capybara(nomAnimal)); break;
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
