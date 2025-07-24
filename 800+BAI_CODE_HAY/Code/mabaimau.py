n=int(input())
a=list(map(int,input().split()))
k=0
for i in range (0,n):
	if a[i]>=a[k]:
		k=i
print(k+1)