// pet doggo
struct Doggo {
    var name: String
    var breed: String
    var age: Int
    var weight: Double
    var length: Double
    var hobbies: [String]
    
    func doSomething() -> String {
        var str = ""
        str = "\(name) is \(hobbies[Int.random(in: 0..<hobbies.count)]) :D"
        print(str)
        return str
    }
    
    func calculateBMI() -> Double {
        var bmi = 0.0
        bmi = weight/(length*length)
//        print("\(name) has a bmi of \(bmi)!")
        if bmi > 27 {
            print("\(name) is overweight with a bmi of \(bmi) :o")
        }
        else if bmi < 15{
            print("\(name) is underweight with a bmi of \(bmi) :(")
        }
        else {
            print("Yay! \(name) has an accpetable bmi of \(bmi) :)")
        }
        return bmi
    }
    
    func feed () {
        // useless function
        print("You have fed \(name) and it is full again :D")
    }
}

var superDoggo = Doggo(name: "Hallo", breed: "Rainbow Retriever", age: 101, weight: 30, length: 1, hobbies: ["dancing", "singing", "jumping around"])
superDoggo.doSomething()
superDoggo.calculateBMI()
superDoggo.feed()

class YJ{
    
}
