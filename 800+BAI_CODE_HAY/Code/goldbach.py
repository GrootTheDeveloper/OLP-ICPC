n=int(input())
prime=[True]*(n+5)
for i in range(2,int(n**0.5)+1):
    if (prime[i]):
        for j in range(i*i,n+1,i):
            prime[j]=False
res=0
for i in range(2,n//2+1):
    if (prime[i] and prime[n-i]):
        res+=1
print(int(res))
