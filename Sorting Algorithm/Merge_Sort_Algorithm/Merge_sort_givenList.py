# Author: AnushkaThakkar

# This program has a given list to perform merge sort.

def merge_sort(unsorted_list):           # <--- divides the list into equal halves
    if len(unsorted_list) <= 1:
        return unsorted_list
    middle = len(unsorted_list) // 2     # <--- Find the middle point and divide it
    left_list = unsorted_list[:middle]
    right_list = unsorted_list[middle:]

    left_list = merge_sort(left_list)             # <--- Further divides into halves
    right_list = merge_sort(right_list)           # <--- Further divides into halves
    return list(merge(left_list, right_list))     # <--- returns the sorted list after sorting and merging the two halves using merge() function


def merge(left_half,right_half):                            # <---- Sort and Merge the halves

    res = []
    while len(left_half) != 0 and len(right_half) != 0:
        if left_half[0] < right_half[0]:                    # <--- Smallest gets appended in the list
            res.append(left_half[0])
            left_half.remove(left_half[0])         
        else:
            res.append(right_half[0])
            right_half.remove(right_half[0])
    if len(left_half) == 0:
        res = res + right_half
    else:
        res = res + left_half
    return res                                          # <--- Returns the sorted list
 
unsorted_list = [64, 34, 25, 12, 22, 11, 90]            # <--- Given list

print(merge_sort(unsorted_list))                        # <--- Prints the sorted list