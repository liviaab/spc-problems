/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: CONTAGEM - Não é Mais um Joguinho Canadense

A palavra é lida e itera-se sobre cada caractere procurando por uma letra 'b'.
Como uma transicao para o segundo estado é feita ao ler um 'b', calcula-se o custo 
sendo 2^(numero de letras restantes). O custo é calculado todas as vezes que se encontra
um 'b', pois as transicoes podem ter acontecido no primeiro b, no segundo b, no terceiro, etc.
Cada nova custo calculado é somado ao anterior e, ao final, exibe-se o custo total das 
possibilidades.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	long long int custo;
	int instancia = 1;
	char palavra[61];
	int i, tamString;

	for(i = 0; i < 61 ; i ++) palavra[i] = '\0';
	
	while(scanf("%s", palavra) != EOF){
		custo = 0;		
		tamString = strlen(palavra);

		for(i = 0 ; i < tamString ; i++){
			if( palavra[i] == 'b'){
				custo += (long long int)pow(2, ( tamString - i -1) );
			}
		}

		printf("Palavra %d\n%lld\n\n",instancia, custo );
		instancia++; 
		for(i = 0; i < 61 ; i ++) palavra[i] = '\0';
	}

	return 0;
}