/*
Pier-Alexandre Caron
2020-02-11
source.cpp
Modifier le laboratoire 3.1 pour y inclure un objet et non une structure
*/
				/*
				Programme fait par : Pier-Alexandre Caron
				fait le : 2020-01-31
				Nom du projet : Laboratoire 3
				Nom du fichier : Source.cpp
				Manipuler des structure de base pour calculer l'age d'une personne selon sa date de fete
				*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cassert>
#include "date.h"
using namespace std;


void afficherDate(date dateJour);

void viderBuffer(void);
date fetchBirthday(date dateJour);
int calculerAge(date dateFete, date dateJour);
void afficherNaissance(date dateFete, int age);


int main(void) {

	date dateJour;
	date dateFete;

	date dateNaissance(28, 01, 2000);
	int age;
	dateJour.today();

	afficherDate(dateJour);
	
	dateFete = fetchBirthday(dateJour);
	
	age = calculerAge(dateFete, dateJour);
	
	afficherNaissance(dateFete, age);
	system("pause");

	return 0;
}
/*
Affiche la date du jour avec un certain formatage
retourne void
recois une struct date
*/
void afficherDate(date date) {
	cout << "Aujhourd'hui nous somme le ";
	date.afficher(cout);

}

//Vide le buffer
//Fonction Faite par Julier ma professeur d'objet
void viderBuffer()
{
	cin.clear(); //on reset le flux pour que la suite parte d’un flux valide
	cin.seekg(0, ios::end);//se place à la fin, si ça marche, non vide
	if (!cin.fail()) //Le flux est valide, donc le buffer est non vide
		cin.ignore(numeric_limits<streamsize>::max());
	else //Le flux est invalide, donc le buffer est vide
		cin.clear();
	// Le flux est dans un état invalide donc on le remet en état valide
}
/*
Prends des donné propre a l'utilisateur sur sa date et les stock dans une structure date
Test de validation si les input sont bon
retourne une structure date
recois l'année actuelle
*/
date  fetchBirthday(date dateJour) {

	bool valid;
	date Date;
	int jour, mois, annee;

	do
	{
		valid = true;
		viderBuffer();
		cout << endl << "Entrer un votre date de naissance (jj mm aaaa) : ";
		cin >> jour >> mois >> annee;

		//si le stream devient faux ou if(cin.fail())
		if (!cin) {
			cout << endl << "Vous devez entrer un entier.";
			valid = false;
		}
		else if (jour < 1 || jour > 31) {
			cout << endl << "Le jour doit être entre 1 et 31";
			valid = false;
		}
		else if (mois < 1 || mois > 12) {
			cout << endl << "le mois doit etre entre 1 et 12";
			valid = false;
		}
		else if (annee < 1900 || annee > dateJour.getAnnee()) {
			cout << "L'année doit etre en 1900 et " << annee + 1900 << endl;
			valid = false;
		}

	} while (!valid);

	/*Date.setJour(jour);
	Date.setMois(mois--);
	Date.setAnnee(annee);*/
	Date.setDate(jour, mois--, annee);
	
	//Date.mois--;		//mois de 0 à 11 car indice

	return Date;
}
/*
Calcule l'age d'une personne selon les parametre recu et la retourne
retourne int age
recois date dateFete et date dateJour
*/
int calculerAge(date dateFete, date dateJour) {

	int age = dateJour.getAnnee() - dateFete.getAnnee();

	if (dateJour.getMois() < dateFete.getMois()) {
		age--;
	}
	if (dateJour.getMois() == dateFete.getMois()) {
		if (dateJour.getJour() < dateFete.getJour()) {
			age--;
		}
	}

	return age;
}
/*
Affiche sois une non naissance sois une date de naissance et un age
retourne void
recois date dateFete et int age
*/
void afficherNaissance(date dateFete, int age) {
	string mois[12] = { "Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Décembre" };

	if (age <= 0) {
		cout << "Pas encore nee" << endl;
	}
	else {
		cout << "Vous avez " << age << " ans" << endl;
		cout << "Vous etes nee le ";
		dateFete.afficher(cout);
	}
}