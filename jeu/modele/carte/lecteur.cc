#include "lecteur.hh"
#include <fstream>
#include <stdexcept>

std::vector<std::string> Lecteur::lireLignes(const std::string &nomFichier) {
    std::ifstream fich(nomFichier);

    if (!fich)
        throw std::runtime_error("Erreur : impossible d'ouvrir le fichier '" + nomFichier + "'.");

    std::vector<std::string> lignes;
    std::string ligne;

    while (std::getline(fich, ligne))
        lignes.push_back(ligne);

    return lignes;
}
