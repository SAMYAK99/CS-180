//reads two arrays and prints the merge between them.
//to avoid printing duplicated elements, uncomment lines 22-24

import UIKit

var arrayOne:[Int] = [1, 2, 4, 5, 6]
var arrayTwo:[Int] = [2, 3, 5, 7]

let m:Int = arrayOne.count
let n:Int = arrayTwo.count
var i = 0
var j = 0


func printUnion(_ arrayOne:[Int], _ arrayTwo:[Int], _ m:Int, _ n:Int) {

    while ( i < m && j < n) {
        if (arrayOne[i] <= arrayTwo[j]) {
            print(arrayOne[i])
            
// uncomment the three lines below to avoid printing identical elements
//                if (arrayOne[i] == arrayTwo[j]) {
//                    j += 1
//                }
            
            i += 1
        }
        else {
            print(arrayTwo[j])
            if (arrayOne[i] == arrayTwo[j]) {
                j += 1
            }
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



