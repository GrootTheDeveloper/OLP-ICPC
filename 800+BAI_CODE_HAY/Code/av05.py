n=int(input())
a=list(map(int,input().split()))
d=0
for i in range(n):
    if a[i]>0:
        print(i+1, end= ' ')
        d=d+1
        break
for i in range(n-1,-1,-1):
    if a[i]>0:
        print(i+1)
        d=d+1
        break
if d==0:
    print('-1 -1')
