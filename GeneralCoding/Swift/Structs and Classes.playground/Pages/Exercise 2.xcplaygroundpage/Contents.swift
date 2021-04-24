import UIKit

var str = "Hello, playground"
let words = ["magnificent", "horrible", "disgusting", "cool", "amazing"]
struct Car {
    var colour: String
    var make: String
    var model: String
    var topSpeed: Int
    var maxFuel: Double
    var fuelLeft: Double
    
    func honky(){
        print("BOOOOOONK!")
    }
    
    func stillGotFuel() -> Bool {
        if fuelLeft >= 1.0{
            return true
        }
        else {
            return false
        }
    }
    
    func describe() -> String {
        let str = "This \(words[Int.random(in: 0...3)]) car is a \(self.colour) \(self.make) \(self.model) with a top speed of \(self.topSpeed) km/h."
        print(str)
        return str
    }
}

var car = Car(colour: "red", make: "Tesla", model: "Model X", topSpeed: 200, maxFuel: 50.0, fuelLeft: 40.0)
//car.describe()


func compare(car1: Car, car2: Car) -> String {
    let v1 = car1.topSpeed
    let v2 = car2.topSpeed
    var str = ""
    if (v1 > v2){
        str = "The \(car1.model) is faster than the \(car2.model) by \(v1-v2) km/h."
    }
    else if (v2 > v1){
        str = "The \(car2.model) is faster than the \(car1.model) by \(v2 - v1) km/h."
    }
    else {
        str = "The \(car2.model) and the \(car1.model) have the same top speed!"
    }
    
    
    print(str)
    return str
}

var spacecar = Car(colour: "rainbow", make: "Nasa", model: "spaceCar1", topSpeed: 100000000000000000, maxFuel: 50.0, fuelLeft: 40.0)

compare(car1: car, car2: spacecar)
