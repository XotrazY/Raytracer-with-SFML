#ifndef CAMERA
#define CAMERA

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


#include "Vecteur.hpp"
#include "Rayon.hpp"

class Camera
{
    public :
        Camera(Vecteur, Vecteur, float, sf::Vector2i, Vecteur);
        Camera(Vecteur, Vecteur, float, sf::Vector2i);
        ~Camera() = default;

        Rayon Creer_Rayon(int x, int y);
        const sf::Image& Image() const;

        sf::Image _Resultat;
        sf::Vector2i _resolution;

    private :
        Vecteur _position;
        Vecteur _direction;

        float _zoom ;

        Vecteur _up;
        Vecteur _right;

        float _IR;
        float _MX;
        float _MY;
};
#endif
