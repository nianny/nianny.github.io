//
//  ViewController.swift
//  SkooLink
//
//  Created by Xiao Nianhe on 10/4/21.
//
import UIKit
import Firebase

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    let arr = ["Chat 1", "Chat 2", "Chat 3", "Chat 4"]
    
    @IBOutlet weak var newPost: UIBarButtonItem!
    @IBOutlet var table: UITableView!
    @IBOutlet weak var profileItem: UIBarButtonItem!
    override func viewDidLoad() {
        super.viewDidLoad()
        table.register(MyTableViewCell.nib(), forCellReuseIdentifier: MyTableViewCell.identifier)
        table.delegate = self
        table.dataSource = self
        self.title = "Posts"
        navigationController?.navigationBar.prefersLargeTitles = true
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 3
    }

    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let customCell = tableView.dequeueReusableCell(withIdentifier: MyTableViewCell.identifier, for: indexPath) as! MyTableViewCell
        customCell.configure(with: "Nianny", imageName: "person.crop.circle")
        return customCell
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 100
    }
    @IBAction func showProfile(_ sender: Any) {
//        if Auth.auth().currentUser != nil {
//          // User is signed in.
//          // ...
//        } else {
        print("hi")
        
            let sb = UIStoryboard(name: "Main", bundle: nil)
            if let secondVC = sb.instantiateViewController(identifier: "signUpVC") as? ViewController {
                self.present(secondVC, animated: true, completion: nil)
            }
//        }
    }
}

