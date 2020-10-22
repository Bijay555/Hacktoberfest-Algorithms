import unittest

def partition(array, begin, end):
    pivot = begin
    for i in xrange(begin+1, end+1):
        if array[i] <= array[begin]:
            pivot += 1
            array[i], array[pivot] = array[pivot], array[i]
    array[pivot], array[begin] = array[begin], array[pivot]
    return pivot

def quicksort(array, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    def _quicksort(array, begin, end):
        if begin >= end:
            return
        pivot = partition(array, begin, end)
        _quicksort(array, begin, pivot-1)
        _quicksort(array, pivot+1, end)
    return _quicksort(array, begin, end)
    
class TestQuickSort(unittest.TestCase):
    def test_sort(self):
        array = [1,99,2,98,3,97,4,96,4,95,5,94]
        ans_array = [1, 2, 3, 4, 4, 5, 94, 95, 96, 97, 98, 99]
        quicksort(array)
        self.assertEqual(array, ans_array)

if __name__ == '__main__':
    unittest.main()