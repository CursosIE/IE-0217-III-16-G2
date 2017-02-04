
for i in range(100000):	

	f = open ("lista.txt", "a")
	f.write(str(i))
	f.write(" ")
	f.close()

