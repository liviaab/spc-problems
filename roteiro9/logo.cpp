/*
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: UVA11505 - Logo

O problema se resume a  encontrar a distância da origem até o ponto final após ma sequência de comandos que movimenta uma tartaruga.
A distância percorrida pela tartaruga é controlada por variaveis que representam a distancia horizontal e vertical e também o ângulo que a tartaruga vira. O valor do deslocamento na horizontal é calculado por ( distanciaDada x cos (angulo)) e o da horizontal ( distanciaDada x sen (angulo)). Quando a tartaruga faz uma curva, apenas o ângulo é modificado.

*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int ntests, ncommands;
	const double pi = acos(-1);
	cin >> ntests;
	while(ntests > 0) {
		cin >> ncommands;
		string s;
		double angle = 0, value;
		double x = 0, y = 0;
	
		while(ncommands > 0 ) {

		    cin >> s >> value;
		    if( s == "fd"){
			x += value*cos(angle*pi/180);
			y += value*sin(angle*pi/180);
		    }else if(s == "bk"){
			x -= value*cos(angle*pi/180);
			y -= value*sin(angle*pi/180);
		    }else if(s == "lt") {
			angle += value;
			if(angle >= 360)
			    angle -= 360;
		    } else {
			angle -= value;
			if(angle < 0)
			    angle += 360;
		    }
		    ncommands--;
		}
		printf("%.lf\n", sqrt(x*x+y*y));
		ntests--;
	}
	return 0;
}
