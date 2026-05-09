#pragma once

#include <set>
#include <vector>
#include <ostream>
#include <map>
#include "case.hh"

class Carte {
public:
    Carte(unsigned int idGuerre);

    std::size_t getLargeur() const;
    std::size_t getHauteur() const;
    const std::vector<std::vector<std::unique_ptr<Case>>> &getContenu() const;

    bool positionValide(const Position &pos) const;
    Case *accesCase(const Position &pos) const;
    std::vector<Case *> getVoisines(const Case &c) const;
    std::vector<Case *> getVoisinesConstructibles(const Case &c) const;
    std::map<Case *, uint16_t> getCasesAtteignables(Case *depart, Unite *uniteEnDeplacement) const;
    std::vector<Case *> getCasesAttaquables(Case *depart, Unite *uniteAttaquante) const;
    std::vector<Case *> getChemin(Case *depart, Case *arrivee, Unite *uniteEnDeplacement) const;
    bool caseDansZocEnnemie(Case *caseCible, const Unite &uniteEnDeplacement,
                            const std::map<Case *, std::set<Faction>> &zoc) const;
    std::map<Case *, std::set<Faction> > getZOC() const;
    void effectuerActionsCases() const;
    uint16_t nbUnites(Faction faction) const;
    std::vector<Case *> getCasesZOC(Faction faction) const;
    std::vector<Case *> getCasesFactionAvecUnites(Faction faction) const;

// sortie flux
    void soriteFlux(std::ostream &os) const;
    void afficherDetails(std::ostream &os) const;

private:
    static uint16_t distance(const Case &a, const Case &b);
    static std::vector<Case *> reconstruitChemin(const std::map<Case *, Case*> &vientDe,
                                                 Case *depart, Case *arrivee);

// attributs
    std::size_t _largeur;
    std::size_t _hauteur;
    std::vector<std::vector<std::unique_ptr<Case>>> _contenu;

    static const std::vector<Position> _DIRECTIONS_PAIRES;
    static const std::vector<Position> _DIRECTIONS_IMPAIRES;
};
