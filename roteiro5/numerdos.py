
teste = 1
while 1:
	numlinhas = int(input())
	if numlinhas == 0:
		break;

	graph = {}
	for i in range(numlinhas):
		line = input()		
		line = line[:len(line)-1] 
		line = line.split(",")
		lineaux = []
		for autor in line:
			lineaux.append(autor.strip())
		

		for autor in lineaux:	
			tupla = autor.split(" ")	
			tupla = (tupla[0], tupla[1])	
			if tupla not in graph:
				graph[tupla] = []

		# print("GRAFO1:")
		# for (s, n) in graph:
		# 	print( s, n, ":", graph[(s,n)])
		# print("")

		for j in range(0, len(lineaux)):
			for k in range(0, len(lineaux)):
				if lineaux[j] !=  lineaux[k]:
					# print("ADD PAR", end=" ")
					# print(lineaux[j],  lineaux[k], end=" ")
					tupla1 = lineaux[j].split(" ")
					tupla2 = lineaux[k].split(" ")
					# print(tupla1, tupla2)
					tupla1 = (tupla1[0], tupla1[1])
					tupla2 =(tupla2[0], tupla2[1])
					graph[ tupla1 ].append( tupla2 )
					# print("ADDOU")

					# print( (tupla1[0], tupla1[1]),":", graph[(tupla1[0], tupla1[1])]  )
					# print("GRAFO2:")
					# for (s, n) in graph:
					# 	print( s, n, ":", graph[(s,n)])
					# print("")
					# print("")

	# fim da leitura
	
	# fbs para num erdos
	dicvisitados = {}
	listavisitados = []
	

	fila = []

	tuplaErdo = "P. Erdos".split(" ")
	dicvisitados[ (tuplaErdo[0], tuplaErdo[1]) ] = 0
	fila.append( (tuplaErdo[0], tuplaErdo[1]) )

				
	if( (tuplaErdo[0], tuplaErdo[1])  in graph):
		while len(fila) != 0:
			autoratual = fila.pop(0)
			for (s, n) in graph[autoratual]:
				if( (s, n) not in dicvisitados ):
					dicvisitados[(s, n)] = dicvisitados[autoratual]+1
					fila.append((s, n))
					listavisitados.append( (n, s, dicvisitados[autoratual]+1) )
				

	for (s, n) in graph:
		if( (s, n) not in dicvisitados):
			listavisitados.append( (n, s, "infinito") )

	listavisitados = sorted(listavisitados, key=lambda x: (x[0], x[1],  ))
	
	print("Teste ",teste)
	for (sobrenome, nome, nErdo) in listavisitados:
		print(nome, sobrenome+":", nErdo)
	print("")
	teste += 1