
#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int main(void){
	int total, nteste = 0, i;
	while(1){
		cin >> total;
		if(total == 0) break;

		int notas[4] = {0}; // notas[0] peso 1, notas[3], peso 50

		while(total > 0){
			if( total >= 50){
				notas[0]++;
				total -= 50;
			}else if( total >= 10){
				notas[1]++;
				total -= 10;
			}else if( total >= 5){
				notas[2]++;
				total -=5;
			}else{ 
				notas[3] = total;
				total -= total;
			}

		}

		cout << "Teste "<< ++nteste << endl;
		for(i = 0 ; i < 4; i++){
			cout << notas[i] << " " ;
		}
		cout << endl<<endl;

	}

	return 0;
}