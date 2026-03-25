#include "camp.hh"
#include <iostream>

unsigned int camp::_compteurId(0);

camp::camp(const std::string &nom):_nom(nom),_id(_compteurId++)
{}

unsigned int camp::getId() const
{
    return _id;
}

std::string camp::getNom() const
{
    return _nom;
}

std::vector<std::shared_ptr<Unite>> camp::getUnites() const
{
    return _unites;
}

void camp::ajouterUnite(std::shared_ptr<Unite> nvUnite)
{
    _unites.push_back(std::move(nvUnite));
}

/*
void camp::supprimerUnite(std::shared_ptr<Unite> uniteRetirer)
{

}
*/
std::shared_ptr<Unite> camp::operator[](unsigned int ind) const
{
    try {
        return _unites.at(ind);
    }
    catch(std::out_of_range error) {
        std::cerr << "Erreur : Indice invalide" << std::endl;
    }
    return nullptr;
}
