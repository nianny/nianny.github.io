import Foundation
func calculateBMI(weight: Double, height: Double) -> Double{
    var BMI = weight / (height*height)
    BMI = round(100*BMI)/100
    if BMI < 17.5{
        print("Underweight: Only \(BMI)!")
    }
    else if BMI >= 17.5 && BMI <= 22.5{
        print("Healthy, good BMI of \(BMI) :D")
    }
    else if (BMI > 17.5){
        print("Overweight, stop drinking so much hot chocolate :o")
        print("Your BMI is already \(BMI)!!!")
    }
//    print(BMI)
    return BMI
}

calculateBMI(weight: 71.5, height: 1.71)
