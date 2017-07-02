/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: URI1028 - Figurinhas

O problema consiste em encontrar o tamanho maximo da pilha de figurinhas, sendo que o tamanho de cada uma deve ser o maior possível. Assim, encontrando o máximo dividor comum da quantidade de figurinhas dos dois garotos, chegamos na solução desejada do problema. O algoritmo 'gdc' encontra o maior divisor comum de maneira recursiva.

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (b == 0)
		return a;
	else return gcd(b, a % b); 
}

int main(void){
	int ntestes, a, b;
	cin >> ntestes;
	while(ntestes > 0){
		cin >> a >> b;
		cout << gcd(a, b ) << endl;
		ntestes--;
	}
	return 0;
}
