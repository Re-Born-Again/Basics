x=[int(item)
for item in input("Enter the list items : ").split()]
print(x)
s=0
for i in x:
  s=s+(abs(i)**2)
r=s**0.5
print("L2 value : ",r)