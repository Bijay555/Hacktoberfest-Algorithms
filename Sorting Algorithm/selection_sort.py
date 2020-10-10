#author: Arpit Dadhich

# Python program for implementation of Selection 
# Sort 
import sys 
arr = [14, 45, 62, 32, 91] 
  
# Traverse through all array elements 
for i in range(len(arr)): 
      
    # Find the minimum element in remaining  
    # unsorted array 
    min_index = i 
    for j in range(i+1, len(arr)): 
        if arr[min_index] > arr[j]: 
            min_index = j 
              
    # Swap the found minimum element with  
    # the first element         
    arr[i], arr[min_index] = arr[min_index], arr[i] 
  
# Driver code to test above 
print ("Sorted array") 
for i in range(len(arr)): 
    print(arr[i])  
