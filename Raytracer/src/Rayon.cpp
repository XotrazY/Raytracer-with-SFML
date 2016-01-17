#include "Rayon.hpp"

Rayon::Rayon(Vecteur pos, Vecteur dir) : _origine(pos), _direction(dir)
{

}

Vecteur Rayon::Calculer_Position(float t) const
{
    return _origine + _direction * t;
}
