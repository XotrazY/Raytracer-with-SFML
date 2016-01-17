#ifndef VECTEUR
#define VECTEUR

 #include <iostream>

class Vecteur
{
  public :
    Vecteur(float, float, float);
    Vecteur();
    ~Vecteur() = default;

    float _x;
    float _y;
    float _z;

    Vecteur operator+(const Vecteur& b)const;
    Vecteur operator-(const Vecteur& b) const;
    float operator*(const Vecteur& b) const;
    Vecteur operator*(const float&) const;
    Vecteur operator/(const Vecteur& b) const;

    bool operator==(const Vecteur& a) const;

    float norme2() const;
    float norme() const;

    void normalize();

    float produit_scalaire(const Vecteur& v) const;
    Vecteur produit_vectoriel(const Vecteur&) const;
};
std::ostream& operator<< (std::ostream& os, const Vecteur& v);
#endif
