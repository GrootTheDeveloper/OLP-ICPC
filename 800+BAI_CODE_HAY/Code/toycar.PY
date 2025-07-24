a,b,n=map(int,input().split())
k=(a*b)-b
if (n%k==0):
    print (n//k)
else:
    print (n//k+1)
