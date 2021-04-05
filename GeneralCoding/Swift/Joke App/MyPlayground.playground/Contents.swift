import UIKit
import PlaygroundSupport
PlaygroundPage.current.needsIndefiniteExecution = true

var str = "Hello, playground"
let url = URL(string: "https://icanhazdadjoke.com/")!
var request = URLRequest(url: url)
request.httpMethod = "GET"
request.setValue("application/json", forHTTPHeaderField:"Accept")
let task = URLSession.shared.dataTask(with: request) {(data, response, error) in
    guard let data = data else { return }
//    print(String(data: data, encoding: .utf8)!)
    var result: Response?
    do {
        result = try JSONDecoder().decode(Response.self, from: data)
    }
    catch {
        print("Fail")
    }
    if let joke = result {
        print(joke.joke)
    } else{
        print("Fail")
    }
//    print(result?.joke)
    
}

task.resume()


struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}


