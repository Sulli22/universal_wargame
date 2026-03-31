#include "carte.hh"

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

void Carte::soriteFlux(std::ostream &os) const
{
    for (std::size_t r = 0; r < _hauteur; ++r) {
        if (r % 2 == 1)
            os << "   ";

        for (std::size_t q = 0; q < _largeur; ++q) {
            _contenu[r][q].getPos().sortieFlux(os);
            os << " ";
        }
        os << std::endl;
    }
}
