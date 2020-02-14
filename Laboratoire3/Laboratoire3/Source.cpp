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

using namespace std;

struct date
{
	int jour;
	int mois;
	int annee;
};

void afficherDate(struct date dateJour);
date dateDuJour(void);
void viderBuffer(void);
date fetchBirthday(int anneeCourante);
int calculerAge(date dateFete, date dateJour);
void afficherNaissance(date dateFete, int age);


int main(void) {

	date dateJour;
	date dateFete;
	int age;
	dateJour = dateDuJour();

	afficherDate(dateJour);
	dateFete = fetchBirthday(dateJour.annee);

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
void afficherDate(struct date date) {
	cout << "Aujhourd'hui nous somme le " << setw(2) << setfill('0') << date.jour << "/" 
		<< setw(2) << setfill('0') << date.mois+1 << "/"
		<< date.annee << endl;

}
/*
Fonction qui calcule la date du jour
retourne uhe struct date
recois void
Fonction faite par julie professeur ma professeur d'objet
*/
date dateDuJour(void) {
	struct tm newtime; // Structure tm qui contiendra la date du jour
	time_t now = time(NULL); // now contient le nombre de secondes depuis le 01-01-1970
	localtime_s(&newtime, &now); // fait la conversion de now en structure tm
	date dateJour;
	dateJour.mois = newtime.tm_mon; // mois (0- 11)
	dateJour.jour = newtime.tm_mday; // jours (1-31)
	dateJour.annee = newtime.tm_year + 1900; // Nombre d'années depuis 1900
	return dateJour;
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
date fetchBirthday(int anneeCourante) {

	bool valid;
	date Date;
	do
	{
		valid = true;
		viderBuffer();
		cout << endl << "Entrer un votre date de naissance (jj mm aaaa) : ";
		cin >> Date.jour >> Date.mois >> Date.annee;

		//si le stream devient faux ou if(cin.fail())
		if (!cin) {
			cout << endl << "Vous devez entrer un entier.";
			valid = false;
		}
		else if (Date.jour < 1 || Date.jour > 31) {
			cout << endl << "Le jour doit être entre 1 et 31";
			valid = false;
		}
		else if (Date.mois < 1 || Date.mois > 12) {
			cout << endl << "le mois doit etre entre 1 et 12";
			valid = false;
		}
		else if (Date.annee < 1900 || Date.annee > anneeCourante + 1900) {
			cout << "L'année doit etre en 1900 et " << Date.annee + 1900 << endl;
			valid = false;
		}

	} while (!valid);

	Date.mois--;		//mois de 0 à 11 car indice

	return Date;
}
/*
Calcule l'age d'une personne selon les parametre recu et la retourne
retourne int age
recois date dateFete et date dateJour
*/
int calculerAge(date dateFete, date dateJour) {

	int age = dateJour.annee - dateFete.annee;

	if (dateJour.mois < dateFete.mois) {			
		age --;
	}
	if (dateJour.mois == dateFete.mois) {
		if (dateJour.jour < dateFete.jour) {
			age --;
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
		cout << "Vous etes nee le " << dateFete.jour << " " << mois[dateFete.mois - 1] << " " << dateFete.annee << endl;

	}
}
