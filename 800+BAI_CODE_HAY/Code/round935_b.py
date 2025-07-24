t=int(input())
for l in range (t):
	a,b,n=map(int,input().split())
	print((n+a)//a + (n+b)//b)