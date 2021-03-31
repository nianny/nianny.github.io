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
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        logInButton.layer.cornerRadius = 20
        

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
                        let dataDescription = document.data().map(String.init(describing:)) ?? "nil"
                        
                        print("Document data: \(dataDescription)")
                    } else {
                        print("Document does not exist")
                    }
                }
                
                let homeViewController = self.storyboard?.instantiateViewController(identifier: Constants.Storyboard.homeViewController) as? ViewController
        //
                self.view.window?.rootViewController = homeViewController
                self.view.window?.makeKeyAndVisible()
            }
        }
        
        
    }
    func signIn(){
        
    }
}
