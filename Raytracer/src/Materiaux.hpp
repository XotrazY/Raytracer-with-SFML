#ifndef MATERIAUX
#define MATERIAUX

class Materiaux
{
  public :
    Materiaux(int coeff_specu, float force_refl);
    ~Materiaux() = default;

    int _coeff_speculaire;
    float _force_reflexion;
};

#endif
