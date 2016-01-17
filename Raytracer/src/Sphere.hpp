#ifndef SPHERE
#define SPHERE

#include "Surface.hpp"

class Sphere : public Surface
{
  public :
    Sphere(Vecteur centre, float rayon, sf::Color, Materiaux);
    Sphere(Vecteur centre, float rayon, sf::Color);

    ~Sphere() = default;

    Vecteur Normale(const Vecteur& position);
    std::pair<bool, float> Collision(const  Rayon&);

  private :
    Vecteur _centre;
    float _rayon;
};
#endif // SPHERE
