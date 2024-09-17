'''
This function takes 4 arguments, list which has to be worked with, a number to insert, starting position in list to consider, ending position which has to be considered. 
1. bisect(list, num, beg, end) :- This function returns the position in the sorted list, where the number passed in argument can be placed so as to maintain the resultant list in sorted order. If the element is already present in the list, the rightmost position where element has to be inserted is returned.
2. bisect_left(list, num, beg, end) :- This function returns the position in the sorted list, where the number passed in argument can be placed so as to maintain the resultant list in sorted order. If the element is already present in the list, the leftmost position where element has to be inserted is returned. 
3. bisect_right(list, num, beg, end) :- This function works similar to the “bisect()” and mentioned above. '''

import bisect

li = [1, 3, 4, 4, 4, 6, 7]
 
# using bisect() to find index to insert new element
# returns 5 ( right most possible index )
print ("Rightmost index to insert, so list remains sorted is : ",
       end="")
print (bisect.bisect(li, 4))
 
# using bisect_left() to find index to insert new element
# returns 2 ( left most possible index )
print ("Leftmost index to insert, so list remains sorted is : ", 
       end="")
print (bisect.bisect_left(li, 4))
 
# using bisect_right() to find index to insert new element
# returns 4 ( right most possible index )
print ("Rightmost index to insert, so list remains sorted is : ",
       end="")
print (bisect.bisect_right(li, 4, 0, 4))

'''
This function takes 4 arguments, list which has to be worked with, number to insert, starting position in list to consider, ending position which has to be considered. 
4. insort(list, num, beg, end) :- This function returns the sorted list after inserting number in appropriate position, if the element is already present in the list, the element is inserted at the rightmost possible position. 
5. insort_left(list, num, beg, end) :- This function returns the sorted list after inserting number in appropriate position, if the element is already present in the list, the element is inserted at the leftmost possible position. 
6. insort_right(list, num, beg, end) :- This function works similar to the “insort()” as mentioned above. '''