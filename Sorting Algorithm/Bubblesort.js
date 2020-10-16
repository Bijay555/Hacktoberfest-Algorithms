// Author: Julio Cesar Goldschmidt
// GitHub: https://github.com/JulioGold

/**
 * The method sort array with the Bubble sort algorithm.
 * @param {Array} array Array of elements to sort.
 */
function BubbleSort(array) {
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = 0; j < array.length - 1; j++) {
            if ( array[j] > array[j + 1] ) {
                let temp = array[j];
                array[j] = array[j + 1];
                array[j+1] = temp;
            }
        }
    }
}

/**
 * The main function to run the algorithm.
 */
(function main() {
    let arr = [3, 1, 2, 5, 4];
    BubbleSort(arr);
    console.log(arr.join(','));
})()
