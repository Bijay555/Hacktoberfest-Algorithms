# Harish Patel github: @haripatelll
# python code that computes the fibanacci number

# Original Method of Calculating The fibonacci via Recursion
# Time Complexity is Exponential
# T(n) = T(n-1) + T(n-2)
def fibanacci_recursion(n):
    if n <= 0:
        print("Invalid input")
    # Base case 1
    elif n == 1:
        return 0
    # Base case 2
    elif n == 2:
        return 1
    # Recursive approach
    else:
        return fibanacci_recursion(n-1) + fibanacci_recursion(n-2)

# We can do a better approach via Dynamic Programming
# Time Complexity is O(n)
fib_Array = [0, 1]
def fibanacci_dp(n):
    if n <= 0:
        print("Invalid input")
    elif n <= len(fib_Array):
        return fib_Array[n-1]
    else:
        temp_fib = fibanacci_dp(n-1) + fibanacci_dp(n-2)
        fib_Array.append(temp_fib)
        return temp_fib

if __name__ == "__main__":
    print(fibanacci_recursion(10))
    print(fibanacci_dp(10))
