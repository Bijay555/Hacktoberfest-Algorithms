def binary_search(data, target, low=0, high=None):
	"""If target is found in indicated portion of a list, returns True. Please note that the last two parameters are optional.
	
	The search only considers the portion from data[low] to data[high] inclusive."""
	# here we set a default parameter high to the length of the first arg
	if high is None:
		high = len(data)

	if low > high:
		return False
	else:
		mid = (low+high) //2

		if target == data[mid]:
			return True
		elif target < data[mid]:
			#recur on the portion left of the middle
			return binary_search(data, target, low, mid-1)
		else:
			#recur on the portion right of the middle
			return binary_search(data, target, mid+1, high)

#can be called like this:
#arr = [k+1 for k in range(10000)]
#binary_search(arr, 7503)
