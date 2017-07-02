"""
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: POPULAR - Popularidade

Solução: É feita a leitura das cédulas e, durante o processo, é contado o numero de votos para cada 
aluno. Assim, ao final da entrada, cada candidato já possui a quantidade total de votos que recebeu 
e retorna-se o que possui o maior numero de votos.

"""

def main():
	
	num_cedulas = int(raw_input())
	
	while num_cedulas != 0 :
		cand_votos = {}	
		max_votos = 0
		for i in range(1, num_cedulas+1):
			cand_votos[i] = 0

		for j in range(0, num_cedulas):
				votos = []
				arraux_votos = raw_input()
				arraux_votos = arraux_votos.split(" ")				
				
				for i in range(0, len(arraux_votos)):
					votos.append(int(arraux_votos[i]))				

				for i in range(1, num_cedulas+1):
					cand_votos[i] += votos[i-1]
					if( cand_votos[i] > max_votos ):
						max_votos = cand_votos[i]

		print max_votos
		num_cedulas = int(raw_input())

main()

