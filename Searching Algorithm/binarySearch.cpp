// Mohanned Kandil
// Binary Search in iterative method, Implemented in C++
#include <iostream>
using namespace std;

int binarySearch(int array[], int targetNumber, int low, int high) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == targetNumber)
            return mid;

        if (array[mid] < targetNumber)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1; // if the target number is not found
}

int main(void) {
    int array[] = { 10, 11, 13, 15, 18, 20, 31 };
    int targetNumber = 18;
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, targetNumber, 0, sizeOfArray - 1);
    if (result == -1)
        cout << "Not found in the list" << endl;
    else
        cout << "Element at index: " << result << endl;
}
