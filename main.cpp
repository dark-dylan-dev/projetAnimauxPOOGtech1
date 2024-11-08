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

	Animal(string nom, string espece, string regime, bool enVie, bool aFaim) : nom(n), espece(e), regime(r), enVie(ev), aFaim(af) {}

	virtual void mourir()
	{
		if (enVie = false)
		{
			cout << nom << " est mort" << endl;
		}
	}
};

class Loup : public Animal 
{
public:
	Loup() : Animal("Loup noir", "Loup", "carivore", true, false) {}
};

int main()
{
	cout << "test";
}