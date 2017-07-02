"""
Nome: Livia Almeida Barbosa
Matricula: 2013007579
Problema: NUMERDOS - Número de Erdos

É feita a leitura da entrada e armazena-se os nomes dos autores em formato de tuplas. O grafo nao direcionado é representado por um dicionário de listas, no qual cada autor é uma chave do dicionario. Em seguida, aplica-se o algoritmo de busca em largura para que seja calculado o numero de Erdos para cada autor. É utilizado um dicionário auxiliar que armazena o autor (também em formato de tupla) e seu numero de Erdo, para que facilite o calculo para os autores seguintes.
Ao final, a lista de autores é ordenada baseado no nome e no sobrenome do autor
"""
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


		for j in range(0, len(lineaux)):
			for k in range(0, len(lineaux)):
				if lineaux[j] !=  lineaux[k]:
					
					tupla1 = lineaux[j].split(" ")
					tupla2 = lineaux[k].split(" ")
					tupla1 = (tupla1[0], tupla1[1])
					tupla2 =(tupla2[0], tupla2[1])
					graph[ tupla1 ].append( tupla2 )

	# fim da leitura
	
	# bfs para num erdos
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
