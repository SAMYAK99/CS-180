// Program to remove duplicate values from a list of values.
// Example:
// Input: [4,3,5,5,4,5,6,7,8,4]
// Output: [4, 3, 5, 6, 7, 8]

const duplicateRemover=(inputArr)=>{
    let dict = {}
    let nonDups = []
    inputArr.forEach(element => {
        if(!dict[element]){
            nonDups.push(element); 
            dict[element] = true;
        }
    });

    return nonDups;
}

const inpArr = [4,3,5,5,4,5,6,7,8,4]
console.log(duplicateRemover(inpArr));