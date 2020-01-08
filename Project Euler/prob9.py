def sq(num):
	return num*num

for a in range(1, 1000/3, 1):
	for b in range(a+1, 1000/2, 1):
		c = 1000 - a - b
		if(sq(a) +sq(b) == sq(c)):
			print a, b, c, a*b*c