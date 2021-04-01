//
//  HomeViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 30/3/21.
//

import UIKit
import Firebase

class HomeViewController: UIViewController {
    @IBOutlet weak var signUpButton: UIButton!
    @IBOutlet weak var logInButton: UIButton!
    @IBOutlet weak var hi: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setUp()
        hi.isHidden = true
        
        
       
        // Do any additional setup after loading the view.
    }
    
    func setUp(){
        signUpButton.layer.cornerRadius = 20
        logInButton.layer.cornerRadius = 20
        logInButton.layer.borderWidth = 2
        logInButton.layer.borderColor = CGColor(gray: 0, alpha: 1)

    }
    
    
    @IBAction func printData(_ sender: Any) {
//        let db = Firestore.firestore()
//        let score = db.collection("users")
//        let scores = score.order(by: "high", descending: true)
//        scores.getDocuments { (data, err) in
//            if err != nil{
//                print("Error: \(err)")
//            }
//            else {
//                print(type(of: scores))
//                print(type(of: data))
//                for documents in  data!.documents {
//                    print(documents.data())
//                    print(type(of: documents.data()))
//                    let daMap = documents.data()
//                    let score = daMap["high"] as! Int
//                    let name = daMap["firstname"] as! String
//
//                    print("Score of \(name) is \(score).")
//                }
//                print(documents)
//                print(type(of: documents))
//            }
//        }
        
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
