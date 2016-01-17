#include "Surface.hpp"

Surface::Surface(sf::Color& C, Materiaux M) : _couleur(C), _materiaux(M)
{

}

Surface::Surface(sf::Color& C) : Surface(C, Materiaux(50, 0.0))
{

}
