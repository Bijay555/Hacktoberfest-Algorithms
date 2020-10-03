// Contributor: Bibek Kakati
// Github: bibekkakati

// A function to sort the given list using Gnome Sort
function gnomeSort(arr, len) {
	// To store current level of index
	let index = 0;
	let temp;
	while (index < len) {
		// In case of starting index increment the index by 1
		if (index == 0) index = index + 1;

		// If value of current element of the array is greater than the previous element than increment the index by 1
		if (arr[index] >= arr[index - 1]) index = index + 1;
		// If value of current element is less than previous element than swap and decrement the index by 1
		else {
			temp = arr[index - 1];
			arr[index - 1] = arr[index];
			arr[index] = temp;
			index = index - 1;
		}
	}
	return arr;
}

// Input array
let arr = [14, 52, 0, -100, -98];
let len = arr.length;

arr = gnomeSort(arr, len);
console.log("Sorted array is: ", arr);
