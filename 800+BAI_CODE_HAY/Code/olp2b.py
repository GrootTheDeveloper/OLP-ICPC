
set_check=[]
def sie():
	for i in range(1,10):
		t=0
		for j in range(1,1000):
			t=t*10+i 
			set_check.append(t)

n=int(input())
sie()
set_check.sort()
res=0
for i in set_check:
	if i%n==0:
		res=i/n 
		break
if (res==0):
	print(-1)
else:
	print(int(res))

