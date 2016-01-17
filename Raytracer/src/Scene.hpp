#ifndef SCENE
#define SCENE

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>

#include "Vecteur.hpp"
#include "Surface.hpp"
#include "Rayon.hpp"
#include "Camera.hpp"
#include "Source_Lumiere.hpp"

class Scene
{
  public :
    Scene();
    Scene(sf::Color);
    Scene(float);
    Scene(sf::Color, float);

    ~Scene();

    void Ajouter_Surface(Surface*);
    void Ajouter_Lumiere(Source_Lumiere);
    void Ajouter_Camera(Camera);

    void Produire_Image_Camera(unsigned int Num_Cam);
    void Produire_Image_Camera(unsigned int Num_Cam, int profondeur_max);
    void Produire_Image_Camera(unsigned int Num_Cam, bool Debug);

    void Produire_Image_Camera(unsigned int Num_Cam, int profondeur_max, bool Debug);

    void Afficher_Image_Camera(unsigned int Num_Cam);
    void Sauvegarder_Image_Camera(unsigned int Num_Cam, const std::string Nom_Fichier);


  private :
    sf::Color Lancer_Rayon(unsigned int Num_Cam, const Rayon&, int profondeur);
    sf::Color Phong_Illumination(Surface*, const Vecteur& direction_rayon, const Vecteur& pos, const Vecteur& N);

    std::pair<Surface*, float> Intersection(const Rayon&);

    static Rayon Reflection(const Vecteur& position, const Vecteur& normale, const Vecteur& direction_rayon);

    sf::Color _couleur_ambiante;
    float _eclairage_ambiant;

    std::vector<Surface*> _liste_surface;
    std::vector<Camera> _liste_camera;
    std::vector<Source_Lumiere> _liste_lumiere;
};

#endif
