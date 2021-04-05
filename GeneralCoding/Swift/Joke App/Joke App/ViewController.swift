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
    let url = "icanhazdadjoke.com"

    @IBOutlet weak var noIdea: UIButton!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var answerLabel: UILabel!
    @IBOutlet weak var continueLabel: UILabel!
    @IBOutlet var tapButton: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        print("Hi first")
        super.viewDidLoad()
//        noIdea.layer.cornerRadius = 10
//        setJoke()
        getData(from: url)
        print("Hi")
        // Do any additional setup after loading the view.
    }
    @IBAction func answerRequested(_ sender: Any) {
//        answerLabel.isHidden = false
//        continueLabel.isHidden = false
//        tapButton.isEnabled = true
//        noIdea.isEnabled = false
    }
    
    @IBAction func screenTapped(_ sender: Any) {
//        currentJoke += 1
//        if currentJoke == setups.count{
//            currentJoke = 0
//        }
//
//        setJoke()
    }
    
    func setJoke(){
//        tapButton.isEnabled = false
//        noIdea.isEnabled = true
//        answerLabel.isHidden = true
//        continueLabel.isHidden = true
//        questionLabel.text = setups[currentJoke]
//        answerLabel.text = punchlines[currentJoke]
    }
    
    func newJoke(){
        
    }
    
    func getData (from url: String){
        URLSession.shared.dataTask(with: URL(string: url)!) { (data, response, error) in
            print("hi 3")
            guard let data = data, error == nil else {
                print("Something went wrong")
                return
            }
            
            //have data
            var result: Response?
            do {
                result = try JSONDecoder().decode(Response.self, from: data)
            }
            catch {
                print("Failed to convert \(error.localizedDescription)")
            }
            
            guard let json = result else {
                return
            }
            print(json.joke)
        }
    }
}
    


struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}

