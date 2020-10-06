#Contributor Adya
#Implementing the fractional knapsack algorithm in python

def fractional_knapsack(W,V,w):
	dict={}
	val=0
	for i in range(len(W)): 
		dict.update({V[i]//W[i]:i})

	#creating an array with sorted value by weight values
	p=sorted(dict.keys(),reverse=True)
	
	
	for i in p:
		if w==0:
			return val
		a=min(W[dict[i]],w)
		val=val+a*i
		w=w-a
	return val


#driver code
W=[5,10,20,30,40]
V=[30,20,100,90,160]
w=60
print(fractional_knapsack(W,V,w))