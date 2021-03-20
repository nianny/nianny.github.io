//: [Previous](@previous)

import Foundation

var str = "Hello, playground"

//: [Next](@next)

let test = 10 / 20 //0?!?!?!?
//integer division -> integer/integer = integer

//casting
Double(10)/Double(20)
//Double(10) / Int(20)
//this doesnt work, because you cant divide different types apparently

let test1 = 5 / 2
let test2 = 5.0 / 2
let test3 = 5 / 2.0


//lets say you have 10 macbooks and 10 ipads
var numMacBooks = 10
var numIPads = 10

//one macbooks died :(((
numMacBooks = numMacBooks - 1

//your ipads reproduced! Somehow.
numIPads = numIPads * 2

//total equiptment now???
var total = numIPads + numMacBooks

// TODO: What if someone eats an iPad
numIPads -= 1


// TODO: What is the total equipment now? Recalculate it
total = numIPads + numMacBooks
