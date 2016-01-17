#include "Couleur.hpp"

sf::Color operator*(const sf::Color& c, const float& f)
{
    int r = c.r*f;
    int g = c.g*f;
    int b = c.b*f;

    return {static_cast<sf::Uint8>(r<255 ? r:255), static_cast<sf::Uint8>(g<255 ? g:255), static_cast<sf::Uint8>(b<255 ? b:255)};
}
