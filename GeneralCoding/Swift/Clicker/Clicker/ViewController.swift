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
    var counter = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        clickbutton.layer.cornerRadius=10
        // Do any additional setup after loading the view.
    }

    @IBAction func buttonPressed(_ sender: Any) {
        counter+=1
        number.text = "\(counter)"
        
    }
    
}

