/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: Trace - Codeforces 157B

O objetivo do problema é encontrar a área pintada de vermelho de circulos concêntricos de diferentes raios, sendo que estes são pintados alternadamente de vermelho e azul. A área externa é sempre pintada de azul. Os raios dados na entrada sao amazenados em um vetor ordenado. Sempre é adicionado um raio de valor zero para que não ocorra erro no loop que calcula a área pintada. Nesse loop, itera-se se dois em dois raios a partir do ultimo, adicionando o valor do primeiro (que será vermelho) e subtraindo o do segundo (que será azul) à uma variavel. Esta é impressa no final do programa.

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int comp( long int a, long int b) {
	if (a >= b) return a;
	return b;
}

int main(void){
    
	int n; 
	cin >> n;

	long int raios[n+1];
	raios[0] = 0; 

	for(int i = 1; i <= n; i++){
		cin >> raios[i];
	}

	sort(raios, raios+n+1);

	double sum = 0;
	for(int i = n; i > 0; i -= 2){
		sum += (raios[i] * raios[i]) - (raios[i - 1] * raios[i - 1]);
	}

	sum *= M_PI;

	printf("%.10lf\n", sum);
	return 0;
}
