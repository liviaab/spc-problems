def main():
	n = int(input())
	while 1:
		if n == 0:
			break;

		dic = {}
		line = input();
		line = line.split(" ")
		dic[line[1]] = line[0]
		dic[line[3]] = line[2]

		line = input();
		line = line.split(" ", 1)


		if ((int(line[0]) + int(line[1])) % 2) == 0:
			print (dic["PAR"])
		else:
			print (dic["IMPAR"])

		n -= 1

main()