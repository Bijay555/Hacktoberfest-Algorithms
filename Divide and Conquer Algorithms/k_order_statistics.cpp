// Created by GeorgiyX (github.com/GeorgiyX) 31.10.2020.
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <random>

size_t getUnsignedRandom(size_t min, size_t max) {
    static std::mt19937 generator{std::random_device()()};
    std::uniform_int_distribution<size_t> distribution(min, max);
    return distribution(generator);
}

/**
 * Selects the pivot element (this is a random element in the array),
 * then sort the array "arr" - on the left, elements
 * smaller or equal to the pivot, and on the right, elements
 * larger. Returns the new pivot index.
 * @param arr - array pointer
 * @param left - left border
 * @param right - right border
 * @return the new pivot index. The element for this index is the pivot-th order statistic.
 */
size_t partition(int *arr, size_t left, size_t right) {
    /* determining the pivot by random, then swapping */
    std::swap(arr[left], arr[getUnsignedRandom(left, right - 1)]);
    size_t pivot = left; // now the pivot is on the left border
    int tmp;
    for (size_t i = left + 1; i < right; ++i) {
        if (arr[i] <= arr[pivot]) {
            /* move an element less than or equal to pivot before pivot */
            tmp = arr[i];
            memmove(arr + pivot + 1, arr + pivot, (i - pivot) * sizeof(arr[0]));
            arr[pivot] = tmp;
            pivot++;
        }
    }
    return pivot;
}

/**
 * Algorithm for searching for K-th order statistics. Non-recursive implementation
 * @param arr - array pointer
 * @param arrSize - array size
 * @param k - statistics number
 * @return returns the k-th ordinal statistics
 */
int kOrderStatistic(int *arr, size_t arrSize, size_t k) {
    assert(k < arrSize);
    size_t left = 0, right = arrSize;
    auto kExpected = partition(arr, left, right);
    while (k != kExpected) {
        kExpected = kExpected < k ? partition(arr, (left = kExpected + 1), right)
                                  : partition(arr, left, kExpected);
    }
    return arr[k];
};


int main() {
    int arr[] = {5, 3, 0, 8, 7, 1, 6, 8, 15, 2, 6, 10, 16};
    std::for_each(arr, arr + (sizeof(arr) / sizeof(arr[0])), [](auto el) { std::cout << el << " "; });
    std::cout << std::endl << "kOrderStatistic(11): " << kOrderStatistic(arr, sizeof(arr) / sizeof(arr[0]), 11)
              << std::endl;
    return 0;
}
