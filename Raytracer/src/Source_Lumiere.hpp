#ifndef SOURCE_LUMIERE
#define SOURCE_LUMIERE

#include <SFML/Graphics.hpp>

#include "Vecteur.hpp"
#include "Rayon.hpp"


class Source_Lumiere
{
  public :
    Source_Lumiere(Vecteur position);
    Source_Lumiere(Vecteur position, float);
    Source_Lumiere(Vecteur position, sf::Color);
    Source_Lumiere(Vecteur, float, sf::Color);

    ~Source_Lumiere() = default;

    Rayon Creer_Rayon(const Vecteur& position) const;

    std::pair<bool, float> Collision(Rayon&) const;

    Vecteur _position;
    float _force_eclairage;
    sf::Color _teinte;
};

#endif
