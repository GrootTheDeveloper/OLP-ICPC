from collections import defaultdict
f=defaultdict(int)
n=int(input())
a=list(map(int,input().split()))
for i in a:
    f[i]+=1
for i in a:
    print(i,f[i])
