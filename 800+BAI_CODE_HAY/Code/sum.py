
v=[]
def init():
	for i in range(1,10):
		val=0
		for j in range (31):
			val=val*10+i
			v.append(val)


init()
n=int(input())
v.sort()
res=-1
for i in v:
	if (i%n==0):
		res=i/n 
		break
print(int(res))

