#itai192
#a method that merges two ordered list
def Merge(l1, l2):
    l3=[]
	#until one list is empty
    while(len(l1)>0 and len(l2)>0):
	#add the lowest value between the two lists into the third list and remove it from the list it came from
        if (l1[0]<l2[0]):
            l3.append(l1.pop(0))
        else:
            l3.append(l2.pop(0))
	#when one of the two lists is empty, empty the other list into the third list and return the third list
    while(len(l1)>0):
        l3.append(l1.pop(0))
    while(len(l2)>0):
        l3.append(l2.pop(0))
    return l3
#the recursive merge sort method
def MergeSortRec(lis,start,end):
    length=end-start+1
	#if the length is one return a list with one item in it
    if(length==1):
        return [lis[start]]
	#if the list has two items, return a list containing the two items in order
    if(length==2):
	#if the list is in order return it the same way
        if(lis[start]<lis[end]):
            return [lis[start],lis[end]]
	#if the list isn't in order reverse the order and return it
        else:
            return[lis[end],lis[start]]
	#if the list has more than 2 items in it, split the list into 2, and sort them, then merge them
    mid= (start+end)//2
    l1 = MergeSortRec(lis,start,mid)
    l2 = MergeSortRec(lis,mid+1,end)
    return Merge(l1,l2)
#an help method to use the recursive merge(i'm new to python so I don't know if there is a better way to do it)
def MergeSort(lis):
    return MergeSortRec(l1,0,len(lis)-1)


