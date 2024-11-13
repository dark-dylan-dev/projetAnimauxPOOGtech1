#include <iostream>
#include <vector>
#include <string>

#include "Animal.h"

Animal::Animal(const std::string& nom, const std::string& espece, const std::string& regime)
    : nom(nom), espece(espece), regime(regime), aFaim(false), enVie(true), x(0), y(0), id(-1) {
    x = rand() % 100;
    y = rand() % 100;
}

// GETTERS
std::string Animal::getNom() const { return nom; }
std::string Animal::getEspece() const { return espece; }
bool Animal::estEnVie() const { return enVie; }
bool Animal::aFaimStatus() const { return aFaim; }
std::string Animal::getRegime() const { return regime; }
int Animal::getPosX() const { return x; }
int Animal::getPosY() const { return y; }


void Animal::deplacement() {
    x += (rand() % 3) - 1;
    y += (rand() % 3) - 1;
}

void Animal::enTrainDeDormir() const {
    if (getEspece() == "Capybara")
        cout << " - " << getNom() << " (" << getEspece() << ") est en train de se balader." << endl; return;
    cout << " - " << getNom() << " (" << getEspece() << ") est en train de dormir..." << endl;
}

float Animal::distanceAvec(const Animal& autre) const {
    int dx = x - autre.x;
    int dy = y - autre.y;
    return (float)sqrt(dx * dx + dy * dy);
}

void Animal::interagir(Animal& autre) {
    aFaim = true;
    if (regime == "predateur" && autre.getRegime() == "proie" && aFaim) {
        cout << nom << " chasse " << autre.getNom() << "\n";
        autre.x += (autre.x - x);
        autre.y += (autre.y - y);
        if (distanceAvec(autre) == 0) {
            autre.setVie(false);
            cout << autre.getNom() << " est mort\n";
        }
    }
    else if (regime == "proie" && autre.getRegime() == "predateur") {
        cout << nom << " essaie de fuir " << autre.getNom() << "\n";
        x += (x - autre.x);
        y += (y - autre.y);
        if (distanceAvec(autre) == 0) {
            enVie = false;
            cout << nom << " est mort\n";
        }
    }
}

void Animal::afficherPosition() const {
    cout << nom << " (" << espece << ") est a la position (" << x << ", " << y << ")\n";
}

// SETTERS
void Animal::setVie(bool etat) { enVie = etat; }
void Animal::setFaim(bool etat) { aFaim = etat; }
void Animal::setID(int idSet) { id = idSet; }
void Animal::setNom(std::string nomSet) { nom = nomSet; }