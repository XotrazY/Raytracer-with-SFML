#include "Camera.hpp"

#include <cmath>

Camera::Camera(Vecteur p, Vecteur d, float z, sf::Vector2i res, Vecteur orientation)
{
    _position = p;
    _direction = d -p;
    _direction.normalize();
    _zoom = z;
    _resolution = res;

    _up = orientation;
    _up = _up - _direction * (_direction * _up);

    _IR = sqrt(_resolution.x*_resolution.x + _resolution.y*_resolution.y);
    _MX = _resolution.x/2;
    _MY = _resolution.y/2;

    if (_direction == _up)
        _right = Vecteur(1,0,0);
    else
        _right = _direction.produit_vectoriel(_up);

    _Resultat.create(res.x, res.y);
}

Camera::Camera(Vecteur p, Vecteur d, float z, sf::Vector2i res) : Camera(p, d, z, res, Vecteur(0,0,1))
{

}

Rayon Camera::Creer_Rayon(int x, int y)
{
    float X = (x- _MX)/_IR;
    float Y = (abs(_resolution.y-y)-_MY)/_IR;

    Vecteur direction = _direction*_zoom  + _right*X + _up*Y;
    direction.normalize();

    return Rayon(_position + direction * 0.1, direction);
}

const sf::Image& Camera::Image() const
{
    return _Resultat;
}
