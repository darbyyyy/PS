out =0
for i in range(100, 1000):
	for j in range(i, 1000):
		str_origin = str(i*j)
		str_reversed = str_origin[::-1]
		if str_origin == str_reversed and out < i*j:
			out= i*j

print out