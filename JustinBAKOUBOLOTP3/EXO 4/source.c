#include <stdio.h>
#include <stdlib.h>

void AffichageIPv4(int Valeur) {

}
int main() {
	int MyAddress_w = 192;
	int MyAddress_x = 168;
	int MyAddress_y = 129;
	int MyAddress_z = 10;
	int IPv4MaskLength = 24;
	char ValeurEntree1= 0;
	int Masque;
	printf("Veuillez entrer l'adresse IPv4 sur 32 bits: "); 
	scanf("%d", &ValeurEntree1 ); 
	printf("Veuillez entrer le masque : "); 
	scanf("%d", &Masque);
	int valeurMSB = (int)pow(2.0, 31);
	int temp = 0; 

	int Compteur = 0; 
	for (Compteur = 1; Compteur <=32; Compteur++) { // On calcul la valeure entière de MyAdress_w
		if ((ValeurEntree & valeurMSB)==1) {
			if (Compteur % 8 != 0) {
				temp += (int)pow(2.0, ((8) - (Compteur % 8)));
				
			}
			else { temp += 1;  }
			ValeurEntree <<= 1;
		}
		if (Compteur == 8) {
			MyAddress_w = temp;
			temp = 0;
		}
		else if (Compteur == 16) {
			MyAddress_x = temp; 
			temp = 0;

		}
		else if (Compteur == 24) {
			MyAddress_y = temp;
			temp = 0;
		}
		else if (Compteur == 32) {
			MyAddress_z = temp; 
			temp = 0; 
		}
		
	} 
	printf("\n adresse      IPv4 =%d.%d.%d.%d", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z); 
	printf("");

}