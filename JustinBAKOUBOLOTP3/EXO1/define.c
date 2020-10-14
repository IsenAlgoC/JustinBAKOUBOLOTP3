#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define carre(x) (x)*(x) // Les parenthèses permettent le comportement cohérent de la macro,
// sans les paranthèse la priorité sur des paranthèses l'emporte sur l'addition n+1*n*1 = 2n+1 ; les valeurs ne sont pas changées en mémoire.

int main() {
	int Nb = 5; 

	printf("Le carre de Nb est %d \n ", carre(Nb+1));

	system("PAUSE"); 
	return(EXIT_SUCCESS); 


}