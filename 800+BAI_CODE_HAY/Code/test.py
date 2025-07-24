

f=[1,2,3]
for i in range(100):
	f.append(f[len(f)-1]+f[len(f)-2])
print(len(f))
d=0
for i in f:
	if (i<100000000000000):
		d+=1
		print(i,end=',')
print(d)