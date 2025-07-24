def g(x):
	return x*(x+1)*(2*x+1)//6


a,b,n=map(int,input().split())

print(int(g(b)-g(a-1))%n)
