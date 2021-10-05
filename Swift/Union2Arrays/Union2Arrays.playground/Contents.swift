import UIKit


var arrayOne:[Int] = [1, 2, 4, 5, 6]
var arrayTwo:[Int] = [2, 3, 5, 7]

let m:Int = arrayOne.count //5
let n:Int = arrayTwo.count //4
var i = 0 // 1, 2, 3, 4, 5
var j = 0 // 1, 2, 3
// 1, 2, 2, 3, 4, 5, 5, 6,

func printUnion(_ arrayOne:[Int], _ arrayTwo:[Int], _ m:Int, _ n:Int) {

    while ( i < m && j < n) {
        if (arrayOne[i] <= arrayTwo[j]) {
            print(arrayOne[i])
            i += 1
        }
        else {
            print(arrayTwo[j])
            j += 1
        }
    }
    
    
    while i < m {
        print(arrayOne[i])
           i += 1
    }
    
    while j < n {
        print(arrayTwo[j])
        j += 1
    }
    
}

printUnion(arrayOne, arrayTwo, m, n)
