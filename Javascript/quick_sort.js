// basic implementation, where pivot is the first element
function quickSortBasic(array) {
  if(array.length < 2) {
    return array;
  }

  var pivot = array[0];
  var lesserArray = [];
  var greaterArray = [];

  for (var i = 1; i < array.length; i++) {
    if ( array[i] > pivot ) {
      greaterArray.push(array[i]);
    } else {
      lesserArray.push(array[i]);
    }
  }

  return quickSortBasic(lesserArray).concat(pivot, quickSortBasic(greaterArray));
}

/******************* Testing Quick sort algorithm *********************/

// Returns a random integer between min (inclusive) and max (inclusive). Using Math.round() will give a non-uniform distribution, which we dont want in this case.

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
// By adding 1, I am making the maximum inclusive ( the minimum is inclusive anyway). Because, the Math.random() function returns a floating-point, pseudo-random number in the range from 0 inclusive up to but not including 1
}

var arr = [];

for (var i = 0; i < 10; i++) { //initialize a random integer unsorted array
  arr.push(getRandomInt(1, 100));
}

console.log("Unsorted array: ");
console.log(arr); //printing unsorted array

arr = quickSortBasic(arr, 0, arr.length - 1);
console.log("Sorted array: ");
console.log(arr);

/* Output - 
  Unsorted array: 
[ 63, 95, 63, 26, 76, 19, 65, 8, 63, 26 ]
Sorted array: 
[ 8, 19, 26, 26, 63, 63, 63, 65, 76, 95 ]
[Finished in 0.1s]
*/
