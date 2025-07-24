import sys 
sys.stdin=open("dx.inp","r")
sys.stdout=open("dx.out",'w')
n=input()
a=n[0]*len(n)
b=str((int(n[0])+1)%10)*len(n)
if (int(b)<=int(n)): b='1'*(len(n)+1)
if int(a)-int(n)>0:
    print(int(a)-int(n))
else:
    print(int(b)-int(n))
