#include "Sphere.hpp"

#include <cmath>


Sphere::Sphere(Vecteur c, float r, sf::Color C, Materiaux M) : Surface(C, M), _centre(c), _rayon(r)
{

}

Sphere::Sphere(Vecteur c, float r, sf::Color C) : Sphere(c, r, C, Materiaux(50, 0.0))
{

}


Vecteur Sphere::Normale(const Vecteur& position)
{
    Vecteur N = position - _centre;
    N.normalize();
    return N;
}

std::pair<bool, float> Sphere::Collision(const  Rayon& r)
{
    float a = r._direction.norme2();
    float b = 2*(r._origine * r._direction - _centre * r._direction );
    float c = r._origine.norme2() + _centre.norme2() - (r._origine * _centre)*2 - _rayon*_rayon;

    float delta = b*b - 4*a*c;


    float t = -1;
    float t1 = 0;
    float t2 = 0;


    if (delta > 0.00001 and a != 0)
    {
        t1 = (-b - sqrt(delta))/(2*a);
        t2 = (-b + sqrt(delta))/(2*a);
        t = t1 > t2 ? t2 : t1;
    }
    else if (delta > 0)
        t = -b/(2*a);

    if (t >= 0)
        return {true, t};
    return {false, t};
}
