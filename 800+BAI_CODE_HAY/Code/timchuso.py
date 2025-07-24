import math 

def fastpow(a,b,mode):
	res = 1 
	while b != 0:
		if (b % 2 == 1):
			res = res * a % mode
		a = a * a % mode 
		b = b // 2
	return res 

t = int(input())
for i in range(t):
	a,b,k = map(int,input().split());
	print( ((a % b) * fastpow(10, k-1, b)) % b * 10 // b)