#ifndef DERIVE_ANIMAL_H
#define DERIVE_ANIMAL_H

#include "Animal.h"
#include <string>

using namespace std;

class Loup : public Animal {
public:
    Loup(const string& nom) : Animal(nom, "Loup", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 5) - 1;
            y += (rand() % 5) - 1;
        }
        else {
            cout << getNom() << " (Loup) se balade et hurle au clair de lune\n";
        }
    }
};

class Lapin : public Animal {
public:
    Lapin(const string& nom) : Animal(nom, "Lapin", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 5) - 2;
            y += (rand() % 5) - 2;
        }
        else {
            cout << getNom() << " (Lapin) se cache la nuit\n";
        }
    }
};

class Chevre : public Animal {
public:
    Chevre(const string& nom) : Animal(nom, "Chevre", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 2;
            y += (rand() % 6) - 2;
        }
        else {
            cout << getNom() << " (Chevre) se met au chaud pour se reposer\n";
        }
    }
};

class Biche : public Animal {
public:
    Biche(const string& nom) : Animal(nom, "Biche", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 5) - 2;
            y += (rand() % 5) - 2;
        }
        else {
            cout << getNom() << " (Biche) cherche un endroit ou dormir\n";
        }
    }
};

class Ours : public Animal {
public:
    Ours(const string& nom) : Animal(nom, "Ours", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 3) - 1;
            y += (rand() % 3) - 1;
        }
        else {
            cout << getNom() << " (Ours) se balade dans les rivieres\n";
        }
    }
};

class Renard : public Animal {
public:
    Renard(const string& nom) : Animal(nom, "Renard", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 1;
            y += (rand() % 6) - 1;
        }
        else {
            cout << getNom() << " (Renard) se pose près d'un arbre\n";
        }
    }
};

class Cheval : public Animal {
public:
    Cheval(const string& nom) : Animal(nom, "Cheval", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 10) - 2;
            y += (rand() % 10) - 2;
        }
        else {
            cout << getNom() << " (Cheval) s'allonge dans un coin tranquille\n";
        }
    }
};

class Lynx : public Animal {
public:
    Lynx(const string& nom) : Animal(nom, "Lynx", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 7) - 1;
            y += (rand() % 7) - 1;
        }
        else {
            cout << getNom() << " (Lynx) part chasser\n";
        }
    }
};

class Panda : public Animal {
public:
    Panda(const string& nom) : Animal(nom, "Panda", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 3) - 2;
            y += (rand() % 3) - 2;
        }
        else {
            cout << getNom() << " (Panda) mange son bambou\n";
        }
    }
};

class Tigre : public Animal {
public:
    Tigre(const string& nom) : Animal(nom, "Tigre", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 8) - 1;
            y += (rand() % 8) - 1;
        }
        else {
            cout << getNom() << " (Tigre) cherche sa prochaine proie\n";
        }
    }
};

class Koala : public Animal {
public:
    Koala(const string& nom) : Animal(nom, "Koala", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 3) - 2;
            y += (rand() % 3) - 2;
        }
        else {
            cout << getNom() << " (Koala) grimpe aux arbres\n";
        }
    }
};

class Ecureuil : public Animal {
public:
    Ecureuil(const string& nom) : Animal(nom, "Ecureuil", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 2;
            y += (rand() % 6) - 2;
        }
        else {
            cout << getNom() << " (Ecureuil) se met dans son terrier\n";
        }
    }
};

class Puma : public Animal {
public:
    Puma(const string& nom) : Animal(nom, "Puma", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 1;
            y += (rand() % 6) - 1;
        }
        else {
            cout << getNom() << " (Puma) fait des courses avec d'autres Puma\n";
        }
    }
};

class Coyote : public Animal {
public:
    Coyote(const string& nom) : Animal(nom, "Coyote", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 1;
            y += (rand() % 6) - 1;
        }
        else {
            cout << getNom() << " (Coyote) se balade dans l'obscurite\n";
        }
    }
};

class Rat : public Animal {
public:
    Rat(const string& nom) : Animal(nom, "Rat", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 6) - 2;
            y += (rand() % 6) - 2;
        }
        else {
            cout << getNom() << " (Rat) cherche du fromage\n";
        }
    }
};

class Bison : public Animal {
public:
    Bison(const std::string& nom) : Animal(nom, "Bison", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 3) - 2;
            y += (rand() % 3) - 2;
        }
        else {
            cout << getNom() << " (Bison) se deplace\n";
        }
    }
};

class Lama : public Animal {
public:
    Lama(const string& nom) : Animal(nom, "Lama", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 5) - 2;
            y += (rand() % 5) - 2;
        }
        else {
            cout << getNom() << " (Lama) se repose\n";
        }
    }
};

class Aigle : public Animal {
public:
    Aigle(const string& nom) : Animal(nom, "Aigle", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 7) - 1;
            y += (rand() % 7) - 1;
        }
        else {
            cout << getNom() << " (Aigle) dors\n";
        }
    }
};

class Elephant : public Animal {
public:
    Elephant(const string& nom) : Animal(nom, "Elephant", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 4) - 2;
            y += (rand() % 4) - 2;
        }
        else {
            cout << getNom() << " (Elephant) se baigne dans une riviere\n";
        }
    }
};

class Fennec : public Animal {
public:
    Fennec(const string& nom) : Animal(nom, "Fennec", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 8) - 1;
            y += (rand() % 8) - 1;
        }
        else {
            cout << getNom() << " (Fennec) joue avec ses congeneres\n";
        }
    }
};

class Jaguar : public Animal {
public:
    Jaguar(const string& nom) : Animal(nom, "Jaguar", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 8) - 1;
            y += (rand() % 8) - 1;
        }
        else {
            cout << getNom() << " (Jaguar) se decide a chasser\n";
        }
    }
};

class Zebre : public Animal {
public:
    Zebre(const string& nom) : Animal(nom, "Zebre", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 5) - 2;
            y += (rand() % 5) - 2;
        }
        else {
            cout << getNom() << " (Zebre) va se coucher\n";
        }
    }
};

class Castor : public Animal {
public:
    Castor(const string& nom) : Animal(nom, "Castor", "proie") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 4) - 2;
            y += (rand() % 4) - 2;
        }
        else {
            cout << getNom() << " (Castor) construit un barage\n";
        }
    }
};

class Lion : public Animal {
public:
    Lion(const string& nom) : Animal(nom, "Lion", "predateur") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 7) - 1;
            y += (rand() % 7) - 1;
        }
        else {
            cout << getNom() << " (Lion) chasse avec sa famille\n";
        }
    }
};

class Capybara : public Animal {
public:
    Capybara(const std::string& nom) : Animal(nom, "Capybara", "neutre") {}

    void deplacement(bool estJour) override {
        if (estJour)
        {
            x += (rand() % 4) - 2;
            y += (rand() % 4) - 2;
        }
        else {
            cout << getNom() << " (Capybara) se balade\n";
        }
    }
};

#endif
