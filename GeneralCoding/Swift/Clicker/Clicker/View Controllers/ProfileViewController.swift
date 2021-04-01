//
//  ProfileViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 1/4/21.
//

import UIKit
import Firebase

class ProfileViewController: UIViewController {
    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var nameShow: UILabel!
    @IBOutlet weak var dateShow: UILabel!
    @IBOutlet weak var scoreShow: UILabel!
    var selectedUser: String?
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let selectedUser = selectedUser {
            
            
            let db = Firestore.firestore()
            let docRef = db.collection("users").document(selectedUser)

            docRef.getDocument { [self] (document, error) in
                if let document = document, document.exists {
                    let dataDescription = document.data()!//.map(String.init(describing:)) ?? "nil"
                    let currentScore = dataDescription["high"] ?? 0
                    let UserID = dataDescription["uid"] ?? "0"
                    let firstname = dataDescription["firstname"] ?? ""
                    let lastname = dataDescription["lastname"] ?? ""
                    let time = dataDescription["time"] ?? ""
                    let date = time as! String
                    let score = (currentScore as! Int)
                    let uid = UserID as! String
                    let firstName = firstname as! String
                    let lastName = lastname as! String
                    self.title = "Profile (\(firstName))"
                    self.nameLabel.text = "Name: \(firstName) \nScore: \(score) \nDay Registered: \(date)"
                    
                }
            }
        }

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

}
