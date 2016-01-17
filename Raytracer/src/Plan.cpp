#include "Plan.hpp"
#include <cmath>

Plan::Plan(float distance, Vecteur vecteur_orthogonal, sf::Color c, Materiaux m) : Surface(c, m), _distance(distance)
{
    _vecteur_orthogonal = vecteur_orthogonal*-1;
    _vecteur_orthogonal.normalize();
}

Plan::Plan(float distance, Vecteur vecteur_orthogonal, sf::Color c) : Plan(distance, vecteur_orthogonal, c , Materiaux(50, 0.0))
{

}

Vecteur Plan::Normale(const Vecteur&)
{
    return _vecteur_orthogonal;
}

std::pair<bool, float> Plan::Collision(const  Rayon& r)
{
    float t = 0;
    if (r._direction * _vecteur_orthogonal != 0)
        t = (-(r._origine * _vecteur_orthogonal) - _distance) / (r._direction * _vecteur_orthogonal);
    else
        t= -1;

    if (t>=0)
        return {true,t};
    return {false,t};
}

