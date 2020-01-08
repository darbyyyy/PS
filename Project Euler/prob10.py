
MAX_NUM = 2000000

sum = 0

pnum = [1 for i in range(MAX_NUM)]

for i in range(2, MAX_NUM):
	if(pnum[i]):
		sum += i
		for j in range(i*i, MAX_NUM, i):
			pnum[j] = 0

print sum 