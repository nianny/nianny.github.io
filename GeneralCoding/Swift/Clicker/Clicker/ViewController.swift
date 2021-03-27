//
//  ViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 17/3/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var gu: UIView!
    @IBOutlet weak var number: UILabel!
    @IBOutlet weak var clickbutton: UIButton!
    @IBOutlet weak var restart: UIButton!
    @IBOutlet weak var control: UISegmentedControl!
    @IBOutlet weak var congratsLabel: UILabel!
    var counter = 0
    var choice = 0
    var maximum = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        clickbutton.layer.cornerRadius=10
        restart.layer.cornerRadius=10
        choice = control.selectedSegmentIndex
        congratsLabel.isHidden = true
        checkValue()
        
        // Do any additional setup after loading the view.
    }

//    @IBAction func choose(_ sender: Any) {
//        choice = control.selectedSegmentIndex
//    }
    @IBAction func control(_ sender: Any) {
        choice = control.selectedSegmentIndex
    }
    @IBAction func restart(_ sender: Any) {
        counter = 0
        number.text = "You pressed \(counter) times"
        maximum = 0
        checkValue()
        
        self.number.alpha = 1
    }
    @IBAction func buttonPressed(_ sender: Any) {

        
        UIView.animate(withDuration: 1.5) {
//            self.number.alpha = 0.2
//            self.view.backgroundColor = .red

//            self.number.transform = self.number.transform.rotated(by: .pi/2)
        } completion: { (_) in
            UIView.animate(withDuration: 1.5){
                self.view.backgroundColor = .white
                self.number.transform = .identity
            }
        }


//        UIView.animate(withDuration: 3.0){
//            self.number.alpha = 1
//        }
//        UIView.animate(withDuration: 3.0) {
//            self.number.alpha = 0
//        }
        if choice == 0 || choice == 1{
            
        
            if (choice == 0){
                counter += 1
            }
            else if (choice == 1){
                counter += Int.random(in: -5...10)
            }
            number.text = "You pressed \(counter) times"
            maximum = max(maximum, counter)
            if choice == 0 || choice == 1{
                checkValue()
            }
        }
        
        
    }
    func checkValue(){
        if maximum >= 20 && maximum <= 25{
            congratsLabel.isHidden = false
            congratsLabel.text = "Come on!!!"
        }
        else if maximum == 0{
            congratsLabel.isHidden = false
            congratsLabel.text = "Lets start!"
        }
        else if maximum >= -5 && maximum <= 5{
            congratsLabel.isHidden = false
            congratsLabel.text = "Good luck :)"
        }
        else if maximum >= 50 && maximum<=55{
            congratsLabel.isHidden = false
            congratsLabel.text = "Halfway there..."
        }
        else if maximum >= 100{
            congratsLabel.isHidden = false
            congratsLabel.text = "Yay! You did it :D"
        }
        else if maximum >= 1000{
            congratsLabel.isHidden = false
            congratsLabel.text = "Woah! You're a legend :o"
        }
        else {
            congratsLabel.isHidden = true
        }
    }
    
}

