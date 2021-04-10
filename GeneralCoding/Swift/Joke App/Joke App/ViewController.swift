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
    var nextJoke: String = ""
    var nextPunch: String? = nil
    
    


    @IBOutlet weak var noIdea: UIButton!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var answerLabel: UILabel!
    @IBOutlet weak var continueLabel: UILabel!
    @IBOutlet var tapButton: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        getData(first: true)
//        questionLabel.text = nextJoke;
//        if let punch = nextPunch{
//            answerLabel.text = punch
//        }
        getData(first: false)
        noIdea.layer.cornerRadius = 10
        tapButton.isEnabled = false
        answerLabel.alpha = 0
        continueLabel.isHidden = true
        
    }
    @IBAction func answerRequested(_ sender: Any) {
        if noIdea.currentTitle == "No idea :o" {
//            answerLabel.isHidden = false
    //        continueLabel.isHidden = false
            UIView.animate(withDuration: 0.2) {
                self.answerLabel.alpha = 1
            }
            noIdea.setTitle("Tap for new", for: .normal)
        }
        
        else if noIdea.currentTitle == "Tap for new"{
            answerLabel.alpha = 0
            questionLabel.text = nextJoke;
            if let punch = nextPunch{
                answerLabel.text = punch
                noIdea.setTitle("No idea :o", for: .normal)
            }
            else {
                self.noIdea.setTitle("Tap for new", for: .normal)
            }
            getData(first: false)
        }
        
        
        
//        getData()
    }
    
//    @IBAction func screenTapped(_ sender: Any) {
//        getData(first: false)
//    }
    
    func setJoke(){
        tapButton.isEnabled = false
        noIdea.isEnabled = true
        answerLabel.alpha = 0
        continueLabel.isHidden = true
    }
    
    func newJoke(){
        
    }
    
    func getData (first: Bool){
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
                        self.getData(first: first)
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
//                        self.questionLabel.text = String(arr[0])
//                        self.answerLabel.text = String(arr[1])
                        self.nextJoke = String(arr[0])
                        self.nextPunch = String(arr[1])
//                        self.tapButton.isEnabled = false
//                        self.noIdea.isEnabled = true
//                        self.answerLabel.alpha = 0
//                        self.noIdea.setTitle("No idea :o", for: .normal)
//                        self.choice = true
                        if first{
                            self.questionLabel.text = self.nextJoke;
                            if let punch = self.nextPunch{
                                self.answerLabel.text = punch
                                self.noIdea.setTitle("No idea :o", for: .normal)
                            }
                            else {
                                self.noIdea.setTitle("Tap for new", for: .normal)
                            }
                        }
                    }
                    
                }
                else {
//                    joky += "."
                    print(joky)
//                    self.setQuestion(label: joky)
//                    self.tapButton.isEnabled = true
                    value.append(joky)
                    DispatchQueue.main.async {
                        self.nextJoke = joky
                        self.nextPunch = nil
//                        self.questionLabel.text = joky
//                        self.noIdea.isEnabled = true
////                        self.tapButton.isEnabled = true
//                        self.answerLabel.alpha = 0
//                        self.noIdea.setTitle("Tap for new", for: .normal)
//                        self.choice = false
                        if first {
                            self.questionLabel.text = self.nextJoke;
                            if let punch = self.nextPunch{
                                self.answerLabel.text = punch
                                self.noIdea.setTitle("No idea :o", for: .normal)
                            }
                            else {
                                self.noIdea.setTitle("Tap for new", for: .normal)
                            }
                        }
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

