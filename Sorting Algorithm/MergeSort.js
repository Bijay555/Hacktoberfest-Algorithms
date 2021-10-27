// Author: Julio Cesar Goldschmidt
// GitHub: https://github.com/JulioGold

function merge(left, right) {
    let result = [];
    let i = 0;
    let j = 0;

    while(i < left.length && j < right.length) {
        if(left[i] < right[j]) {
            result.push(left[i++]);
        } else {
            result.push(right[j++]);
        }
    }

    return result.concat(left.slice(i)).concat(right.slice(j));
}

/**
 * The method sort array with the Bubble sort algorithm.
 * @param {Array} arr Array of elements to sort.
 */
function MergeSort(arr) {
    let arrayLength = arr.length;
    let middle;

    if (arrayLength < 2) {
        return arr;
    }

    middle = Math.floor(arrayLength/2);
    
    return merge(MergeSort(arr.slice(0, middle)), MergeSort(arr.slice(middle)));
}

/**
 * The main function to run the algorithm.
 */
(function main() {
    let arr = [3, 1, 2, 5, 4];
    let resultArray = MergeSort(arr);
    console.log(resultArray.join(','));
})()
