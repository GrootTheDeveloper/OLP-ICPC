def calc(n):
	return n*(n+1)//2

t=int(input())
for e in range(t):
	x=int(input())
	l,r=1,100000000
	while l<r:
		mid=(l+r)//2
		if (calc(mid)>x):
			r=mid-1
		else:
			l=mid+1
	while calc(l-1)>=x:
		l-=1
	while calc(l)<x:
		l+=1
	if (calc(l)==x):
		print(0)
	else:
		print(1)