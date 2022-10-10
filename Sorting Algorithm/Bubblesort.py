# Name : Dakshay Ahuja
# github username : dakshayahuja

# Defining the bubble sort algo:
def bubble_sort(items):
    changes = passes = 0
    last = len(items)
    swapped = True

    while swapped:
        swapped = False
        passes += 1
        for j in range(1, last):
            if items[j - 1] > items[j]:
                items[j], items[j - 1] = items[j - 1], items[j]  # Swap
                changes += 1
                swapped = True
                last = j

    print(items)


print("Welcome to a Bubble Sort Algorithm in Python!")

# Calling the function:
while True:
    print("Enter as many numbers as you want.\nYou can choose between 0 and 9.\nLeave a space between each one")
    numbers = input()
    items = [int(num) for num in numbers.split() if num.isdigit()]
    if items:
        bubble_sort(items)
    break
