#ifndef DERIVE_ANIMAL_H
#define DERIVE_ANIMAL_H

#include "Animal.h"
#include <string>

using namespace std;

class Loup : public Animal {
public:
    Loup(const string& nom) : Animal(nom, "Loup", "predateur") {}

    void deplacement() override {
        x += (rand() % 5) - 1;
        y += (rand() % 5) - 1;
    }
};
class Lapin : public Animal {
public:
    Lapin(const string& nom) : Animal(nom, "Lapin", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};
class Chevre : public Animal {
public:
    Chevre(const string& nom) : Animal(nom, "Chevre", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
    }
};
class Biche : public Animal {
public:
    Biche(const string& nom) : Animal(nom, "Biche", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};
class Ours : public Animal {
public:
    Ours(const string& nom) : Animal(nom, "Ours", "predateur") {}

    void deplacement() override {
        x += (rand() % 3) - 1;
        y += (rand() % 3) - 1;
    }
};
class Renard : public Animal {
public:
    Renard(const string& nom) : Animal(nom, "Renard", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
    }
};
class Cheval : public Animal {
public:
    Cheval(const string& nom) : Animal(nom, "Cheval", "proie") {}

    void deplacement() override {
        x += (rand() % 10) - 2;
        y += (rand() % 10) - 2;
    }
};
class Lynx : public Animal {
public:
    Lynx(const string& nom) : Animal(nom, "Lynx", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};
class Panda : public Animal {
public:
    Panda(const string& nom) : Animal(nom, "Panda", "proie") {}

    void deplacement() override {
        x += (rand() % 3) - 2;
        y += (rand() % 3) - 2;
    }
};
class Tigre : public Animal {
public:
    Tigre(const string& nom) : Animal(nom, "Tigre", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};
class Koala : public Animal {
public:
    Koala(const string& nom) : Animal(nom, "Koala", "proie") {}

    void deplacement() override {
        x += (rand() % 3) - 2;
        y += (rand() % 3) - 2;
    }
};
class Ecureuil : public Animal {
public:
    Ecureuil(const string& nom) : Animal(nom, "Ecureuil", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
    }
};
class Puma : public Animal {
public:
    Puma(const string& nom) : Animal(nom, "Puma", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
    }
};
class Coyote : public Animal {
public:
    Coyote(const string& nom) : Animal(nom, "Coyote", "predateur") {}

    void deplacement() override {
        x += (rand() % 6) - 1;
        y += (rand() % 6) - 1;
    }
};
class Rat : public Animal {
public:
    Rat(const string& nom) : Animal(nom, "Rat", "proie") {}

    void deplacement() override {
        x += (rand() % 6) - 2;
        y += (rand() % 6) - 2;
    }
};
class Bison : public Animal {
public:
    Bison(const std::string& nom) : Animal(nom, "Bison", "proie") {}

    void deplacement() override {
        x += (rand() % 3) - 2;
        y += (rand() % 3) - 2;
    }
};
class Lama : public Animal {
public:
    Lama(const string& nom) : Animal(nom, "Lama", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};
class Aigle : public Animal {
public:
    Aigle(const string& nom) : Animal(nom, "Aigle", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};
class Elephant : public Animal {
public:
    Elephant(const string& nom) : Animal(nom, "Elephant", "proie") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
    }
};
class Fennec : public Animal {
public:
    Fennec(const string& nom) : Animal(nom, "Fennec", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};
class Jaguar : public Animal {
public:
    Jaguar(const string& nom) : Animal(nom, "Jaguar", "predateur") {}

    void deplacement() override {
        x += (rand() % 8) - 1;
        y += (rand() % 8) - 1;
    }
};
class Zebre : public Animal {
public:
    Zebre(const string& nom) : Animal(nom, "Zebre", "proie") {}

    void deplacement() override {
        x += (rand() % 5) - 2;
        y += (rand() % 5) - 2;
    }
};
class Castor : public Animal {
public:
    Castor(const string& nom) : Animal(nom, "Castor", "proie") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
    }
};
class Lion : public Animal {
public:
    Lion(const string& nom) : Animal(nom, "Lion", "predateur") {}

    void deplacement() override {
        x += (rand() % 7) - 1;
        y += (rand() % 7) - 1;
    }
};
class Capybara : public Animal {
public:
    Capybara(const std::string& nom) : Animal(nom, "Capybara", "neutre") {}

    void deplacement() override {
        x += (rand() % 4) - 2;
        y += (rand() % 4) - 2;
    }
};

#endif
