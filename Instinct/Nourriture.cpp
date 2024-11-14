#include <vector>
#include <iostream>

#include "Nourriture.h"

Nourriture::Nourriture(std::string type) : type(type), x(rand() % 100), y(rand() % 100) {}
