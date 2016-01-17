#ifndef CYLINDRE_INFINI
#define CYLINDRE_INFINI

#include "Surface.hpp"

class Cylindre_Infini : public Surface
{
  public :
    Cylindre_Infini(Vecteur p, float r, Vecteur normale, sf::Color c, Materiaux);
    Cylindre_Infini(Vecteur p, float r, Vecteur normale, sf::Color c);
    ~Cylindre_Infini() = default;

    Vecteur Normale(const Vecteur&);
    std::pair<bool, float> Collision(const  Rayon&);

  private :
    Vecteur _position;
    float _rayon;
    Vecteur _normale;

};
#endif
