//
//  ViewController.swift
//  Joke App
//
//  Created by Xiao Nianhe on 4/4/21.
//

import UIKit

class ViewController: UIViewController {
    var currentJoke = 0
    var choice = true
    
    


    @IBOutlet weak var noIdea: UIButton!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var answerLabel: UILabel!
    @IBOutlet weak var continueLabel: UILabel!
    @IBOutlet var tapButton: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        noIdea.layer.cornerRadius = 10
        tapButton.isEnabled = false
        answerLabel.isHidden = true
        continueLabel.isHidden = true
        getData()
    }
    @IBAction func answerRequested(_ sender: Any) {
        if choice {
            answerLabel.isHidden = false
    //        continueLabel.isHidden = false
            noIdea.setTitle("Tap for new", for: .normal)
            choice = false
        }
        else {
            getData()
        }
        
        
//        getData()
    }
    
    @IBAction func screenTapped(_ sender: Any) {
        getData()
    }
    
    func setJoke(){
        tapButton.isEnabled = false
        noIdea.isEnabled = true
        answerLabel.isHidden = true
        continueLabel.isHidden = true
    }
    
    func newJoke(){
        
    }
    
    func getData (){
        var value = [String]()
        let url = URL(string: "https://icanhazdadjoke.com/")!
        var request = URLRequest(url: url)
        request.httpMethod = "GET"
        request.setValue("application/json", forHTTPHeaderField:"Accept")
        let task = URLSession.shared.dataTask(with: request) {(data, response, error) in
            guard let data = data else { return }
            var result: Response?
            do {
                result = try JSONDecoder().decode(Response.self, from: data)
            }
            catch {
                print("Fail")
            }
            if let joke = result {
                var joky = joke.joke
                if joky.count > 100 {
                    DispatchQueue.main.async {
                        self.getData()
                    }
                    return
                }
                joky = joky.trimmingCharacters(in: .whitespacesAndNewlines)
//                print(joky)
                if joky.contains("?"){
                    var arr = joky.split(separator: "?")
                    arr[0] = arr[0]+"?"
                    arr[1] = Substring(arr[1].trimmingCharacters(in: .whitespaces))
                    value.append(String(arr[0]))
                    value.append(String(arr[1]))
                    print(arr)
                    DispatchQueue.main.async {
                        self.questionLabel.text = String(arr[0])
                        self.answerLabel.text = String(arr[1])
                        self.tapButton.isEnabled = false
                        self.noIdea.isEnabled = true
                        self.answerLabel.isHidden = true
                        self.noIdea.setTitle("No idea :o", for: .normal)
                        self.choice = true
                    }
                    
                }
                else {
//                    joky += "."
                    print(joky)
//                    self.setQuestion(label: joky)
//                    self.tapButton.isEnabled = true
                    value.append(joky)
                    DispatchQueue.main.async {
                        self.questionLabel.text = joky
                        self.noIdea.isEnabled = true
//                        self.tapButton.isEnabled = true
                        self.answerLabel.isHidden = true
                        self.noIdea.setTitle("Tap for new", for: .normal)
                        self.choice = false
                    }
                    
//                    return value
//                    return value
                }
            }
        }

        task.resume()
//        return value
//        return value
    }
    
    func setQuestion(label: String){
        questionLabel.text = label
    }
}
    


struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}

