//var width = 20
//var height = 40
//var x = 5
//var y = 6
//
//var result = width*y + height*x - x*y

func lshapeSize(forWidth width: Int, height: Int, x:Int, and y: Int) ->Int{
    return (width*y + height*x - x*y)
}
print(lshapeSize(forWidth: 20, height: 40, x: 5, and: 6))
