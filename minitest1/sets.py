def main():
	instancias = int(input())
	while instancias:
		numConj = int(input())
		setslist = []

		for i in range(numConj):
			auxlist = []
			line = input()
			line = line.split(" ")
			
			for c in line:
				auxlist.append(int(c))
			del auxlist[0]

			auxset = set(auxlist)
			setslist.append(auxset)

		numOps = int(input())
		ans = []
		for i in range(numOps):
			line = input()
			line = line.split(" ")
			a = int(line[1]) - 1
			b = int(line[2]) - 1
			count = 0

			if int(line[0]) == 1:
				#intersecao
				count = len( set.intersection( setslist[a], setslist[b] ) )
				print( count)
				ans.append(count)
			else:
				# uniao 
				count = len( set.union( setslist[a], setslist[b] ))
				print(count)
				ans.append(count)

		instancias -= 1


main()