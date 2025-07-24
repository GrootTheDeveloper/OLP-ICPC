x,n,k=map(int,input().split())
print(max(0,k*(x+k*x)//2-n))