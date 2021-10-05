//Bubble Sort algorithm for Swift
//Enter any array in the line 5

import UIKit

var arr:[Int] = [64, 34, 25, 12, 22, 11, 90]
var n = arr.count
var swap = true
while swap == true {
    swap = false
    for i in 0 ..< n-1 {
        if arr[i] > arr[i + 1] {
            let temp = arr [i + 1]
            arr [i + 1] = arr[i]
            arr[i] = temp
            swap = true
        }
    }
}

print (arr)

