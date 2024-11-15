#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Animal.h"
#include "Nourriture.h"

Animal::Animal(const string& nom, const string& espece, const string& regime)
    : nom(nom), espece(espece), regime(regime), aFaim(false), enVie(true), x(0), y(0), id(-1), aFaimCount(0), pasFaim(0) {
    x = rand() % 100;
    y = rand() % 100;
}

// GETTERS
string Animal::getNom() const { return nom; }
string Animal::getEspece() const { return espece; }
bool Animal::estEnVie() const { return enVie; }
bool Animal::aFaimStatus() const { return aFaim; }
string Animal::getRegime() const { return regime; }
int Animal::getPosX() const { return x; }
int Animal::getPosY() const { return y; }
int Animal::getFaimCount() const { return aFaimCount; }
int Animal::getPasFaim() const { return pasFaim; }

void Animal::deplacement() {
    x += (rand() % 3) - 1;
    y += (rand() % 3) - 1;
}

void Animal::enTrainDeDormir() const {
    if (getEspece() == "Capybara")
        cout << " - " << getNom() << " (" << getEspece() << ") est en train de se balader." << endl << endl; return;
    cout << " - " << getNom() << " (" << getEspece() << ") est en train de dormir..." << endl << endl;
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
    if (regime == "predateur" && autre.getRegime() == "proie") {
        cout << nom << " chasse " << autre.getNom() << "\n";

        if ((x - autre.x) < -1) { x += 2; }
        else if ((x - autre.x) > 1) { x -= 2; }
        if ((y - autre.y) < -1) { y += 2; }
        else if ((y - autre.y) > 1) { y -= 2; }

        if ((x - autre.x) == -1) { x++; }
        else if ((x - autre.x) == 1) { x--; }
        if ((y - autre.y) == -1) { y++; }
        else if ((y - autre.y) == 1) { y--; }

        if (distanceAvec(autre) == 0 && aFaim == true) {
            autre.setVie(false);
            aFaim = false;
            cout << autre.getNom() << " est mort, chasse par " << getNom() << " (" << getEspece() << ")" << endl << endl;
        }
    }
    else if (regime == "proie" && autre.getRegime() == "predateur") {
        cout << nom << " (" << getEspece() << ") essaie de fuir " << autre.getNom() << " (" << autre.getEspece() << ")" << endl << endl;

        if ((x - autre.x) < 0) { x--; }
        else if ((x - autre.x) > 0) { x++; }
        if ((y - autre.y) < 0) { y--; }
        else if ((y - autre.y) > 0) { y++; }

        if (distanceAvec(autre) == 0 && autre.aFaimStatus() == true) {
            enVie = false;
            autre.setFaim(false);
            cout << nom << " est mort\n" << endl;
        }
    }
}

void Animal::afficherPosition() const {
    cout << " - [DEBUG] > " << nom << " (" << espece << ") est a la position (" << x << ", " << y << ")\n";
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
    cout << nom << " se dirige vers : " << nourr.getType() << endl;

    if ((x - nourr.getPosX()) < 0) { x++; }
    else if ((x - nourr.getPosX()) > 0) { x--; }
    if ((y - nourr.getPosY()) < 0) { y++; }
    else if ((y - nourr.getPosY()) > 0) { y--; }

    if (Animal::distanceAvecNourr(nourr) == 0) {
        cout << nom << " mange : " << nourr.getType() << endl;
        aFaim = false;
        nourr.setEtat(false);
    }
    cout << endl;
}

// SETTERS
void Animal::setVie(bool etat) { enVie = etat; }
void Animal::setFaim(bool etat) { aFaim = etat; }
void Animal::setID(int idSet) { id = idSet; }
void Animal::setNom(string nomSet) { nom = nomSet; }
void Animal::setFaimCount(int nb) {
    if (nb != 0) { aFaimCount += nb; }
    else { aFaimCount = nb; } //pour à la fois ajouter au conte si nb = 1 et le reset si nb = 0
}
void Animal::setPasFaim(int nb) {
    if (nb != 0) { pasFaim += nb; }
    else { pasFaim = nb; }
}