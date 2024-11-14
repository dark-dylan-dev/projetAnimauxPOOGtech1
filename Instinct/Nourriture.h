#ifndef NOURRITURE_H
#define NOURRITURE_H



class Nourriture {
private:
	std::string type;
	int x, y;
	bool etat;
public:
	Nourriture(std::string type) : type(type), x(rand() % 100), y(rand() % 100), etat(true) {}

	/*float distanceAvecNourr(Nourriture& nourriture) const {};*/

	std::string getType() const { return type; }
	int getPosX() const { return x; }
	int getPosY() const { return y; }
	int getEtat() const { return etat; }
	void setEtat(bool nvEtat) { etat = nvEtat; }
};

#endif
