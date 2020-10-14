#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define NBMAXNOTES 30 

void Echanger(float *a, float *b) { // Cette fonction sera utile pour le tri à bulle dans la dernière partie de l'exercice.
	float temp = 0; 
	temp = *a; 
	*a = *b;
	*b = temp;
}

int main() {
	
	float note[NBMAXNOTES];  
	float Somme = 0;
	float Min; 
	float Max; 
	int Compteur = 0;
	float NoteEntree = 0;
	int NbAbsences = 0 ; 
	int NbDeNotesValides = 0; 

	for (int Compteur = 0; Compteur < NBMAXNOTES; Compteur++) { note[Compteur] = -2; }

	for (int Compteur = 0;  Compteur < NBMAXNOTES; Compteur ++) {
		printf("Entrez la note no [%d] : ", Compteur + 1);
		scanf_s("%f", &NoteEntree);
		if (NoteEntree < 0 || NoteEntree > 20) { // Verifie que la note est comprises en 0 et 20
			char Reponse;
			_cputs("L'eleve est-il (A)bsent Ou voulez-vous arrêter la saisie (O)ui (N)on  ? \n");
			Reponse = _getch();
			if (Reponse == 'A') {
				NbAbsences += 1; // Dans le cas où l'utilisateur réponds absent; on incrémente le compteur des absences 
				note[Compteur] = -1;
			}
			else if (Reponse == 'O') {
				Compteur = 31;
			}
			else if (Reponse == 'N'){
				Compteur -= 1;
			}
			else {
				Compteur -= 1;
			}
		}
		else {
			NbDeNotesValides+= 1;
			Somme += NoteEntree ;
			note[Compteur] = NoteEntree; 
			}
		printf("%.2f", note[Compteur]); 
		
	}
	Compteur = 0;
	float temp;
	Min = note[0];
	Max = note[0];
	for (Compteur = 1; Compteur < NBMAXNOTES; Compteur++) {
		if (note[Compteur]>=0) {
			temp = note[Compteur];
			if (temp > Max) {
				Max = temp;
			}
			else if (temp < Min) {
				Min = temp;
			}
		}
	}
	float moyenne = 0;
	moyenne = (Somme / NbDeNotesValides);
	printf("\nLe nombre de notes valides est : %d", NbDeNotesValides); 
	printf("\nLe nombre d'abscences est : %d ", NbAbsences); 
	printf("\nLa moyenne est de : %.2f",moyenne ); 
	printf("\nLe plus petit nombre est : %.2f", Min); 
	printf("\nLe plus grand nombre est : %.2f", Max);
	// Calcul de l'écart type; 
	float EcartMoyen= 0;
	for (Compteur = 0; Compteur < NBMAXNOTES; Compteur++) {
		if (note[Compteur] > 0) {
			EcartMoyen = (float)pow((note[Compteur]-moyenne), 2);
		}
	}
	float EcartType = (float)sqrt(EcartMoyen / NbDeNotesValides); 
	printf("\n L'Ecart Type est de : %.2f", EcartType); 
	// Affichage du Tableau des Notes; 
	printf("\nNo de Note  Valeur de la Note ");
	int CompteurAffichage = 0;
	for (Compteur = 0; Compteur < NBMAXNOTES; Compteur++) {
		if (note[Compteur] > 0) {
			CompteurAffichage += 1;
			printf("\n %d", CompteurAffichage);
			printf("\t\t  %.2f \n", note[Compteur]);
		}
	}
	
	 
	int TbDesIndex[30]; // On créer le Tableau des index.
	
	for (int Compteur = 0; Compteur < NBMAXNOTES; Compteur++) { TbDesIndex[Compteur] = Compteur; }
	// Tri des notes et affichage des notes par ordre décroissant avec l'indice correspondant
	for (int CompteurTri = 0; CompteurTri < NBMAXNOTES; CompteurTri++) {
		for (Compteur = 0; Compteur < NBMAXNOTES - CompteurTri; Compteur++) {
			if (note[Compteur] < note[Compteur + 1]) {
				Echanger(&note[Compteur], &note[Compteur + 1]);
				Echanger(&(float)TbDesIndex[Compteur], &(float)TbDesIndex[Compteur + 1]);
			}
		}
	}
	// Tri des notes et affichage des notes par ordre décroissant avec l'indice correspondant
	printf("\nRang        No de Note      Valeur de la Note ");
	CompteurAffichage = 0;
	for (Compteur = 0; Compteur < NBMAXNOTES; Compteur++) {
		if (note[Compteur] > 0) {
			CompteurAffichage += 1;
			printf("\n %d", CompteurAffichage);
			printf("\t\t %d", TbDesIndex[Compteur] + 1);
			printf("\t\t  %.2f \n", note[Compteur]);
		}
	}

	system("pause"); 
	return (EXIT_SUCCESS);
}