def insertion_sort(lst):
    n = 1
    for i in range(n, len(lst)):
        if lst[i] < lst[i-1]:
           for j in range(n-1, -1, -1):
                if lst[i] > lst[j]:
                    lst.insert(j+1, lst[i])
                    lst.pop(i+1)
                elif j == 0:
                    lst.insert(0, lst[i])
                    lst.pop(i+1)
        n+=1
    print(lst)
