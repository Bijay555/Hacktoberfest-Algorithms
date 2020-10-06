// utility: swap
void swap(int* array, int L, int R) {
    int temp = array[L];
    array[L] = array[R];
    array[R] = temp;

    return;
}

// utility: partition
int partition(int* array, int low, int high) {
    //parameters
    int pivot = low;
    int i = low;
    int j = high;

    //iterate and swap untill indices cross
    while (i < j) {
        while ((array[i] <= array[pivot]) && (i < high))
            ++i;
        while (array[j] > array[pivot])
            --j;
        if (i < j)
            swap(array, i, j);
    }
    swap(array, pivot, j);

    return j;
}

// algorithm
void quick_sort(int* array, int low, int high) {
    if (low >= high)
        return;

    int pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);

    return;
}
