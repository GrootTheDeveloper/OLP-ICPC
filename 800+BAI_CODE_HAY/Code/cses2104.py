s=input()
q=int(input())
for i in range (0,q):
	st=input()
	k=s.find(st)
	if (k!=-1):
		k+=1
	print(k)