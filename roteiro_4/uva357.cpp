
/*
357 - Let Me Count The Ways
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 30001

using namespace std;

int main(void){
	int number;
	int i, j;
	int coins[5] = {1, 5, 10, 25, 50};
	long long manners[MAXSIZE] = {0};

	while(1){
		cin >> number;
		if( number == 0 || !number) break;

		manners[0] = 1;
		for (i = 0 ; i < 5 ; i++){
			for(j = coins[i]; j < number ; j++ ){
				manners[j] += manners[ j - coins[i]];
			}
		}

		if (manners[number] == 1)
            cout << "There is only 1 way to produce " << cents << " cents change.\n";
        else
            cout << "There are " << ways[cents] << " ways to produce " << cents << " cents change.\n";

	}
	return 0;
}