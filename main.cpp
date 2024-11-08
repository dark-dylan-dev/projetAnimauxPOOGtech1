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
        cout << endl;
        int* nouveauxAnimaux = new int[nombreDAnimaux];
        int choix;
        string noms[25] = { "exemple1", "exemple2", "exemple3", "exemple4", "exemple5","exemple6", "exemple7", "exemple8", "exemple9", "exemple10", "exemple11", "exemple12", "exemple13", "exemple14", "exemple15", "exemple16", "exemple17", "exemple18", "exemple19", "exemple20", "exemple21", "exemple22", "exemple23", "exemple24", "exemple25" };
        string nomAnimal;
        for (int i = 0; i < nombreDAnimaux; ++i) {
            cout << "Quel espece voulez-vous donner a votre nouvel animal ?" << endl;
            for (int i = 0; i < LIMITE_ANIMAUX; ++i) {
                cout << " - " << i+1 << ". " << noms[i] << endl;
            }
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
            switch (choix) {
            case 1: animaux.push_back(Loup(nomAnimal)); break; case 6:  break; case 11: break; case 16: break; case 21: break;
            case 2:                                     break; case 7:  break; case 12: break; case 17: break; case 22: break;
            case 3:                                     break; case 8:  break; case 13: break; case 18: break; case 23: break;
            case 4:                                     break; case 9:  break; case 14: break; case 19: break; case 24: break;
            case 5:                                     break; case 10: break; case 15: break; case 20: break; case 25: break; 
            default: break;
            }
        }
        cout << "Noms des animaux crees :" << endl;
        for (int i = 0; i < animaux.size(); ++i) {
            cout << " - " << animaux[i].getNom() << endl;
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