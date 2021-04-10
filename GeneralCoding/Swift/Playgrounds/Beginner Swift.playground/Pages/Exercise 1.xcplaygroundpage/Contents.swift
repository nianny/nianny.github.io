//: [Previous](@previous)
import UIKit
var str = "Hello, playground"

//: [Next](@next)
var array = [1, 2, 3, 4, 3, 5, 6, 7, 8, 9, 10]
array.remove(at: 4) //fifth element -> 4th index
array += [11, 12, 13, 14]
array = [-3,-2,-1] + array
array.insert(0, at: 3)
print(array)

