#include "Scene.hpp"
#include "Couleur.hpp"

#include <iostream>
#include <cmath>

Scene::Scene() : Scene(sf::Color(0,0,0), 0.1)
{}

Scene::Scene(sf::Color c) : Scene(c, 0.1)
{}

Scene::Scene(float ambiant) : Scene(sf::Color(0,0,0), ambiant)
{}

Scene::Scene(sf::Color c, float ambiant) : _couleur_ambiante(c), _eclairage_ambiant(ambiant)
{}

Scene::~Scene()
{
    for (auto S : _liste_surface)
    {
        delete S;
    }
}

void Scene::Ajouter_Surface(Surface* s)
{
    _liste_surface.push_back(s);
}

void Scene::Ajouter_Lumiere(Source_Lumiere sl)
{
    _liste_lumiere.push_back(sl);
}

void Scene::Ajouter_Camera(Camera c)
{
    _liste_camera.push_back(c);
}

void Scene::Produire_Image_Camera(unsigned int Num_Cam)
{
    return Produire_Image_Camera(Num_Cam, 5, false);
}

void Scene::Produire_Image_Camera(unsigned int Num_Cam, int profondeur_max)
{
    return Produire_Image_Camera(Num_Cam, profondeur_max, false);
}

void Scene::Produire_Image_Camera(unsigned int Num_Cam, bool Debug)
{
    return Produire_Image_Camera(Num_Cam, 5, Debug);
}

void Scene::Produire_Image_Camera(unsigned int Num_Cam, int profondeur_max, bool Debug)
{
    sf::Clock clock;

    int h = _liste_camera[Num_Cam]._resolution.y;
    int l = _liste_camera[Num_Cam]._resolution.x;

    int nbr = (h*l);
    float b = nbr/100;
    int p = 0;
    int r = 0;

    for (int y=0; y < h; y++)
    {
        for (int x=0; x < l; x++)
        {
            if (Debug)
            {
                r += 1;
                if (r > b)
                {
                    p += 1;
                    std::cout << p << " %" << std::endl;
                    r = 0;
                }
            }

            Rayon r_camera = _liste_camera[Num_Cam].Creer_Rayon(x,y);
            sf::Color c = Lancer_Rayon(Num_Cam ,r_camera, profondeur_max);
            _liste_camera[Num_Cam]._Resultat.setPixel(x,y, c);
        }
    }

    sf::Time Temps_Creation = clock.getElapsedTime();
    std::cout << "Image crée en " << Temps_Creation.asSeconds() << " secondes." << std::endl;
}

sf::Color Scene::Lancer_Rayon(unsigned int Num_Cam, const Rayon& rayon, int profondeur)
{
    if (profondeur <= 0)
        return sf::Color(0,0,0);

    std::pair<Surface*, float> P = Intersection(rayon);

    Surface* surface = P.first;
    Vecteur position = rayon.Calculer_Position(P.second);

    if (surface == nullptr)
    {
        return _couleur_ambiante;
    }

    Vecteur N = surface->Normale(position);
    sf::Color Lumiere_Recu = Phong_Illumination(surface, rayon._direction, position, N);

    if (surface->_materiaux._force_reflexion > 0)
    {
        Rayon rayon_reflechi = Reflection(position, N, rayon._direction);
        sf::Color Lumiere_Refle = Lancer_Rayon(Num_Cam, rayon_reflechi, profondeur - 1)*(surface->_materiaux._force_reflexion);
        Lumiere_Recu = Lumiere_Recu + Lumiere_Refle * 2;
    }

    return Lumiere_Recu;
}

sf::Color Scene::Phong_Illumination(Surface* surface, const Vecteur& direction_rayon, const Vecteur& pos, const Vecteur& N)
{

    sf::Color couleur = surface->_couleur * _eclairage_ambiant;

    for (const Source_Lumiere& lumiere : _liste_lumiere)
    {
        Rayon rayon_lumiere = lumiere.Creer_Rayon(pos);
        float t_lumiere_objet_visible = lumiere.Collision(rayon_lumiere).second;

        std::pair<Surface*, float> P = Intersection(rayon_lumiere);
        Surface* s = P.first;
        float t = P.second;

        if (s == nullptr or  t_lumiere_objet_visible < t)
        {
            Vecteur L = rayon_lumiere._direction;
            Vecteur R = N*2* (N * L) - L;
            R.normalize();
            Vecteur V = direction_rayon * -1;
            float cos1 = (N * L);

            if (cos1 > 0)
            {
                /// Diffuse
                float kd = cos1*lumiere._force_eclairage;

                /// Speculaire
                float cos2 = (R * V);
                float ka = cos2 > 0 ? cos2 : 0;
                ka = pow(ka, surface->_materiaux._coeff_speculaire)*lumiere._force_eclairage;

                /// Ajout avec une synthèse des couleurs multiplicatives
                couleur += (lumiere._teinte*surface->_couleur)*kd  + lumiere._teinte*ka;
            }
        }
    }

    return couleur;
}

std::pair<Surface*, float> Scene::Intersection(const Rayon& rayon)
{
    float t_min = 500;
    Surface* surface = nullptr;
    bool visible = false;

    for (auto s : _liste_surface)
    {
        std::pair<bool, float> P = s->Collision(rayon);
        float t = P.second;

        if (P.first and (t < t_min or visible== false))
        {
            t_min = t;
            surface = s;
            visible = true;
        }
    }

    if (visible)
        return {surface, t_min};
    return {nullptr, -1.0};

}

Rayon Scene::Reflection(const Vecteur& position, const Vecteur& normale, const Vecteur& direction_rayon)
{
    Vecteur direction = normale*(normale*direction_rayon)*-2 + direction_rayon;
    direction.normalize();
    return Rayon(position + direction*0.1, direction);
}

void Scene::Afficher_Image_Camera(unsigned int Num_Cam)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;

    unsigned int Largeur = _liste_camera[Num_Cam]._resolution.x;
    unsigned int Hauteur = _liste_camera[Num_Cam]._resolution.y;

    sf::RenderWindow Window(sf::VideoMode(Largeur, Hauteur, 32), "Lanceur de rayon", sf::Style::Default, settings);
    Window.setFramerateLimit(60);

    sf::Texture T;
    T.loadFromImage(_liste_camera[Num_Cam].Image());

    sf::Sprite sprite;
    sprite.setTexture(T);

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        Window.clear(sf::Color::Black);
        Window.draw(sprite);

        Window.display();
    }
}

void Scene::Sauvegarder_Image_Camera(unsigned int Num_Cam, const std::string Nom_Fichier)
{
    _liste_camera[Num_Cam].Image().saveToFile(Nom_Fichier);
}
