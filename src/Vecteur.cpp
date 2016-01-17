#include "Vecteur.hpp"
#include <cmath>

Vecteur::Vecteur(float x, float y, float z) : _x(x), _y(y), _z(z)
{

}

Vecteur::Vecteur() : Vecteur(0,0,0)
{

}
std::ostream& operator<< (std::ostream& os, const Vecteur& v)
{
    os << v._x << " " << v._y << " " << v._z << '\n';
    return os;
}

Vecteur Vecteur::operator+(const Vecteur& b) const
{
    return {_x+b._x,_y+b._y,_z+b._z};
}

Vecteur Vecteur::operator-(const Vecteur& b) const
{
    return {_x-b._x,_y-b._y,_z-b._z};
}

float Vecteur::operator*(const Vecteur& b) const
{
    return produit_scalaire(b);
}

Vecteur Vecteur::operator*(const float& b) const
{
    return {_x*b,_y*b,_z*b};
}

Vecteur Vecteur::operator/(const Vecteur& b) const
{
    return {_x/b._x,_y/b._y,_z/b._z};
}

bool Vecteur::operator==(const Vecteur& b) const
{
    return (_x == b._x and _y == b._y and _z == b._z);
}

float Vecteur::norme2() const
{
     return _x*_x + _y*_y + _z*_z;
}

float Vecteur::norme() const
{
    return sqrt(norme2());
}

void Vecteur::normalize()
{
    float n = norme();
    if (n != 0)
    {
        _x/=n;
        _y/=n;
        _z/=n;
    }
}

float Vecteur::produit_scalaire(const Vecteur& v) const
{
    return _x*v._x + _y *v._y + _z*v._z;
}

Vecteur Vecteur::produit_vectoriel(const Vecteur& b) const
{
    return {_y * b._z - _z * b._y,
            _z * b._x - _x * b._z,
            _x * b._y - _y * b._x
            };
}
