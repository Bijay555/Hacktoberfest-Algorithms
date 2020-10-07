# Author GitHub: Rollerss

# Method takes an array and optional proc argunent.
# The proc is used to chage how the bubble sort works such as sorting highest to lowest.

def bubble_sort(array, &prc)

  # Default Proc if none is supplied to sort smallest to lagest.
  prc ||= Proc.new { |a, b| a <=> b }

  # Array has default of not being sorted
  sorted = false

  # Loop is run unit sorted is true, this happens when the if statement is not entered
  until sorted
    sorted = true

    (1...array.length).each do |i|

      # Proc is called to check if the two elements in the array are sorted
      if prc.call(array[i - 1], array[i]) == 1
        sorted = false
        array[i - 1], array[i] = array[i], array[i - 1]
      end
    end
  end

  array
end

# Tests for the bubble sort, all should return true

p bubble_sort([5, 4, 7]) == [4, 5, 7]
p bubble_sort([4, 12, 2, 8, 1, 14, 9, 25, 24, 81]) == [1, 2, 4, 8, 9, 12, 14, 24, 25, 81]
p bubble_sort([4, 12, 2, 8, 1, 14, 9, 25, 24, 81]) { |a, b| a.to_s <=> b.to_s } == [1, 12, 14, 2, 24, 25, 4, 8, 81, 9]
p bubble_sort([4, 12, 2, 8, 1, 14, 9, 25, 24, 81]) { |a, b| 1 if a < b } == [81, 25, 24, 14, 12, 9, 8, 4, 2, 1]
p bubble_sort(['x', 'e', 'b', 't', 'a']) == ["a", "b", "e", "t", "x"]