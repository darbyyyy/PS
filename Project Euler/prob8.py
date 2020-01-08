
num = [int (i) for i in str(input())]

value = 1
for i in range(5):
	value *= num[i]

max = 0
for i in range(4, len(num)):
	value = 1
	for j in range(5):
		value *= num[i-j]
	if(max < value):
		max = value

print max