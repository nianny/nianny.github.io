//
//  LogInViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 30/3/21.
//

import UIKit
import Firebase

class LogInViewController: UIViewController {
    @IBOutlet weak var emailLogin: UITextField!
//    @IBOutlet weak var passwordLogin: UIStackView!
    @IBOutlet weak var passwordLogin: UITextField!
    @IBOutlet weak var logInButton: UIButton!
    @IBOutlet weak var logInLabel: UILabel!
    @IBOutlet weak var returnHome: UIButton!
    
    var maximum = 0
    var uid = ""
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
        if let destination = segue.destination as? ViewController {
            destination.maximumScore = maximum
            print("YAY")
        }
    }

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        logInButton.layer.cornerRadius = 20
        logInLabel.isHidden = true
        logInButton.setTitleColor(.systemBackground, for: .normal)
        returnHome.layer.cornerRadius = 10
        returnHome.layer.borderColor = CGColor(gray: 0.7, alpha: 1)
        returnHome.layer.borderWidth = 2
        
        self.title = "Log in"
        
        

        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

    @IBAction func loginTapped(_ sender: Any) {
        
        //validate text fields
        
        //signing in the user
//        signIn()
        let email = emailLogin.text!.trimmingCharacters(in: .whitespacesAndNewlines)
        let password = passwordLogin.text!.trimmingCharacters(in: .whitespacesAndNewlines)
        Auth.auth().signIn(withEmail: email, password: password) { (result, error) in
            
            if error != nil {
                self.logInLabel.text = error!.localizedDescription
                self.logInLabel.isHidden = false
            } else {
                let db = Firestore.firestore()
                let docRef = db.collection("users").document(result!.user.uid)

                docRef.getDocument { (document, error) in
                    if let document = document, document.exists {
                        let dataDescription = document.data()!//.map(String.init(describing:)) ?? "nil"
                        let currentScore = dataDescription["high"] ?? 0
                        let UserID = dataDescription["uid"] ?? "0"
                        self.maximum = (currentScore as! Int)
                        self.uid = UserID as! String
//                        print(type(of: dataDescription))
//                        print(self.maximum)
//                        print("Document data: \(dataDescription)")
//                        let homeViewController = self.storyboard?.instantiateViewController(identifier: Constants.Storyboard.homeViewController) as? ViewController
//                //
//                        self.view.window?.rootViewController = homeViewController
//                        self.view.window?.makeKeyAndVisible()
                        
                        let sb = UIStoryboard(name: "Main", bundle: nil)
                        if let secondVC = sb.instantiateViewController(identifier: "HomeVC") as? ViewController {
                            self.present(secondVC, animated: true, completion: nil)
                            secondVC.maximumScore = self.maximum
                            secondVC.uid = self.uid
                        }
                    } else {
                        print("Document does not exist")
                    }
                }
            }
        }
        
        
    }
    @IBAction func backHome(_ sender: Any) {
        let sb = UIStoryboard(name: "Main", bundle: nil)
        if let secondVC = sb.instantiateViewController(identifier: "choosingVC") as? HomeViewController {
            self.present(secondVC, animated: true, completion: nil)
        }
    }
    func signIn(){
        
    }
}
