//
//  ViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 17/3/21.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var number: UILabel!
    @IBOutlet weak var clickbutton: UIButton!
    @IBOutlet weak var restart: UIButton!
    @IBOutlet weak var control: UISegmentedControl!
    var counter = 0
    var choice = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        clickbutton.layer.cornerRadius=10
        restart.layer.cornerRadius=10
        choice = control.selectedSegmentIndex
        
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
        number.text = "\(counter)"
    }
    @IBAction func buttonPressed(_ sender: Any) {
        if (choice == 0){
            counter += 1
        }
        else if (choice == 1){
            counter += Int.random(in: -5...10)
        }
        //counter+=1
        number.text = "\(counter)"
        
    }
    
}

