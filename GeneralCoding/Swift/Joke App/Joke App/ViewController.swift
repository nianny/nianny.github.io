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
        // Do any additional setup after loading the view.
    }
    @IBAction func answerRequested(_ sender: Any) {
        answerLabel.isHidden = false
        continueLabel.isHidden = false
        tapButton.isEnabled = true
        noIdea.isEnabled = false
    }
    
    @IBAction func screenTapped(_ sender: Any) {
        currentJoke += 1
        if currentJoke == setups.count{
            currentJoke = 0
        }
        
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
    
}

