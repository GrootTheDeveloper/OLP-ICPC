n=int(input())
a=list(map(int,input().split()))
MIN=10**9
t1=0
kq=0
for i in range(n):
	t1+=a[i]
	t2=0
	for j in range(i+1,n):
		t2+=a[j]
	if (abs(t1-t2)<MIN):
		MIN=abs(t1-t2)
		kq=i 
print(kq+1)