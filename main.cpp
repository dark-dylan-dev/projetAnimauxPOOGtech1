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
public:
	string nom;
	string espece;
	string regime;
	bool enVie;
	bool aFaim;

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