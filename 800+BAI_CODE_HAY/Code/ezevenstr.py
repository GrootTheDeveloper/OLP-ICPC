from collections import defaultdict 
f=defaultdict(int)
s=input()
for i in s:
	f[i]+=1
cnt=0 
for i in range(ord('a'),ord('z')+1):
	if (f[chr(i)]%2==1):
		cnt+=1 
if (cnt==0):
	print('Yes')
else:
	print('No')