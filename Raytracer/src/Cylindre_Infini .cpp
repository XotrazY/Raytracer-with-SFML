#include "Cylindre_Infini.hpp"


Cylindre_Infini::Cylindre_Infini(Vecteur p, float r, Vecteur n, sf::Color c, Materiaux m) : Surface(c, m), _position(p), _rayon(r), _normale(n)
{
    _normale.normalize();
}

Cylindre_Infini::Cylindre_Infini(Vecteur p, float r, Vecteur normale, sf::Color c) : Cylindre_Infini(p, r, normale, c, Materiaux(50,0.0))
{

}

Vecteur Cylindre_Infini::Normale(const Vecteur& pos)
{
    Vecteur V = pos - _position;
    Vecteur N = V - _normale*(V*_normale);
    N.normalize();
    return N;
}

std::pair<bool, float> Cylindre_Infini::Collision(const  Rayon& r)
{
    float oa = r._origine*_normale;

    float A = r._direction.norme2() -  ((r._direction*_normale)*(r._direction*_normale));
    float B = 2* ((r._origine*r._direction) - (r._direction* _position) - (r._direction*_normale)*(oa));
    float C = r._origine.norme2() + _position.norme2() - 2*(r._origine* _position) - (oa*oa)- _rayon*_rayon;

    float Delta = (B*B + A *C*-4);

    float t = -1;

    if (Delta > 0.00001 and A != 0)
    {
        float t1 = (-B - sqrt(Delta))/(2*A);
        float t2 = (-B + sqrt(Delta))/(2*A);
        t = t1 > t2 ? t2 : t1;
    }
    else if (Delta > 0 and A != 0)
        t = -B/(2*A);

    if (t >= 0)
        return {true, t};
    else
        return {false,t};
}

