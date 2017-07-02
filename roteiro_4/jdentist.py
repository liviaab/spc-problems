
def main():
	nconsultas = int(input())
	listaconsultas = []

	for i in range(nconsultas):
		line = input()
		line = line.split(" ")
		hinicio = int(line[0])
		htermino = int(line[1])
		listaconsultas.append( (hinicio, htermino) )


	# print(listaconsultas)
	listaconsultas.sort(key = lambda tupla: tupla[1])
	# print("Ordenada:")

	ultimofinal = listaconsultas[0][1]
	escolhidos = 1
	# print(ultimofinal)
	for i in range( 1, len(listaconsultas)):
		if( listaconsultas[i][0] >= ultimofinal):
			escolhidos += 1
			ultimofinal = listaconsultas[i][1]



	print(escolhidos)

main()