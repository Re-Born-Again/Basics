
dict = {
        "a": 1,
        "aa": 2,
        "abcd": 1234
}
    
print(f'dict["a"] : {dict["a"]}')
print(f'dict["aa"] : {dict["aa"]}')
print(f'dict["abcd"] : {dict["abcd"]}')
print(f'dict["a"] + dict["aa"] : {dict["a"] + dict["aa"]}')
    
dict["a"] += 1
print(f'dict["a"]+=1 : {dict["a"]}')
    
dict["a"] = 3
print(f'dict["a"] : {dict["a"]}')
print(f'dict.get("b", 0) : {dict.get("b", 0)}')

print("using dict.get()")
print(f'dict.get("a", 0) : {dict.get("a", 0)}')
print(f'dict.get("b", 0) : {dict.get("b", 0)}')
print(f'dict.get("z", 0) : {dict.get("z", 0)}')

val_to_find = 1234
key_present = None
found = False
for key, value in dict.items():
    if value == val_to_find:
        found = True
        key_present = key
        break
    
if found:
    print(f'value set for key : {key_present}')
else:
    print("Not present in dictionary")

dict2 = {0: 'a', 1: 'b'}
it = dict2.get(1)
if it is not None:
    print(f'key : 1 value : {it}')
print("dict values : ",dict)
dict.pop("abcd") # key
del dict["aa"] # value
print("dict values after pop() and del : ",dict)

# to check if a key is present
if "a" in dict :
    print("Key \"a\" is present")
else :
    print("Key \"a\" is not present")