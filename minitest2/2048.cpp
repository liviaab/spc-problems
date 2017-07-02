#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdbool.h>

using namespace std;


int main(void){

	int ncasos;
	cin >>  ncasos;
	while(ncasos > 0){
		int matriz[4][4];
		int n, maxval = 0;
		
		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				cin >> n;
				matriz[i][j] = n;
				if( n == 2048 ) maxval = 1;
			}
		}

		if( maxval == 1 ){
			cout << "NONE"<< endl;
			ncasos--;
			continue;
		}

		bool down = false, left = false, right = false, up = false;
		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				if( matriz[i][j] == 0) continue;

				if( !down && i < 3  && (matriz[i+1][j] == 0 || matriz[i+1][j] == matriz[i][j]) ){					
					down = true;
					maxval = 1;					
				}
				if( !left && j > 0 && (matriz[i][j-1] == 0 || matriz[i][j-1] == matriz[i][j]) ){
					left = true;
					maxval = 1;				
				}
				if( !right && j < 3 && (matriz[i][j+1] == 0 || matriz[i][j+1] == matriz[i][j])  ){
					right = true;
					maxval = 1;					
				}
				if( !up && i > 0 && (matriz[i-1][j] == 0 || matriz[i-1][j] == matriz[i][j]) ){
					up = true;
					maxval = 1;					
				}
			}
		}	

		if(maxval == 0 ){
			cout << "NONE";
		}else{
			if(down) cout << "DOWN";
			if(down && (left || right || up) ) cout << " ";
			if(left) cout << "LEFT";		
			if(left && (right || up) ) cout << " ";		
			if(right) cout << "RIGHT";
			if(right && ( up ) ) cout << " ";
			if(up) cout << "UP";
		}
		cout << endl;
		ncasos--;
	}
}		