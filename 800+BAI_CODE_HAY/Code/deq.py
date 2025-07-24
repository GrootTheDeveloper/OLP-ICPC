n=int(input())
a=list(map(int,input().split()))
b=[]
for i in a:
	while True:
		if (len(b)==0):
			print(0,end=' ')
			break
		k=b.pop()
		if k<=i:
			print(k,end=' ')
			b.append(k)
			break 
	b.append(i)
