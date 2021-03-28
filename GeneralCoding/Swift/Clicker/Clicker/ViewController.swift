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
    @IBOutlet weak var maxScore: UILabel!
    @IBOutlet weak var restart: UIButton!
    @IBOutlet weak var control: UISegmentedControl!
    @IBOutlet weak var congratsLabel: UILabel!
    @IBOutlet weak var timer: UILabel!
    @IBOutlet weak var speedLabel: UILabel!
    @IBOutlet weak var pause: UIButton!
    var counter = 0.0
    var choice = 0
    var maximum = 0
    var time: Timer?
    var timeElapsed = 0.0
    var end = false
    let maxNum = 150
    var maximumScore = 0
    var speed = 0.0
    var pauseBool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        pause.layer.cornerRadius = 10
//        pause.setTitle("", for: .disabled)
        pause.isHidden = true
        clickbutton.layer.cornerRadius = 10
        restart.layer.cornerRadius = 10
        maxScore.clipsToBounds = true
        maxScore.layer.cornerRadius = 10
        choice = control.selectedSegmentIndex
        congratsLabel.isHidden = true
        checkValue()
        speedLabel.text = "Speed: \(speed)"
        speedLabel.isHidden = true
        time = Timer.scheduledTimer(timeInterval: 0.1, target: self, selector: #selector(updateCounter), userInfo: nil, repeats: true)
        
        // Do any additional setup after loading the view.
//        timer.isHidden = true;
        timer.text = "\(timeElapsed)"
        
        maxScore.text = "Max: \(maximumScore)"
    }
    
    @objc func updateCounter() {
        if pauseBool {
            pause.setTitle("Continue", for: .normal)
        }
        else if !pauseBool{
            pause.setTitle("Pause", for: .normal)
        }
        if counter == 1{
            pause.isHidden = false
            pause.setTitle("Pause", for: .disabled)
        }
        if (counter != 0 && !end && !pauseBool){
            speedLabel.isHidden = false
            speed = counter/timeElapsed
            speedLabel.text = "Speed: \(round(speed*100)/100) clicks/s."
            timeElapsed += 0.1
            timer.text = "\(round(timeElapsed*100)/100) seconds"
        }
        
        if (counter == 60 && choice == 2){
            congratsLabel.isHidden = false
            clickbutton.isEnabled = false
            clickbutton.setTitle("Finished", for: .disabled)
            
            congratsLabel.text = "Woah! You're a legend :o"
            end = true
            counter = Double(maxNum)
            number.text = "You pressed \(counter) times"
            timer.isHidden = true
        }
            
    }
    
    

//    @IBAction func choose(_ sender: Any) {
//        choice = control.selectedSegmentIndex
//    }
    @IBAction func control(_ sender: Any) {
        choice = control.selectedSegmentIndex
    }
    @IBAction func restart(_ sender: Any) {
        maximumScore = max(maximumScore, Int(counter))
        maxScore.text = "Max: \(maximumScore)"
        counter = 0
        number.text = "You pressed \(Int(counter)) times"
        maximum = 0
        checkValue()
        
        self.number.alpha = 1
        clickbutton.isEnabled = true
        clickbutton.setTitle("CLICK ME", for: .disabled)
        timeElapsed = 0
        timer.text = "\(timeElapsed)"
        end = false
        timer.isHidden = false
        speedLabel.isHidden = true
        self.congratsLabel.transform = .identity
    }
    @IBAction func buttonPressed(_ sender: Any) {
        if pauseBool{
            pauseBool = false
        }
        
        UIView.animate(withDuration: 0.1) {
//            self.number.alpha = 0.2
//            self.view.backgroundColor = .red

//            self.number.transform = self.number.transform.rotated(by: .pi/2)
//            self.clickbutton.transform = self.clickbutton.transform.scaledBy(x: 1.01,y: 1.01)
        } completion: { (_) in
            UIView.animate(withDuration: 0.1){
                self.view.backgroundColor = .white
                self.number.transform = .identity
                self.clickbutton.transform = .identity
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
                counter += Double(Int.random(in: -5...10))
            }
            number.text = "You pressed \(Int(counter)) times"
            maximum = max(maximum, Int(counter))
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
            congratsLabel.text = "Lets start! (Click to start)"
        }
        else if maximum >= -5 && maximum <= 5{
            congratsLabel.isHidden = false
            congratsLabel.text = "Good luck :)"
        }
        else if maximum >= 50 && maximum<=55{
            congratsLabel.isHidden = false
            congratsLabel.text = "Halfway there..."
        }
        else if maximum >= 100 && maximum <= 150{
            congratsLabel.isHidden = false
            congratsLabel.text = "Yay! You did it :D"
        }
        else if maximum >= maxNum{
            congratsLabel.isHidden = false
            clickbutton.isEnabled = false
            clickbutton.setTitle("Finished", for: .disabled)
            
            congratsLabel.text = "Wow! You're a legend :o"
            UIView.animate(withDuration: 2) {
                self.congratsLabel.transform = self.congratsLabel.transform.scaledBy(x: 1.5, y: 1.5)
            }
            end = true
            counter = Double(maxNum)
            number.text = "You pressed \(maxNum) times"
            timer.isHidden = true
            maximumScore = max(maximumScore, Int(counter))
            maxScore.text = "Max: \(maximumScore)"
        }
        else {
            congratsLabel.isHidden = true
        }
    }
    @IBAction func pauseClicked(_ sender: Any) {
        maximumScore = max(maximumScore, Int(counter))
        maxScore.text = "Max: \(maximumScore)"
        pauseBool = !pauseBool
        
    }
    
}

