#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int req1(int **matriz, int m, int n){
	bool todos;
	int i , j;

	for (i = 0 ; i < m ; i++){
		todos = true;
		for(j = 0 ; j < n; j++){
			if( matriz[i][j] == 0){
				todos = false;
				break;
			}		
		}
		if(todos) break;
	}
	
	if(todos){
		return 0;	
	}
	return 1;
}


int req2(int **matriz, int m, int n){
	bool ninguem;
	int i , j;

	for(j =0 ; j < n; j++){
		ninguem = true;
		for(i =0 ; i < m ; i++){
			if(matriz[i][j] == 1){
				ninguem = false;
				break;			
			}
		}
		if(ninguem) break;
	}
	
	if(ninguem)
		return 0;

	return 1;
}


int req3(int **matriz, int m, int n){
	bool resportodos;
	int i, j;

	for(j =0 ; j < n; j++){
		resportodos = true;
		for(i =0 ; i < m ; i++){
			if(matriz[i][j] == 0){
				resportodos = false;
				break;			
			}
		}
		if(resportodos) break;
	}
	
	if(resportodos)
		return 0;

	return 1;
}

int req4(int **matriz, int m, int n){
	bool zeroproblemas;
	int i , j;

	for (i = 0 ; i < m ; i++){
		zeroproblemas = true;
		for(j = 0 ; j < n; j++){
			if( matriz[i][j] == 1){
				zeroproblemas = false;
				break;
			}		
		}
		if(zeroproblemas) break;
	}
	
	if(zeroproblemas)
		return 0;

	return 1;
}

int main(void){
	int numpart, numprob;
	int i, j;
	while(1){
		cin >> numpart >> numprob;
		if( numpart == 0 && numprob == 0) break;
	
		int **matriz = (int **)malloc(numpart* sizeof(int *));
		for(j = 0 ; j < numpart ; j++){
			matriz[j] = (int *)malloc(numprob* sizeof(int));
		}
		

		for(i = 0; i < numpart; i++){
			for(j = 0 ; j < numprob ; j++){
				cin >> matriz[i][j] ;
			}
		}
		
		int r1 = req1(matriz, numpart, numprob);
		int r2 = req2(matriz, numpart, numprob);
		int r3 = req3(matriz, numpart, numprob);
		int r4 = req4(matriz, numpart, numprob);
		cout << r1 + r2 + r3 + r4 << endl;

	}
	return 0;
}

