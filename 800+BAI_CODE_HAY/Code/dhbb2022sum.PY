n,a,b=map(int,input().split())
mode=int(10**9+7)
s1=((a%mode)*(n*(n+1)//2%mode))%mode
x=0
for i in range(1,1000001):
    t1=i**2
    t2=(i+1)**2-1
    t3=min(t2,n)
    x+=(t3-t1+1)*i
    if (n<=t2): break
s2=(b%mode)*(x%mode)
print(int((s1+s2)%mode))
