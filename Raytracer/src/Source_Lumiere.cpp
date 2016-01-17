#include "Source_Lumiere.hpp"

Source_Lumiere::Source_Lumiere(Vecteur position) : Source_Lumiere(position, 1.0, sf::Color(255,255,255))
{

}

Source_Lumiere::Source_Lumiere(Vecteur position, float f) : Source_Lumiere(position, f, sf::Color(255,255,255))
{

}

Source_Lumiere::Source_Lumiere(Vecteur position, sf::Color c) : Source_Lumiere(position, 1.0, c)
{

}

Source_Lumiere::Source_Lumiere(Vecteur p, float f, sf::Color c) : _position(p), _force_eclairage(f), _teinte(c)
{

}

Rayon Source_Lumiere::Creer_Rayon(const Vecteur& position) const
{
    Vecteur direction = _position - position;
    direction.normalize();
    return Rayon(position + direction*0.1, direction);
}

std::pair<bool, float> Source_Lumiere::Collision(Rayon& r) const
{
    float t = (r._origine - _position)*(r._direction*-1);

    if(t > 0)
        return std::make_pair(true,t);
    return std::make_pair(false,-1);
}
