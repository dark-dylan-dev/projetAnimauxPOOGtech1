#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool jour = true;

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

	virtual void mourir()
	{
		if (enVie = false)
		{
			cout << nom << " est mort" << endl;
		}
	}

	void attaquer(Animal& cible)
	{
		cout << nom << " attaque " << cible.getNom() << endl;
		cible.mourir()
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
	Loup() : Animal("Loup noir", "Loup", "carivore", true, false) {}
};

int main()
{
	cout << "test 2";
}