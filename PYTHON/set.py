s1 = set()
for i in range(6):
    s1.add(i)
print(" ".join(map(str, s1)))
print(s1)

print(f'3 present in s1 : {3 in s1}')
print(f'10 present in s1 : {10 in s1}')

v = [1, 2, 3, 4, 5, 6]
s2 = set(v)
print(" ".join(map(str, s2)))

s2.discard(3) # does not raise error if element not present
# s2.remove(3) raises error if element not present
print("After erasing 3:")
print(" ".join(map(str, s2)))

if 2 in s2:
    print(f'Found {2}')
else:
    print("Not found")

print("s1 : ",s1)
print("s2 : ",s2)
# set operations : 

# union
print("union : ",s1 | s2)

# intersection
print("intersection : ",s1 & s2)

# difference
print("difference : ",s1 - s2)