#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define carre(x) (x)*(x) // Les parenth�ses permettent le comportement coh�rent de la macro,
// sans les paranth�se la priorit� sur des paranth�ses l'emporte sur l'addition n+1*n*1 = 2n+1 ; les valeurs ne sont pas chang�es en m�moire.

int main() {
	int Nb = 5; 

	printf("Le carre de Nb est %d \n ", carre(Nb+1));

	system("PAUSE"); 
	return(EXIT_SUCCESS); 


}