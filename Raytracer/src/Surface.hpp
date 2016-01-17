#ifndef SURFACE
#define SURFACE


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Rayon.hpp"
#include "Materiaux.hpp"
#include "Vecteur.hpp"


class Surface
{
  public :
    Surface(sf::Color&, Materiaux);
    Surface(sf::Color&);
    virtual ~Surface() = default;

    virtual Vecteur Normale(const Vecteur&) = 0;
    virtual std::pair<bool, float> Collision(const  Rayon&) = 0;

    sf::Color _couleur;
    Materiaux _materiaux;
};

#endif
