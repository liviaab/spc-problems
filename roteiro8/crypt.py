"""
Nome: Lívia Almeida Barbosa
Matricula: 2013007579
Problema: 10008 - What's Cryptanalysis?

A cada linha lida, todos os seus caracteres são transformados para letras maiusculas.
Para realizar a contagem das letras, foi utilizado um dicionario no qual as chaves são as
letras e os respectivos valores são a quantidade de vezes que cada letra aparece nas frases ( >= 1).
Em seguida, é obtida uma representação em lista desse dicionário, ordenada da forma pedida 
no enunciado do problema ( decrescente pelo valor e crescente pelo caractere), a qual é impressa
ao final. 

"""

import operator
import string

def main():
	n = int( input() )
	result = {} 	
	while ( n > 0 ):
		line = input()
		line = line.upper()
		for c in line:
			if c in result:
				result[c] += 1
			else:
				result[c] = 1		
		n-= 1; 


	sorted_result = sorted(result.items(), key=lambda x: (-x[1], x[0]))
	
	for ( c, v ) in sorted_result:
		if( c in string.ascii_uppercase):
			print(c, v)

main()
