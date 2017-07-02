/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: URI 1022 - TDA Racional

Nesse problema são dadas operacoes racionais e pede-se que sejam impressas o resultado não simplificado e, em seguida, o resultado simplificado. No problema foi definido como seria feito o calculo da operacao sem simplificação. Após obter este resultado, calcula-se o máximo divisor comum (MDC) entre o numerador e o denominador para imprimir o numero racional simplificado.

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

	int ncasos, a, b, c, d;
	int r1, r2, fator;
	char barra, op;
	cin >> ncasos;
	while(ncasos > 0){
		cin >> a >> barra >> b >> op >> c >> barra >> d;

		
		if(op == '+'){
			r1 = (a*d + c*b);
			r2 = b * d;
		}else if( op == '-'){
			r1 = (a*d - c*b);
			r2 = b * d;
		}else if( op == '*'){
			r1 = a * c;
			r2 = b * d;
		}else{
			r1 = a * d;
			r2 = b * c;
		}

		fator = gcd(r1, r2);
		if(fator < 0) fator = -1*fator;
		cout << r1 << "/" << r2 << " = " << r1/fator << "/" << r2/fator << endl;
		ncasos--;
	}

	return 0;
}
