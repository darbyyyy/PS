import array

MAX_NUM = 1000000
pnum = [1 for i in range(MAX_NUM)]


for i in range(2, MAX_NUM):
	if pnum[2] :
		check_num = i*i
		while(MAX_NUM > check_num):
			pnum[check_num]=0
			check_num += i
cnt= 0
for i in range(2, MAX_NUM):
	if(pnum[i]):
		cnt+=1;
		if(cnt == 10001):
			print i
			exit()
