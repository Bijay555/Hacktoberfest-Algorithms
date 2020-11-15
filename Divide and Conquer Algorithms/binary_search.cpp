// Created by GeorgiyX (github.com/GeorgiyX) 29.10.2020.
#include <iostream>
#include <cassert>

/**
 * Simple non-recursive implementation of binary search (search in a sorted array).
 * Log(n) complexity :)
 * @param arr - array to search for
 * @param arrSize - array size
 * @param el - element to search for
 * @return index of el or -1 in case of failure
 */
int binarySearch(int *arr, size_t arrSize, int el) {
    assert(arr);
    size_t left = 0, right = arrSize, mid;
    int resultIndex = -1;
    while (left != right) {
        mid = (right + left) / 2;
        if (arr[mid] < el) {
            left = mid + 1;
        } else if (arr[mid] > el) {
            right = mid;
        } else {
            resultIndex = mid;
            break;
        }
    }
    return resultIndex;
}

/**
 * Binary search using recursion
 * @param arr - array to search for
 * @param left - left border of search
 * @param right - right border of search
 * @param el - element to search for
 * @return index of el or -1 in case of failure
 */
int binarySearchRecursively(int *arr, size_t left, size_t right, int el) {
    size_t mid = (left + right) / 2;
    if (left == right) {
        return -1;
    } else if (arr[mid] == el) {
        return mid;
    } else {
        return arr[mid] < el ? binarySearchRecursively(arr, mid + 1, right, el)
                             : binarySearchRecursively(arr, left, mid, el);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::cout << "binarySearch: " << binarySearch(array, (sizeof(array) / sizeof(array[0])), 6) << std::endl;
    std::cout << "binarySearchRecursively: "
              << binarySearchRecursively(array, 0, (sizeof(array) / sizeof(array[0])), 6) << std::endl;
    return 0;
}
