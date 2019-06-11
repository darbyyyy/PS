num = 600851475143
pnum_max =1
i=2
while(num >1):

	if num%i==0:
		num /=i
		pnum_max = i

	else:
		i=i+1
print pnum_max