import UIKit
import PlaygroundSupport
PlaygroundPage.current.needsIndefiniteExecution = true

//var str = "Hello, playground"
//let url = URL(string: "https://icanhazdadjoke.com/")!
//var request = URLRequest(url: url)
//request.httpMethod = "GET"
//request.setValue("application/json", forHTTPHeaderField:"Accept")
//let task = URLSession.shared.dataTask(with: request) {(data, response, error) in
//    guard let data = data else { return }
////    print(String(data: data, encoding: .utf8)!)
//    var result: Response?
//    do {
//        result = try JSONDecoder().decode(Response.self, from: data)
//    }
//    catch {
//        print("Fail")
//    }
//    if let joke = result {
//        print(joke.joke)
//        print(type(of: joke.joke))
//        print(joke.id)
//        print(type(of: joke.id))
//    } else{
//        print("Fail")
//    }
////    print(result?.joke)
//
//}
//
//task.resume()
//
//

let url = URL(string: "https://icanhazdadjoke.com/")
var request = URLRequest(url: url!)
request.httpMethod = "GET"
request.setValue("application/json", forHTTPHeaderField: "Accept")
        
let task = URLSession.shared.dataTask(with: request, completionHandler: { data, response, error in
    guard let data = data, error == nil else{
        print("Something went wrong")
        return
    }
            
    //converting data
    var result: Response?
    do{
        result = try JSONDecoder().decode(Response.self, from: data)
    } catch {
        print("failed to convert")
        print(data)
    }
            
    if let json = result{
        print("hm")
        print(json.status)
        print(json.joke)
        print(json.id)
    } else{
        return
    }
            

})
task.resume()

struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}


//let string = "The rain in Spain? HAHA."
//let stringResult = string.contains("?")
//var arr = string.split(separator: "?")
//arr[0] = arr[0]+"?"
//arr[1] = Substring(arr[1].trimmingCharacters(in: .whitespaces))
//print(arr)


