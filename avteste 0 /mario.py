import pprint
def main():

	line = raw_input()
	line = line.split(" ")
	numpedido = int(line[0])
	numdispon = int(line[1])

	while numpedido != 0 and numdispon != 0:
		armarios = {}
		livres = 9999999
		pos = 0

		line = raw_input()
		line = line.split(" ")

		for i in range(0, numdispon):
			armarios[int(line[i])] = 1

		for i in range(1, (int(line[i]) - numpedido)+2 ):
			aux = 0
			for j in range (i, i + numpedido):				
				if j not in armarios:
					aux += 1

			if( aux < livres):
				livres = aux

		print livres

		line = raw_input()
		line = line.split(" ")
		numpedido = int(line[0])
		numdispon = int(line[1])


main()