#ifndef PLAN
#define PLAN

#include "Surface.hpp"

class Plan : public Surface
{
  public :
    Plan(float distance, Vecteur vecteur_orthogonal, sf::Color, Materiaux);
    Plan(float distance, Vecteur vecteur_orthogonal, sf::Color);
    ~Plan() = default;

    Vecteur Normale(const Vecteur&);
    std::pair<bool, float> Collision(const  Rayon&);

  private :
    float _distance;
    Vecteur _vecteur_orthogonal;

};
#endif
