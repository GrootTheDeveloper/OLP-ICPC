n=int(input())
a=list(map(int,input().split()))
cnt=0
for i in a:
	if i==0:
		cnt=1

lim=10**18
s=1
for i in a:
	s*=i
	if s>lim:
		s=-1
		break
if (cnt==1):
	print(0)
else:
	print(s)