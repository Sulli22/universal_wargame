#include "carte.hh"

const std::vector<Position> Carte::_DIRECTIONS = {
            {0, -1},
    {-1, 0},       {1, 0},
    {-1, 1},       {1,  1},
            {0,  1},
};

Carte::Carte(std::size_t largeur, std::size_t hauteur):
    _largeur(largeur), _hauteur(hauteur)
{
    _contenu.reserve(hauteur);

    for (std::size_t r = 0; r < hauteur; ++r) {
        std::vector<Case> ligne;
        ligne.reserve(largeur);

        for (std::size_t q = 0; q < largeur; ++q)
            ligne.emplace_back(Position(q, r));

        _contenu.push_back(std::move(ligne));
    }
}

std::size_t Carte::getLargeur() const
{
    return _largeur;
}

std::size_t Carte::getHauteur() const
{
    return _hauteur;
}

const std::vector<std::vector<Case>> &Carte::getContenu() const
{
    return _contenu;
}

Case *Carte::accesCase(const Position &pos)
{
    return &_contenu[pos.getR()][pos.getQ()];
}

bool Carte::positionValide(const Position &pos) const
{
    int q = pos.getQ();
    int r = pos.getR();

    // Vérifie que q et r sont non négatifs et dans les limites
    return (q >= 0 && q < static_cast<int>(_largeur))
        && (r >= 0 && r < static_cast<int>(_hauteur));
}

std::vector<Case> Carte::getVoisins(const Case &c) const
{
    std::vector<Case> voisins;

    auto pos = c.getPos();

    for (const auto &d : _DIRECTIONS) {
        auto voisin = pos + d;
        if (positionValide(voisin))
            voisins.push_back(_contenu[voisin.getR()][voisin.getQ()]);
    }

    return voisins;
}

void Carte::soriteFlux(std::ostream &os) const
{
    /*for (std::size_t r = 0; r < _hauteur; ++r) {
        for (std::size_t q = 0; q < _largeur; ++q) {
            _contenu[r][q].getPos().sortieFlux(os);
            os << " ";
        }
        os << std::endl;
    }*/

    for (std::size_t r = 0; r < _hauteur; ++r)
    {
        // Ligne des colonnes impaires
        for (std::size_t q = 1; q < _largeur; q += 2)
            os << "\t(" << q << "," << r << ")" << std::endl;

        // Ligne des colonnes paires
        for (std::size_t q = 0; q < _largeur; q += 2) {
            os << "(" << q << "," << r << ")";
            if (q + 2 < _largeur)
                os << "\t\t"; // espace entre les colonnes
        }
        os << std::endl;
    }
}
