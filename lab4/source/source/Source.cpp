/*
Programme fait par Pier-Alexandre Caron
2020-02-11
Source.cpp
Creer un code qui sera apte a convertir du texte normal en code morse 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct CodeMorse {
	string morseTraduction;
	char charactere;
};

int initCodeMorse(CodeMorse traducteur[]);
bool ouvrirFichier(ifstream& fichierNote);
bool siVide(ifstream& fichierNote);
string saisirMessage(void);
int researchChar(char charToTraduct, struct CodeMorse[37]);

void main(void){

	CodeMorse traducteur[37];
	int qtyCode;
	string message;

	qtyCode = initCodeMorse(traducteur);

	//saisis du message dans une fonction
	message = saisirMessage();

	//boucle qui fait la traduction du message
	for (int i = 0; i < message.length(); i++) {
		
		//si le char I est égale a un espace saute la ligne
		if (message[i] == ' ') {
			cout << endl;
		}
		else {
			int pos = researchChar(message[i], traducteur);
			if (pos == 37) {
				
				cout << "<" << message[i] << ">" << " " << "????"<<endl;
			}
			else {
				
				cout <<"<" <<message[i]<<">" << " " << traducteur[pos].morseTraduction <<endl;
			}

		}
	}

	system("pause");
}
/*
Initialise les tableaux traducteur
recois Traducteur[]
retourne qtyCode
*/
int initCodeMorse(CodeMorse traducteur[])
{
	ifstream fichier("codeMorse.txt"); //Notes en entrée
	int qtyCode = 0;
	//valide si le fichier est ouvrable
	if (!ouvrirFichier(fichier)) {
		exit(0);
	}

	//valide si le fichier est vide
	if (!siVide(fichier)) {
		exit(0);
	}

	//Initialise le tableau de traduction
	while (!fichier.eof()) {
		fichier >> traducteur[qtyCode].charactere;
		fichier >> traducteur[qtyCode].morseTraduction;
		qtyCode++;
	}
	return qtyCode;
}
/*
Ouvre le fichier et teste si il existe
recois fichier note
retourne void
*/
bool ouvrirFichier(ifstream& fichier) {
	if (!fichier.is_open()) //le fichier n'existe pas
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
bool siVide(ifstream& fichier) {
	if (fichier.fail()) //si le fichier est vide
	{
		cout << "Le fichier est vide." << endl;
		fichier.close();
		system("pause");
		return false;
	}
	return true;
}
/*
Saisir un message de l'utilisateur pour le mettre dans une variable string
Recois void
return string message
*/
string saisirMessage(void) {
	string message;
	cout << "Quel est le message a convertir en morse" << endl;
	getline(cin, message);

	return message;
}
/*
Recherche la position du caractere dans le tableau de char
recois un char a traduire, la structure code morse
return un int ( la position dans le tableau de char )
*/
int researchChar(char charToTraduct, CodeMorse traduction[37]) {
	int pos=0;
	for (pos = 0; pos < 37; pos++) {
		if (toupper(charToTraduct) == traduction[pos].charactere) {
			return pos;
		}
	}
	return pos;
}