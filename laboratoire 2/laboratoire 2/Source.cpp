/*
Programme: Laboratoire 2
Acteur: Pier-Alexandre Caron
Date de création:28/01/2020
But du programme:Lire le nom, le prénom et les 5 notes des étudiants dans
etudiant.txt, calcule la note finale pour chacun et calcul
la moyenne du groupe. Affiche la liste à l’écran*/
/* Directive au pré-processeur
 =========================== */
#include <iostream>
#include <fstream> //librairie pour la manipulation de fichiers
#include <iomanip> //librairie pour l'affichage (setw, left)
#include <string>
using namespace std;

bool ouvrirFichier(ifstream& fichierNote);
bool siVide(ifstream& fichierNote);
float calculerNoteFinale(ifstream& fichierNote);
void trierAlphabetique(string nom[], string prenom[], float noteFinale[], int nbEtu);
void afficherEtudiant(string nom[], string prenom[], float noteFinale[], int nbEtu);
float calculerMoyenne(float noteFinale[], int nbEtu);
void afficherMoyenne(float moyenne);

/* Programme principal
 =================== */
void main()
{
	string nom[32], //Nom de l'étudiant
		prenom[32]; //Prénom de l'étudiant
	float noteFinale[32], //Total des 5 notes d'un étudiant
		total = 0, //Total des notes du groupe
		moyenne; //Moyenne du groupe
	int nbEtu = 0; //Nombre d'étudiants
	ifstream fichierNote("etudiant.txt"); //Notes en entrée

	if (!ouvrirFichier(fichierNote)) {
		exit(0);
	}


	getline(fichierNote, nom[nbEtu]); //lecture de l'entête

	if (!ouvrirFichier(fichierNote)) {
		exit(0);
	}

	fichierNote >> nom[nbEtu] >> prenom[nbEtu];
	while (!fichierNote.eof()) //tant que ce n'est pas la fin du fichier
	{
		noteFinale[nbEtu] = calculerNoteFinale(fichierNote);
		nbEtu++;
		fichierNote >> nom[nbEtu] >> prenom[nbEtu];
	}
	moyenne = calculerMoyenne(noteFinale,nbEtu);

	trierAlphabetique(nom, prenom, noteFinale, nbEtu);

	afficherEtudiant(nom, prenom, noteFinale, nbEtu);
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
void trierAlphabetique(string nom[], string prenom[], float noteFinale[], int nbEtu) {
	string swap;
	float temp;
	for (int i = 0; i < nbEtu - 1; i++) {
		for (int j = i + 1; j < nbEtu; j++) {
			if (nom[i] > nom[j]) {
				swap = nom[i];
				nom[i] = nom[j];
				nom[j] = swap;

				swap = prenom[i];
				prenom[i] = prenom[j];
				prenom[j] = swap;

				temp = noteFinale[i];
				noteFinale[i] = noteFinale[j];
				noteFinale[j] = temp;
				
			}
			else if (nom[i] == nom[j] && prenom[i] > prenom[j]) {


				swap = prenom[i];
				prenom[i] = prenom[j];
				prenom[j] = swap;

				temp = noteFinale[i];
				noteFinale[i] = noteFinale[j];
				noteFinale[j] = temp;
			}
			
		}
		
	}

}
/*
Affiche une liste d'étudiant
recois nom[],prenom[],notefinale[],nbEtu
retourne Void
*/
void afficherEtudiant(string nom[], string prenom[], float noteFinale[], int nbEtu){

	cout << left << setw(10) << "Nom" << setw(10) << "Prenom" << setw(10) << "Note Finale" << endl		//affichage de l'entête dans la console
		<< "==========" << "==========" << "==========" << endl << endl;
	for (int i = 0; i < nbEtu; i++) {
		cout << left << setw(10) << nom[i] << setw(10) << prenom[i]
			<< setw(10) << fixed << setprecision(0) << right << noteFinale[i] << " %";
		if (noteFinale[i] < 60) //affiche EC si échec
			cout << " EC";
		cout << endl;
	}
	
	
}
/*
Calcule une moyenne
recois float notefinale[], int nbEtu
retourne float moyenne
*/
float calculerMoyenne(float noteFinale[],int nbEtu) {
	float moyenne = 0;
	
	for (int i = 0; i < nbEtu; i++) {
		moyenne += noteFinale[i];
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