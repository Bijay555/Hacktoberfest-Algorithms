# Author: AnushkaThakkar

# This program receives the list as an input from User and then sort it using merge sort algorithm.

def merge_sort(alist, start, end):       # <--- merge_sort will sort the list from indexes start to end – 1 inclusive
    if end - start > 1:                  # <--- If end – start is not greater than 1, then return
        mid = (start + end)//2           # <--- Otherwise, set mid equal to the floor of (start + end)/2
        merge_sort(alist, start, mid)    # <--- Call merge_sort with the same list and with start = start and end = mid as arguments
        merge_sort(alist, mid, end)      # <--- Call merge_sort with the same list and with start = mid and end = end as arguments
        merge_list(alist, start, mid, end)   
 
def merge_list(alist, start, mid, end):    # <--- merges to create a new sorted list from indexes start to end – 1.
    left = alist[start:mid]
    right = alist[mid:end]
    k = start
    i = 0
    j = 0
    while (start + i < mid and mid + j < end):
        if (left[i] <= right[j]):
            alist[k] = left[i]
            i = i + 1
        else:
            alist[k] = right[j]
            j = j + 1
        k = k + 1
    if start + i < mid:
        while k < end:
            alist[k] = left[i]
            i = i + 1
            k = k + 1
    else:
        while k < end:
            alist[k] = right[j]
            j = j + 1
            k = k + 1
 
 
alist = input('Enter the list of numbers: ').split()   # <--- Receiving the list from user
alist = [int(x) for x in alist]
merge_sort(alist, 0, len(alist))                       # <--- Calling merge_sort function
print('Sorted list: ', end='')            
print(alist)                                           # <--- Printing sorted list