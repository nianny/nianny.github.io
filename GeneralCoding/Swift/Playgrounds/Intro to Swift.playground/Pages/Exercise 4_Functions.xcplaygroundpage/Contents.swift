//: [Previous](@previous)

import Foundation

var str = "Hello, playground"

//: [Next](@next)

func printIntroductions(){ //definining/writing the function
    print("Hello my name is YJ")
    print("My hobby is sleeping")
    print("My favourite programming language is swift")
}

printIntroductions() //runs everything inside the function
//known as "calling the functyion"


func printIntroductionWithName(name: String){ //includes function parameter
    print("Hello my name is \(name)")
    print("My hobby is sleeping")
    print("My favourite programming language is swift")
}

printIntroductionWithName(name: "Jiachen")

func printIntroductionWithHobbyFor(name: String, hobby: String){
    print("Hello my name is \(name)")
    print("My hobby is \(hobby)")
    print("My favourite programming language is swift")
}

printIntroductionWithHobbyFor(name: "Jiachen", hobby: "eating mcdonalds")

func printIntroduction(for name: String, withHobby hobby: String){
    print("Hello my name is \(name)")
    print("My hobby is \(hobby)")
    print("My favourite programming language is swift")
}
/* Format:
 External name: for, withHobbt
 Intewrnal name: name, hobby
 
 */


//this is what i'd prefer
printIntroduction(for: "Jia Chen", withHobby: "eating macdonalds")




//'_' only applies for first parameter
func introduce(_ name: String, withHobby hobby: String){
    print("Hello my name is \(name)")
    print("My hobby is \(hobby)")
    print("My favourite programming language is swift")
}



//this is what i'd prefer
introduce("Jia Chen", withHobby: "eating macdonalds")


//parameters (during definition), argument (when using)
























//exercise 4
func twoNumberStory(first: Int, second: Int){
    print("I went to buy some nutella from TinkerCademy. I thought it would cost \(first) dollars, but it ended up costing \(second) dollars :o")
    print("Interesting...")
}


twoNumberStory(first:10, second:2)



print("\n \n \n \n")



var hello: Any = "hello"
hello = 5

//
//var a = 1
//var b = 2.45
//var total = a + b
print("\n \n")
