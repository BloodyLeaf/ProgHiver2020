/*
Pier-Alexandre Caron
2020-02-14
date.cpp
Définition de toute les méthode de la classe date
*/
#include "date.h"

// constructeur vide
date::date() {
	_jour = _mois = 1;
	_annee = 1900;
}
// constructeur avec des parametre 
date::date(int jour, int mois, int annee) {
	_jour = jour;
	_mois = mois;
	_annee = annee;
}
// deconstructeur
date::~date()
{
	_jour = 0;
	_mois = 0;
	_annee = 0;
}
//getteux jour
int date::getJour()const
{
	return _jour;
}
//getteux mois
int date::getMois()const
{
	return _mois;

}
//getteux annee
int date::getAnnee()const
{
	return _annee;
}
//get la date au complet
date date::getDate()const {
	return *this;
}
//prototype de set jour
void date::setJour(int jour) {
	assert(jour >= 1 && jour <= 31); //robustesse avec <cassert>
	_jour = jour;

}
//prototype de set mois
void date::setMois(int mois) {
	assert(mois >= 1 && mois <= 12); //robustesse avec <cassert>
	_mois = mois;

}
//Prototype de set Annee
void date::setAnnee(int annee) {
	assert(annee >= 1900 && annee <= 9999); //robustesse avec <cassert>
	_annee = annee;

}
void date::setDate(int jour, int mois, int annee) {
	assert(jour >= 1 && jour <= 31); //robustesse avec <cassert>
	_jour = jour;
	assert(mois >= 1 && mois <= 12); //robustesse avec <cassert>
	_mois = mois;
	assert(annee >= 1900 && annee <= 9999); //robustesse avec <cassert>
	_annee = annee;
}
/*
Fonction qui calcule la date du jour
retourne uhe struct date
recois void
Fonction faite par julie professeur ma professeur d'objet
*/
void date::today(void) {

	struct tm newtime; // Structure tm qui contiendra la date du jour
	time_t now = time(NULL); // now contient le nombre de secondes depuis le 01-01-1970
	localtime_s(&newtime, &now); // fait la conversion de now en structure tm

	_mois = newtime.tm_mon; // mois (0- 11)
	_jour = newtime.tm_mday; // jours (1-31)
	_annee = newtime.tm_year + 1900; // Nombre d'années depuis 1900
}
void date::afficher(ostream& sortie) {
	sortie << setw(2) << setfill('0') << _jour << "/" << setw(2) << setfill('0') << _mois << "/" << _annee << endl;
}
