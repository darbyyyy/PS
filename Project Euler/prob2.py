a = 1; b=1
temp = a+b
sum=0
while(temp <=4000000):
	if temp%2==0:
		sum+=temp
	a=b
	b=temp
	temp = a+b

print sum