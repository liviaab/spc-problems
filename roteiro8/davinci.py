"""
Nome: Lívia Almeida Barbosa
Matricula: 2013007579
Problema: 11385 - Da Vinci Code - UVA

Após a leitura das linhas de entrada, os numeros de Fibbonacci (até o valor máximo indicado) são calculados
e armazenados em um dicionário para uma consulta posterior. 
Em seguida é feita a tradução, como foi explicado no enunciado:
a cada letra e cada numero de fibbonacci da frase de entrada, calcula-se a "posição" do numero de fibbonacci 
(no caso, a chave do dicionário) e a letra é colocada nessa posição na string de saída.


"""

import string
import pprint

def main():
	ntests = int( input() )
	while (ntests > 0 ):
		firstline = int( input() )
		secline = input() # numbers from fib series
		secline = secline.split(' ')
		secline	= [ int(x) for x in secline]		
		thirdline = input() #cipher text
		
		dicfib = {}
		ap = 0
		p = 1
		i = 0

		while(1):
			if( i > 0 and dicfib[i-1] >= 2147483648):
				break
			dicfib[i] = ap + p
			ap = p
			p = dicfib[i]			
			i += 1

		auxans = [ " " for i in range ( max ( [ key for key, value in dicfib.items() if value == max(secline) ][0] +1, len(thirdline) ) ) ]
		indexfib = 0		
		for c in thirdline:
			
			if ( c in string.ascii_uppercase ):
				lkey = [ key for key, value in dicfib.items() if value == secline[indexfib] ][0]
				auxans[lkey] = c
				indexfib += 1
			
			if( indexfib >= len(secline))	:
				break
		
		auxans = "".join(auxans)
		ans = auxans.rstrip()
			
		print(ans)


		ntests -= 1
	
main()
