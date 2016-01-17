#include "Test.hpp"

#include "../Scene.hpp"

#include "../Sphere.hpp"
#include "../Cylindre_Infini.hpp"
#include "../Plan.hpp"

namespace Test
{
    void Kawai(const std::string Nom_Image)
    {
        Scene S;

        S.Ajouter_Camera(Camera(Vecteur(5, 0,0), Vecteur(5,10,0), 0.75, sf::Vector2i(1600, 900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(10,0,0),  sf::Color(255,0,0)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(-10,0,0), sf::Color(0,255,0)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(0,0,10),   sf::Color(0,0,255)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(0,0,-10),   sf::Color(100,0,100)));


        S.Ajouter_Surface(new Sphere(Vecteur(10,20,0), 1, sf::Color(255,255,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(4,20,-5), 1, sf::Color(255,255,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(0,20,5), 1, sf::Color(255,255,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(2,20,8), 1, sf::Color(255,255,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(6,20,6), 1, sf::Color(255,255,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(-5,20,2), 1, sf::Color(255,255,255)));


        for (int x= -21; x<31; x++)
        {
            S.Ajouter_Surface(new Cylindre_Infini(Vecteur(x ,45,0), 1, Vecteur(0,0,1), sf::Color(60,60,60)));
        }


        S.Produire_Image_Camera(0);
        S.Afficher_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

    void Test1(const std::string Nom_Image)
    {
        Scene S;

        S.Ajouter_Camera(Camera(Vecteur(0, 0,1), Vecteur(0,15,2), 1, sf::Vector2i(1600,900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(50,-50,100)));

        S.Ajouter_Surface(new Plan(1, Vecteur(0,0,-1), sf::Color(13, 71, 171)));

        S.Ajouter_Surface(new Sphere(Vecteur(3,25,6), 1, sf::Color(171,113,14)));
        S.Ajouter_Surface(new Sphere(Vecteur(-3,16,0), 1, sf::Color(85, 139, 87)));
        S.Ajouter_Surface(new Sphere(Vecteur(3,15,0), 1, sf::Color(140,86,138)));

        S.Ajouter_Surface(new Cylindre_Infini(Vecteur(0,30,0), 2, Vecteur(0,0,1), sf::Color(14,171,35)));

        S.Produire_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

    void Test2(const std::string Nom_Image)
    {
        Scene S;

        S.Ajouter_Camera(Camera(Vecteur(0, 0.5,0), Vecteur(0,15,0), 1, sf::Vector2i(1600,900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(-10,-5,0), 1.0, sf::Color(255,0,0)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(10,-5,0), 1.0, sf::Color(0,255,0)));

        S.Ajouter_Surface(new Plan(1, Vecteur(0,0,-1), sf::Color(100, 70, 0)));

        S.Ajouter_Surface(new Sphere(Vecteur(-3,10,0), 1, sf::Color(255,0,255)));
        S.Ajouter_Surface(new Sphere(Vecteur(0,10,0), 1, sf::Color(255, 255, 255)));
        S.Ajouter_Surface(new Sphere(Vecteur(+3,10,0), 1, sf::Color(0, 255, 255)));

        S.Produire_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

    void Test3(const std::string Nom_Image)
    {
        Scene S;

        Materiaux Specu_Faible(100, 0.0);
        Materiaux Specu_Moyenne(50, 0.0);
        Materiaux Specu_Forte(10, 0.0);

        S.Ajouter_Camera(Camera(Vecteur(-2.9,0,0), Vecteur(0,1,1), 0.25, sf::Vector2i(1600,900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(2,0,0), 0.5, sf::Color(255,0,0)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(0,0,2), 1.0, sf::Color(0,0,255)));

        S.Ajouter_Surface(new Plan(3, Vecteur(0,0, 1), sf::Color(30, 70, 40), Specu_Faible));
        S.Ajouter_Surface(new Plan(3, Vecteur(1,0, 0), sf::Color(100, 0, 70), Specu_Faible));
        S.Ajouter_Surface(new Plan(3, Vecteur(0,1, 0), sf::Color(70, 100, 0), Specu_Faible));

        S.Ajouter_Surface(new Sphere(Vecteur(0, -2,  2), 0.5, sf::Color(255,255,255), Specu_Forte));
        S.Ajouter_Surface(new Sphere(Vecteur(0,   2,  2), 0.5, sf::Color(255, 255, 255), Specu_Forte));

        S.Produire_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

    void Test4(const std::string Nom_Image)
    {
        Materiaux Miroir_Bon(500, 1.0);

        Scene S;

        S.Ajouter_Camera(Camera(Vecteur(5, -15,0), Vecteur(5,10,0), 1.3, sf::Vector2i(1600,900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(10,10,0)));
        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(10,0,0)));

        S.Ajouter_Surface(new Sphere(Vecteur(4,8,-3), 1, sf::Color(0,0,0), Miroir_Bon));
        S.Ajouter_Surface(new Sphere(Vecteur(6,8,1), 1, sf::Color(0,0,0), Miroir_Bon));

        S.Ajouter_Surface(new Cylindre_Infini(Vecteur(10,14,0), 2, Vecteur(0,0,1), sf::Color(20,20,20), Miroir_Bon));
        S.Ajouter_Surface(new Cylindre_Infini(Vecteur(2,14,0), 2, Vecteur(0,0,1), sf::Color(20,20,20), Miroir_Bon));

        S.Ajouter_Surface(new Plan(4,Vecteur(0,0,-1), sf::Color(63,2,127)));

        S.Produire_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

    void Test5(const std::string Nom_Image)
    {
        Materiaux Miroir_Bon(500, 1.0);

        Scene S;

        S.Ajouter_Camera(Camera(Vecteur(5, -15,0), Vecteur(0,2,1), 0.8, sf::Vector2i(1600,900)));

        S.Ajouter_Lumiere(Source_Lumiere(Vecteur(10,-10,5), 1.0, sf::Color(30,180, 30)));

        S.Ajouter_Surface(new Sphere(Vecteur(2,1,2), 1, sf::Color(114,50,0)));
        S.Ajouter_Surface(new Sphere(Vecteur(2,5,0), 1, sf::Color(0,144,50)));

        S.Ajouter_Surface(new Cylindre_Infini(Vecteur(6,0,0), 1, Vecteur(0,0,1), sf::Color(124,80,24)));


        S.Ajouter_Surface(new Plan(1,Vecteur(-1,0,0), sf::Color(10,10,10), Miroir_Bon));
        S.Ajouter_Surface(new Plan(1,Vecteur(0,0,-1), sf::Color(60,50,40)));

        S.Produire_Image_Camera(0);
        S.Sauvegarder_Image_Camera(0, Nom_Image);
    }

}
