"""

Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: CF50B - Choosing Symbol Pairs

É feita a leitura da linha de entrada. É criado um dicionário que armazena cada caractere da entrada e quantas
vezes ele é encontrado na linha. Para obter a resposta, uma variavel é inicializada com zero e itera-se sobre 
uma representação em lista do dicionário. A cada valor no dicionário, o seu quadrado é adicionado à variavel, 
a qual é impressa ao final do programa.
 
"""


def main():
	line = input()
	dicline = {}

	for c in line:
		if c in dicline.keys() :
			dicline[c] += 1
		else:
			dicline[c] = 1

	ans = 0
	for key, value in dicline.items():
		ans += value**2

	print(ans)


main()
