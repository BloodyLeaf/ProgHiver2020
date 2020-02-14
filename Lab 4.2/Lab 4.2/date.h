/*
Pier-Alexandre Caron
2020-02-14
date.h
Création de l'objet date.h et de ses méthodes
*/

#pragma once

#include <time.h>
#include <cassert>
#include <iostream>
#include <iomanip>
using namespace std;


class date
{
private:
	int _jour;
	int _mois;
	int _annee;

public:
	date();
	date(int jour, int mois, int annee);
	~date();

	int getJour()const;
	int getMois()const;
	int getAnnee()const;
	date getDate()const;

	void setJour(int jour);
	void setMois(int mois);
	void setAnnee(int annee);
	void setDate(int jour, int mois, int annee);
	void today();
	void afficher(ostream& sortie);
	int calculDifferenceJour();
};
