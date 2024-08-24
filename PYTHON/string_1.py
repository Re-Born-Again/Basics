def func1():
    str = "aa bb cc dd"
    temp = str.split(' ')
    for t in temp:
        print(t)

def func2():
    s1 = "()[]{}"
    str1 = ""
    for i in range(len(s1)):
        str1 += s1[i]
        print(f'str1 value : {str1}')
    
    print(f'str1 value : {" ".join(str1)}')
    print(f'str1.size() : {len(str1)}')
    print(f'str1.length() : {len(str1)}')
    
    print("\n\n")
    
    s2 = "()[]{}"
    str2 = ' ' * len(s2)
    str2 = list(str2)
    for i in range(len(s2)):
        str2[i] = s2[i]
        print(f'str2 value : {"".join(str2)}')

def func3():
    str = "ab:cd"
    sub1 = str[:len(str) - 2]
    print(f'sub1 : {sub1}')
    
    pos = str.find(":c")
    sub2 = str[pos + 1:]
    print(f'sub2 : {sub2}')

def func4():
    str = ""
    str += chr(1)  # Adding ASCII char value 1 to string
    print(str)

def func5():
    str = "abcdefgh"
    str = ""
    print(str)
    
    str2 = "abcdefgh"
    str2 = str2[:4]
    print(str2)
    
    str3 = "abcdefgh"
    str3 = str3[:4] + str3[6:]
    print(str3)

func3()
