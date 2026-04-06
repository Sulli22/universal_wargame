#include "carte.hh"
#include "lecteur.hh"
#include "createurcases.hh"
#include <sstream>

#include <iostream>

const std::vector<Position> Carte::_DIRECTIONS = {
            {0, -1},
    {-1, 0},       {1, 0},
    {-1, 1},       {1,  1},
            {0,  1},
};

Carte::Carte(std::string nomFichier)
{
    auto lignes = Lecteur::lireLignes(nomFichier);

    std::size_t q = 0;
    std::size_t r = 0;

    for (const auto& ligne : lignes) {
        r++;
        std::stringstream ss(ligne);
        std::string token;
        std::vector<std::unique_ptr<Case>> cases;

        q = 0;
        while (ss >> token) {
            if (token.size() < 2) continue; // sécurité

            char type = token[0];
            int nombre = std::stoi(token.substr(1));

            for (int i = 0; i < nombre; ++i) {
                cases.push_back(CreateurCases::creer(type, Position(q, r)));
                q++;
            }

        }
        _contenu.push_back(std::move(cases));
    }

    std::cout << q << " " << r <<std::endl;

    _largeur = q;
    _hauteur = r;
}

std::size_t Carte::getLargeur() const
{
    return _largeur;
}

std::size_t Carte::getHauteur() const
{
    return _hauteur;
}

const std::vector<std::vector<std::unique_ptr<Case>>> &Carte::getContenu() const
{
    return _contenu;
}

Case* Carte::accesCase(const Position &pos)
{
    return _contenu[pos.getR()][pos.getQ()].get();
}

bool Carte::positionValide(const Position &pos) const
{
    int q = pos.getQ();
    int r = pos.getR();

    // Vérifie que q et r sont non négatifs et dans les limites
    return (q >= 0 && q < static_cast<int>(_largeur))
        && (r >= 0 && r < static_cast<int>(_hauteur));
}

std::vector<Case *> Carte::getVoisins(const Case &c) const
{
    std::vector<Case *> voisins;

    auto pos = c.getPos();

    for (const auto &d : _DIRECTIONS) {
        auto voisin = pos + d;
        if (positionValide(voisin))
            voisins.push_back(_contenu[voisin.getR()][voisin.getQ()].get());
    }

    return voisins;
}

void Carte::soriteFlux(std::ostream &os) const
{
    for (std::size_t r = 0; r < _hauteur; ++r)
    {
        // Ligne des colonnes impaires
        for (std::size_t q = 1; q < _largeur; q += 2) {
            os << "\t(" << q << "," << r << ")";
            if (q + 2 < _largeur)
                os << "\t"; // espace entre les colonnes
        }
        os << std::endl;

        // Ligne des colonnes paires
        for (std::size_t q = 0; q < _largeur; q += 2) {
            os << "(" << q << "," << r << ")";
            if (q + 2 < _largeur)
                os << "\t\t"; // espace entre les colonnes
        }
        os << std::endl;
    }
}
