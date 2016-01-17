#ifndef RAYON
#define RAYON

#include "Vecteur.hpp"

class Rayon
{
  public :
    Rayon(Vecteur pos, Vecteur dir);
    ~Rayon() = default;

    Vecteur Calculer_Position(float t) const;

    Vecteur _origine;
    Vecteur _direction;
};

#endif
