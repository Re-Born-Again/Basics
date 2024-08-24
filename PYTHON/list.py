l1 = [1,2,3,4,5]
print("l1 : ",l1)

# access
print("from 0 to end with step 2 idx : ",l1[::2])

# add
l2 = []
l2.append("val1")
l2.insert(1,"val2") # index, value
l2.insert(10,"val3") # if index exceed then adds at last
l2.append("val4")
print("l2 : ",l2)

l2.extend(l1) # add an iterable at last
print("l2 : ",l2)

# update
l1[4] = 100 # particular index
l1[:2] = [11,10] # range of indices
print("l1 : ",l1)

# remove
l2.remove("val4") # value
l2.pop(5) # index
print("l2 : ",l2)

# find 1st occurence index of value
print(l2.index("val1"))

# count no. values in list
print(l1.count(100))