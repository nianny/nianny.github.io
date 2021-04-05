//
//  ViewController.swift
//  Joke App
//
//  Created by Xiao Nianhe on 4/4/21.
//

import UIKit

class ViewController: UIViewController {
    var currentJoke = 0
    var setups = ["Why did the chicken cross the road?", "Why couldn't the bicycle stand up?", "Is this pool safe for diving?"]
    var punchlines = ["To get to the other side!", "It was two tired!", "It deep ends"]
    
    


    @IBOutlet weak var noIdea: UIButton!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var answerLabel: UILabel!
    @IBOutlet weak var continueLabel: UILabel!
    @IBOutlet var tapButton: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        noIdea.layer.cornerRadius = 10
        setJoke()
        getData()
    }
    @IBAction func answerRequested(_ sender: Any) {
//        answerLabel.isHidden = false
//        continueLabel.isHidden = false
//        tapButton.isEnabled = true
//        noIdea.isEnabled = false
        getData()
    }
    
    @IBAction func screenTapped(_ sender: Any) {
        currentJoke += 1
        if currentJoke == setups.count{
            currentJoke = 0
        }
        getData()

        setJoke()
    }
    
    func setJoke(){
        tapButton.isEnabled = false
        noIdea.isEnabled = true
        answerLabel.isHidden = true
        continueLabel.isHidden = true
        questionLabel.text = setups[currentJoke]
        answerLabel.text = punchlines[currentJoke]
    }
    
    func newJoke(){
        
    }
    
    func getData (){
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
                print(joke.joke)
            } else{
                print("Fail")
            }
        }

        task.resume()
    }
}
    


struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}

