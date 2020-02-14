/*
Programme: Laboratoire 3.2
Acteur: Pier-Alexandre Caron
Date de création:2020-02-04
But du programme:Modifier le laboratoire 2 pour y inclure des structure
*/

/* Directive au pré-processeur
 =========================== */
#include <iostream>
#include <fstream> //librairie pour la manipulation de fichiers
#include <iomanip> //librairie pour l'affichage (setw, left)
#include <string>
using namespace std;

struct etudiant
{
	string nom;
	string prenom;
	float noteFinale;
};

bool ouvrirFichier(ifstream& fichierNote);
bool siVide(ifstream& fichierNote);
float calculerNoteFinale(ifstream& fichierNote);
void trierAlphabetique(etudiant groupe[32], int nbEtu);
void afficherEtudiant(etudiant groupe[32], int nbEtu);
float calculerMoyenne(etudiant groupe[32], int nbEtu);
void afficherMoyenne(float moyenne);

/* Programme principal
 =================== */
void main()
{
	etudiant groupe[32];

	float total = 0, //Total des notes du groupe
		moyenne; //Moyenne du groupe
	int nbEtu = 0; //Nombre d'étudiants
	ifstream fichierNote("etudiant.txt"); //Notes en entrée

	if (!ouvrirFichier(fichierNote)) {
		exit(0);
	}

	getline(fichierNote, groupe[nbEtu].nom); //lecture de l'entête

	if (!ouvrirFichier(fichierNote)) {
		exit(0);
	}

	fichierNote >> groupe[nbEtu].nom >> groupe[nbEtu].prenom;
	while (!fichierNote.eof()) //tant que ce n'est pas la fin du fichier
	{
		groupe[nbEtu].noteFinale = calculerNoteFinale(fichierNote);
		nbEtu++;

		fichierNote >> groupe[nbEtu].nom >> groupe[nbEtu].prenom;
	}

	trierAlphabetique(groupe, nbEtu);
	afficherEtudiant(groupe, nbEtu);
	
	moyenne = calculerMoyenne(groupe, nbEtu);
	afficherMoyenne(moyenne);


	fichierNote.close();
	system("pause");
}
/*
Ouvre le fichier et teste si il existe
recois fichier note
retourne void
*/
bool ouvrirFichier(ifstream& fichierNote) {
	if (!fichierNote.is_open()) //le fichier n'existe pas
	{
		cout << "Le fichier n’a pas ete trouve." << endl;
		system("pause");
		return false;
	}
	return true;
}
/*
Ouvre le fichier et teste si il est vide
recois fichier note
retourne void
*/
bool siVide(ifstream& fichierNote) {
	if (fichierNote.fail()) //si le fichier est vide
	{
		cout << "Le fichier est vide." << endl;
		fichierNote.close();
		system("pause");
		return false;
	}
	return true;
}
/*
Calcule la note finale de chaque etudiant
recois fichier note
retourne float notefinale
*/
float calculerNoteFinale(ifstream& fichierNote) {
	float noteFinale = 0;
	float note;
	int ponderation[5] = { 10,10,10,35,35 };
	for (int i = 0; i < 5; i++) //lecture des 5 notes
	{
		fichierNote >> note;
		noteFinale += note * ponderation[i] / 100;
	}

	return noteFinale;
}
/*
Trie une liste en ordre alphabétique en gardant la validité des parametre
recois nom[],prenom[],notefinale[],nbEtu
retourne Void
*/
void trierAlphabetique(etudiant groupe[32], int nbEtu) {
	
	for (int i = 0; i < nbEtu - 1; i++) {
		for (int j = i + 1; j < nbEtu; j++) {
			if (groupe[i].nom > groupe[j].nom) {
				etudiant temp = groupe[i];
				groupe[i] = groupe[j];
				groupe[j] = temp;
			}
			else if (groupe[i].nom == groupe[j].nom && groupe[i].prenom > groupe[j].prenom) {

				etudiant temp = groupe[i];
				groupe[i] = groupe[j];
				groupe[j] = temp;
			}
		}
	}
}
/*
Affiche une liste d'étudiant
recois nom[],prenom[],notefinale[],nbEtu
retourne Void
*/
void afficherEtudiant(etudiant groupe[32], int nbEtu) {

	cout << left << setw(10) << "Nom" << setw(10) << "Prenom" << setw(10) << "Note Finale" << endl		//affichage de l'entête dans la console
		<< "==========" << "==========" << "==========" << endl << endl;

	for (int i = 0; i < nbEtu; i++) {
		cout << left << setw(10) << groupe[i].nom << setw(10) << groupe[i].prenom
			<< setw(10) << fixed << setprecision(0) << right << groupe[i].noteFinale << " %";

		if (groupe[i].noteFinale < 60) //affiche EC si échec
			cout << " EC";

		cout << endl;
	}
}
/*
Calcule une moyenne
recois float notefinale[], int nbEtu
retourne float moyenne
*/
float calculerMoyenne(etudiant groupe[32], int nbEtu) {
	float moyenne = 0;

	for (int i = 0; i < nbEtu; i++) {
		moyenne += groupe[i].noteFinale;
	}
	moyenne /= nbEtu;
	return moyenne;
}
/*
Recois et affiche une moyenne
recois float moyenne
retourne void
*/
void afficherMoyenne(float moyenne) {
	cout << endl << left << setw(10) << " " << setw(10) << "Moyenne" << setw(10) << right
		<< fixed << setprecision(1) << moyenne << " %" << endl << endl;
}