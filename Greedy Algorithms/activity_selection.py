def MaxActivities(s , f ): 
    n = len(f) 
    print ("The activities selected are:")
  
    # The first activity is always selected 
    i = 0
    print (i)
  
    # Remaining activities 
    for j in range(n):
      # Select an activity only if beginning time is greater than or equal the end time of the last activity
        if s[j] >= f[i]: 
            print (j) 
            i = j 
  
# Driver program  
s = [0 , 2 , 1 , 4 , 7 , 4] 
f = [1 , 3, 5 , 6 , 8 , 8] 
MaxActivities(s , f) 
