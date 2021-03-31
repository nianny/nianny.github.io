//
//  SignUpViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 30/3/21.
//

import UIKit
import Firebase
//import FirebaseAuth


class SignUpViewController: UIViewController {
    @IBOutlet weak var firstNameTextField: UITextField!
    @IBOutlet weak var lastNameTextField: UITextField!
    @IBOutlet weak var emailTextField: UITextField!
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet weak var signUpButton: UIButton!
    @IBOutlet weak var signUpLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setUp()
        signUpButton.layer.cornerRadius = 10

        // Do any additional setup after loading the view.
    }
    
    func setUp(){
        signUpLabel.isHidden = true
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    
    //check if fields and validate that data is correct
    func validateFields () -> String? {
        
        // check that all fields are filled in
        if firstNameTextField.text?.trimmingCharacters(in: .whitespacesAndNewlines) == ""  || lastNameTextField.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" || emailTextField.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" || passwordTextField.text?.trimmingCharacters(in: .whitespacesAndNewlines) == "" {
            return "Please fill in all fields."
        }
        
        //check if password is secure (not implemented)
        
        return nil //everything is fine
    }
    
    @IBAction func signUpTapped(_ sender: Any) {
        let error = validateFields()
        
        if error != nil {
            //there be error
            showError(error!)
            
        }
        else {
            //create cleaned versions of data
            let firstName = firstNameTextField.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            let lastName = lastNameTextField.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            let email = emailTextField.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            let password = passwordTextField.text!.trimmingCharacters(in: .whitespacesAndNewlines)
            
            Auth.auth().createUser(withEmail: email, password: password) { [self] (result, err) in
                
            
                
                //check for errors
                if err != nil {
                    //there was an error
                    showError("Error creating user")
                }
                else {
                    let db = Firestore.firestore()
                    db.collection("users").document(result!.user.uid).setData(["firstname": firstName, "lastname": lastName, "high": 0, "uid": result!.user.uid ]) { (error) in
                        if error != nil {
                            self.showError("Name unable to be saved")
                            print("Name unable to be saved")
                        }
                    }
                    
//                    (data: ["firstname": firstName, "lastname": lastName, "high": 0, "uid": result!.user.uid ]) { (error) in
//                        if error != nil {
//                            self.showError("Name unable to be saved")
//                            print("Name unable to be saved")
//                        }
//                    }
                    self.transitionToHome()
                    //user create succcessfully
                    //now store things
                }
            }
            //create user
            
            //transition to home screen
            
        }
        

    }
    
    func transitionToHome () {
        let homeViewController = storyboard?.instantiateViewController(identifier: Constants.Storyboard.homeViewController) as? ViewController
//
        view.window?.rootViewController = homeViewController
        view.window?.makeKeyAndVisible()
        
//        showError("Done")
    }
    
    func showError (_ message: String) {
        signUpLabel.text = message
        signUpLabel.isHidden = false
    }
    

}
