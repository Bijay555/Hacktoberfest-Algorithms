// Author: Julio Cesar Goldschmidt
// GitHub: https://github.com/JulioGold

/**
 * The method sort array with the InsertionSort sort algorithm.
 * @param {Array} array Array of elements to sort.
 */
function InsertionSort(array) {
    let len = array.length;
    let value;
    let i;
    let j;

    for(i = 1; i < len; i++) {

        value = array[i]
        j = i - 1

        while (j >= 0 && array[j] > value) {
            array[j+1] = array[j]
            j--
        }

        array[j+1] = value
    }
    
    return array
}

/**
 * The main function to run the algorithm.
 */
(function main() {
    let arr = [3, 1, 2, 5, 4];
    let arrResult = InsertionSort(arr);
    console.log(arrResult.join(','));
})()
