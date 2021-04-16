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
car.describe()
