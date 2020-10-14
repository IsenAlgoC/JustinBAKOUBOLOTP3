# include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() { 
	// Dans cette première partie on affiche les 32 bits d'un entier non signé. 

	unsigned int Nombre = 2868838400; 
	unsigned int temp = 0; // variable temporaire
	unsigned int i = 0; 
	unsigned int Nombre_D_Octets = sizeof(Nombre); 
	printf("Le nombre d'octets est: %d\n", Nombre_D_Octets);
	unsigned int Nombre_De_Bits = 8 * Nombre_D_Octets; 
	printf("Le nombre de bits utilises est: %d \n", Nombre_De_Bits);

	temp = Nombre; 

	for  (i = 0; i < Nombre_De_Bits ; i++) {// Dans cette partie on compare le bit de poids le plus faible avec 1.
		if ((temp & 1) == 1) {
			printf("bit n %d : ON \n", i); // On affiche ON si le bit de poids faible est 1 
		}
		else {
			printf("bit n %d : OFF \n", i); // Sinon on affiche OFF
		}
		temp >>= 1;
	}
	
	// On vérfie bien à l'lécran que les 32 bits sont bien affichés à l'écran.  On fait une verification, le nombre donné est 1111111101010101 ce qui correspond bien à  
	 

}