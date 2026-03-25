#pragma once
#include <vector>
#include <memory>

#include "unite.hh"

class camp {
public:
    camp(const std::string &nom);

    unsigned int getId() const;
    std::string getNom() const;
    std::vector<std::shared_ptr<Unite>> getUnites() const;

    void ajouterUnite(std::shared_ptr<Unite> nvUnite);
    //void supprimerUnite(std::shared_ptr<Unite> uniteSupprimer);

    std::shared_ptr<Unite> operator[](unsigned int ind) const;

private:
    static unsigned int _compteurId;
    unsigned int _id;
    std::string _nom;
    std::vector<std::shared_ptr<Unite>> _unites;
};

