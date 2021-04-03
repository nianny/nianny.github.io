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
    @IBOutlet weak var leaderboardButton: UIButton!
    @IBOutlet weak var shopButton: UIButton!
    @IBOutlet weak var swiftLogo: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
//        overrideUserInterfaceStyle = .dark
        if self.traitCollection.userInterfaceStyle == .dark {
//            swiftLogo.tintColor = UIColor.white
            // User Interface is Dark
            
        } else {
//            swiftLogo.tintColor = UIColor.black
        }

        
        
        
        setUp()
//        hi.isHidden = true
        
        
       
        // Do any additional setup after loading the view.
    }
    
    func setUp(){
        leaderboardButton.layer.cornerRadius = 10
        shopButton.layer.cornerRadius = 10
        signUpButton.layer.cornerRadius = 20
        logInButton.layer.cornerRadius = 20
        logInButton.layer.borderWidth = 2
            
        
            
//        signUpButton.layer.borderWidth = 2
        logInButton.layer.borderColor = UIColor.systemGray.cgColor
//        signUpButton.layer.borderColor = CGColor(gray: 1, alpha: 1)
//        signUpButton.layer.backgroundColor = CGColor(gray: 0.2, alpha: 1)
//        signUpButton.setTitleColor(<#T##color: UIColor?##UIColor?#>, for: <#T##UIControl.State#>)
//        signUpButton.setTitleColor(.white, for: .normal)
//        logInButton.setTitleColor(.white, for: .normal)

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
