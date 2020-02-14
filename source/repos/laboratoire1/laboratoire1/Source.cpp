/*
Programme: calculSomme.cpp
Acteur: Julie Gagnon et Pier-AlexandRE cARON
Date de création: 21/01/2019
But du programme: lit des nombres dans un fichier en input, calcul la somme et
l’affiche en console et dans un fichier en sortie.
*/

#include <iostream>
#include <fstream> //librairie pour la manipulation de fichiers
#include <string>
#include <iomanip>
using namespace std;


bool ifOpen(ifstream &entree, const char* fileName);
bool ifEmpty(ifstream& entree, const char* fileName);
void output(ostream &sortie,double moyenne, int qqtEchec, int qqtEtudiant, string bestStudent);


void main(void) {
	int qqtEchec = 1,				// calcule la quantité d'echec 
		qqtEtudiant = 0;			//La quantité d'étudiant qui sera utilisé pour compter la moyenne
	double moyenne = 0,				// Moyesnne de tout les étudiants
		bestNote = 0,				// Utiliser temporairement pour savoir qui est le meilleur étudiant a la fin de la boucle 
		note;						// Note temporaire qui est utiliser pour des calculs et des comparaison 
	string bestStudent,				// Nom du meilleur étudiant
		nom;						// utilisé temporairement pour pottentiellement le mettre dans best student

	ifstream entree;				//variable ifstream

	entree.open("etudiant.txt");
	ofstream sortie("sortie.txt");	//variable ofstream et ouverture du fichier


	if (!ifOpen(entree, "etudiant.txt"))
		exit(0);

	if (!ifEmpty(entree, "etudiant.txt"))
		exit(0);


	while (!entree.eof()) {			//traite tous les étudiants du fichier

		entree >> nom >> note;

		if (note > bestNote) {		// trouve le meilleur étudiant 
			bestStudent = nom;
			bestNote = note;
		}

		moyenne += note;
		qqtEtudiant++;

		if (note < 60) {			// compte la qqt d'echec
			qqtEchec++;
		}

	}
	moyenne /= qqtEtudiant;

	output(sortie, moyenne, qqtEchec, qqtEtudiant, bestStudent);				// affiche dans le fichier sortie
	output(cout,moyenne,qqtEchec,qqtEtudiant,bestStudent);					// affiche dans la console

	entree.close();
	sortie.close();

	system("pause");

	
}/*
 * ce qu'elle fait : Vérifie si un fichier existe et qu'il s'ouvre
 * Parametre quelle recois : Un fichier d'entree et un filename
 * Parametre quelle retourne : void
 * date de création : 2020-01-24
 */bool ifOpen(ifstream& entree, const char* fileName) {

	if (!entree.is_open()) {
		
		cout << fileName << " doesnt exist" << endl;
		cout << "Program ended with error code 1" << endl;
		system("pause");
		return false;
	}	return true;}/*
 * ce qu'elle fait : Vérifie si un fichier est vide
 * Parametre quelle recois : Un fichier d'entree 
 * Parametre quelle retourne : void
 * date de création : 2020-01-24
 */bool ifEmpty(ifstream& entree, const char* fileName) {

	if (!entree) {

		cout << fileName << " is empty" << endl;
		cout << "Program ended with error code 1" << endl;
		system("pause");
		return false;
	}	return true;}/*
 * ce qu'elle fait : affiche des données 
 * Parametre quelle recois : Un fichier de sortie ofstream
 * Parametre quelle retourne : void
 * date de création : 2020-01-24
 */void output(ostream &sortie, double moyenne, int qqtEchec, int qqtEtudiant, string bestStudent) {
	sortie << right << setw(60) << "statistique du Groupe 4118" << endl;
	sortie << right << setw(60) << "==========================" << endl;
	sortie << setw(30) << left << "Nombre total d'etudiant : " << setw(10) << left << moyenne;
	sortie << setw(30) << left << "Meilleur(e) etudiant(e): " << setw(10) << left << bestStudent << endl;
	sortie << setw(30) << left << "Nombre total d'étudiant : " << setw(10) << left << qqtEtudiant;
	sortie << setw(30) << left << "Nombre d'échec : " << setw(10) << left << qqtEchec << endl;}