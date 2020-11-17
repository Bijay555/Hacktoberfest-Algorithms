// Author: Julio Cesar Goldschmidt
// GitHub: https://github.com/JulioGold

function swap(items, firstIndex, secondIndex){
    var temp = items[firstIndex];
    items[firstIndex] = items[secondIndex];
    items[secondIndex] = temp;
}

function partition(items, left, right) {
    let pivot = items[Math.floor((right + left) / 2)];
    let i = left;
    let j = right;

    while (i <= j) {
        while (items[i] < pivot) {
            i++;
        }

        while (items[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(items, i, j);
            i++;
            j--;
        }
    }

    return i;
}

/**
 * The method sort array with the QuickSort sort algorithm.
 * @param {Array} array Array of elements to sort.
 */
function QuickSort(items, left, right) {

    var index;

    if (items.length > 1) {

        left = typeof left != "number" ? 0 : left;
        right = typeof right != "number" ? items.length - 1 : right;

        index = partition(items, left, right);

        if (left < index - 1) {
            QuickSort(items, left, index - 1);
        }

        if (index < right) {
            QuickSort(items, index, right);
        }

    }

    return items;
}

/**
 * The main function to run the algorithm.
 */
(function main() {
    let arr = [3, 1, 2, 5, 4];
    let arrResult = QuickSort(arr);
    console.log(arrResult.join(','));
})()
