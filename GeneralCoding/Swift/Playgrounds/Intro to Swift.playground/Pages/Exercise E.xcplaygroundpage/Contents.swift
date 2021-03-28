func calculateBMI(weight: Double, height: Double) -> Double{
    let BMI = weight / (height*height)
    print(BMI)
    return BMI
}

calculateBMI(weight: 71.5, height: 1.71)
