//HELPER FUNCTION
var swap = function(array, firstIndex, secondIndex){
    var temp = array[firstIndex];
    array[firstIndex]  = array[secondIndex];
    array[secondIndex] = temp;
};
var array = [2,1];
swap(array, 0, 1)
console.log('swap should return [1,2] -->', array);


var selectionSort = function(array){
  for(var i = 0; i < array.length; i++){
    //set min to the current iteration of i
    var min = i;
    for(var j = i+1; j < array.length; j++){
      if(array[j] < array[min]){
        min = j;
      }
    }
    swap(array, i, min);
  }
  return array;
};
var array = [3,2,10,1]
