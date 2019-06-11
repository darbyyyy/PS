val = 1
def gcd(a, b):
	return gcd(b, a%b) if a%b else b
def lcm(a, b):
	return a * (b/ gcd(a, b))

for i in range(1, 21):
	val = lcm(val, i)

print val