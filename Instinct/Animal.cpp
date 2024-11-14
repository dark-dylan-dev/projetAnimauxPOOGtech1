#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Animal.h"
#include "Nourriture.h"

Animal::Animal(const std::string& nom, const std::string& espece, const std::string& regime)
    : nom(nom), espece(espece), regime(regime), aFaim(false), enVie(true), x(0), y(0), id(-1), aFaimCount(0) {
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
int Animal::getFaimCount() const { return aFaimCount; }

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

float Animal::distanceAvecNourr(const Nourriture& nourriture) const {
    int dx = x - nourriture.getPosX();
    int dy = y - nourriture.getPosY();
    return (float)sqrt(dx * dx + dy * dy);
}

void Animal::interagir(Animal& autre) {
    if (regime == "predateur" && autre.getRegime() == "proie" && aFaim) {
        cout << nom << " chasse " << autre.getNom() << "\n";
        autre.x += 2*(autre.x - x);
        autre.y += 2*(autre.y - y);
        if (distanceAvec(autre) == 0) {
            autre.setVie(false);
            cout << autre.getNom() << " est mort, chasse par " << getNom() << " (" << getEspece() << ")" << endl;
        }
    }
    else if (regime == "proie" && autre.getRegime() == "predateur") {
        cout << nom << " (" << getEspece() << ") essaie de fuir " << autre.getNom() << " (" << autre.getEspece() << ")" << endl;
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

void Animal::setPosition(int newPosX, int newPosY) {
    x = newPosX;
    y = newPosY;
}

void Animal::deplacerVers(Animal& AnimalUn, Animal& AnimalDeux) {
    int xDiff = AnimalDeux.getPosX() - AnimalUn.getPosX();
    int yDiff = AnimalUn.getPosY() - AnimalDeux.getPosY();
    AnimalUn.setPosition(AnimalUn.getPosX() + xDiff, AnimalUn.getPosY() + yDiff);
}

void Animal::cherchNourr(Nourriture& nourr, vector<Nourriture>& nourritures) {
    std::cout << nom << " se dirige vers : " << nourr.getType() << std::endl;
    x += (x - nourr.getPosX());
    y += (y - nourr.getPosY());
    if (Animal::distanceAvecNourr(nourr) == 0) {
        std::cout << nom << " mange : " << nourr.getType() << std::endl;
        aFaim = false;
        nourr.setEtat(false);
    }
}

// SETTERS
void Animal::setVie(bool etat) { enVie = etat; }
void Animal::setFaim(bool etat) { aFaim = etat; }
void Animal::setID(int idSet) { id = idSet; }
void Animal::setNom(std::string nomSet) { nom = nomSet; }
void Animal::setFaimCount(int nb) {
    if (nb != 0) { aFaimCount += nb; }
    else { aFaimCount = nb; } //pour à la fois ajouter au conte si nb = 1 et le reset si nb = 0
}