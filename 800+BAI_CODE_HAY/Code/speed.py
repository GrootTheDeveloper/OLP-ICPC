import math
mode = 100000000007
def power(a, b):
	li = [1,0]
	while b != 0:
		if b % 2 == 1:
			li[0] *= a
			li[1] += li[0] // mode
			li[0] %= mode
		a = a * a % mode
		b //= 2
	return li


a,b = map(int, input().split())

v1 = power(a,b)
v2 = power(b,a)

if (v1[0] == v2[0] and v1[1] == v2[1]):
	print(0)
elif (v1[0] > v2[0] or (v1[0] == v2[0] and v1[1] > v2[1])):
	print(1);
else:
	print(2);

