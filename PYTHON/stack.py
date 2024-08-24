from collections import deque

mystack = deque()
mystack.append(10)
mystack.append(20)
print(".size() :", len(mystack))
print(".top() :", mystack[-1])  # Access the top element
mystack.pop()
print(".top() :", mystack[-1])  # Access the new top element
print(".empty() :", len(mystack) == 0)
mystack.pop()
print(".empty() :", len(mystack) == 0)
# Accessing the top of an empty stack will raise an IndexError
# Uncommenting the following line will cause an error:
# print(".top() :", mystack[-1])