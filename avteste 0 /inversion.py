def main():
	testcase = int(raw_input())
	blank  = raw_input()

	while testcase > 0:
		veclen = int(raw_input())
		inv = 0
		vec = []

		for i in range(0, veclen):
			vec.append( int(raw_input()))
		blank  = raw_input()

		i = 0
		while i != veclen -1:
			if( vec[i] > vec[i + 1] ):
				inv += 1
				temp = vec[i]
				vec[i] = vec[i + 1]
				vec[i + 1] = temp
				i = 0 
			else:
				i += 1

		print inv
		testcase -= 1


main()