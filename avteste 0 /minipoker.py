# your code goes here
def main():
	n = 1;
	
	cteste = int(raw_input())
	while ( cteste != 0 ):
		pontuacao = 0
		aux = raw_input()
		aux = aux.split(" ")
		cartas = []

		for i in range(0, len(aux)):
			cartas.append(int(aux[i]))

		cartas.sort()

		sequencia = 1; 
		#caso 1 - sequencia
		for i in range(0, len(cartas)-1):
			if (cartas[i+1] != cartas[i] + 1):
				sequencia = 0;

		if(sequencia):
			pontuacao = cartas[0] + 200	
		#caso 2 - quadrupla
		else:		
			quadrupla = 0
			for i in range(0,2):
				if(cartas[0 + i] == cartas[1 + i] and cartas[1 + i] == cartas[2 + i] and cartas[2 + i] == cartas[3 + i]):
					quadrupla = 1
					
			if(quadrupla):
				pontuacao = cartas[2] + 180
			#caso 3 - trinca e par
			else:
				if( cartas[0] == cartas[1] and cartas[1] == cartas[2] and cartas[3]== cartas[4]) or ( cartas[0] == cartas[1] and cartas[2] == cartas[3] and cartas[3]== cartas[4]):
					pontuacao = cartas[2]  + 160
				#caso 4 - trinca e diferente
				else:
					trinca = 0
					for i in range (0, 3):
						if (cartas[0 + i] == cartas[1 + i ] and cartas[ i + 1] == cartas[ i + 2]):
							trinca = 1
							break
						
					if trinca:
						pontuacao = cartas[i] + 140
					#caso 5 - dois pares
					else:
						if(cartas[0] == cartas[1] and cartas[2]== cartas[3]):
							pontuacao = cartas[3] * 3 + cartas[0] * 2 + 20
						elif (cartas[0] == cartas[1] and cartas[3]== cartas[4]) or (cartas[1] == cartas[2] and cartas[3] == cartas[4]):
							pontuacao = cartas[3] * 3 + cartas[1] * 2 + 20
						
						#caso 6 - um par
						else:
							par = 0
							for i in range(0, len(cartas) -1):
								if( cartas[i] == cartas[i+1]):
									par = 1
									break

							if(par):
								pontuacao = cartas[i]

		print "Teste ", n
		print pontuacao
		print ""
		cteste -= 1
		n+= 1

	return 0
	
main()