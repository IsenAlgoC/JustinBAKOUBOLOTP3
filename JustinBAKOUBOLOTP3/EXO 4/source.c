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
	unsigned long Masque;
	printf("\n adresse personnelle IPv4 =%d.%d.%d.%d/%d", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z,IPv4MaskLength);

	Masque = (((0xFF << 24)+(0xFF << 16)+(0xFF << 8)+0xFF)<< (32 - IPv4MaskLength));
	
	unsigned  int Adresse_reseau_z = (MyAddress_z)&Masque;
	unsigned  int Adresse_reseau_y = (MyAddress_y)&(Masque >>8);
	unsigned  int Adresse_reseau_x = (MyAddress_x)&(Masque>>16);
	unsigned  int Adresse_reseau_w = (MyAddress_w)&(Masque>>24);

	
	printf("\n adresse reseau IPv4 =%d.%d.%d.%d/%d", Adresse_reseau_w, Adresse_reseau_x, Adresse_reseau_y, Adresse_reseau_z, IPv4MaskLength);
	Masque = (((0xFF << 24) + (0xFF << 16) + (0xFF << 8) + 0xFF) << (32 - IPv4MaskLength));
	Masque =~(Masque);
	unsigned  int Adresse_Broadcast_z = (MyAddress_z)|Masque;
	Masque = Masque >> 8;
	unsigned  int Adresse_Broadcast_y = (MyAddress_y) |(Masque);
	Masque = Masque >> 8;
	unsigned  int Adresse_Broadcast_x= (MyAddress_x) |(Masque);
	Masque = Masque >> 8;
	unsigned  int Adresse_Broadcast_w = (MyAddress_w) | (Masque);

	printf("\n adresse broadcast IPv4 =%d.%d.%d.%d", Adresse_Broadcast_w, Adresse_Broadcast_x, Adresse_Broadcast_y, Adresse_Broadcast_z);
	
	// On déduie ainsi l'algorythme donnant l'adresse Réseau et adresse broadcast pour toute adresse réseau personnelle.
	printf("\n");
	system("PAUSE"); 
	return (EXIT_SUCCESS);

}

