def nt(n):
	if n<2: return False 
	for i in range(2,int(n**0.5)+1):
		if n%i==0:
			return False
	return True 

def snt(n):
	while (nt(n)):
		n//=10
	if (n==0):
		return True 
	else:
		return False 

n=int(input())
if snt(n):
	print("PHAI")
else:
	print("KHONG")
