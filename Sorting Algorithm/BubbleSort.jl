# Name : Luiz Fernando Santos
# github username : LFRusso

# Deffining bubble sort algorithm
function bubbleSort(list)
    swapped = true
    compares = 0
    size = length(list)
    while swapped
        swapped = false
        for j =2:size
            if list[j-1]>list[j]
                # Swapping elements positions
                aux = list[j-1]
                list[j-1] = list[j]
                list[j] = aux
                swapped = true
            end
            compares += 1
        end
    end
    return list
end

# Sample input and output
items = [4, 3, 2, 1, 10, 4, 11, 14, 2, 6]
println("Original list: ", items)

bubbleSort(items)
println("Sorted list: ", items)