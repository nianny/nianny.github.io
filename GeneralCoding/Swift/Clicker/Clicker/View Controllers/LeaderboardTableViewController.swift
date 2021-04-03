//
//  LeaderboardTableViewController.swift
//  Clicker
//
//  Created by Xiao Nianhe on 1/4/21.
//

import UIKit
import Firebase

class LeaderboardTableViewController: UITableViewController {
    @IBOutlet weak var `return`: UIBarButtonItem!
    @IBOutlet var tableview: UITableView!
    @IBOutlet weak var selector: UISegmentedControl!
    var arr = [String]()
    var uid = [String]()
    override func viewDidLoad() {
        self.title = "Leaderboard"
        
        super.viewDidLoad()
        let db = Firestore.firestore()
        let score = db.collection("users")
        let scores = score.order(by: "high", descending: true)
        scores.getDocuments { (data, err) in
            if err != nil{
                print("Error: \(err)")
            }
            else {
                var count = 1
                for documents in  data!.documents {
                    let daMap = documents.data()
                    let score = daMap["high"] as! Int
                    let name = daMap["firstname"] as! String
                    let UserID = daMap["uid"] as! String
                    
                    self.arr.append("\(count). \(name) (\(score) clicks)")
                    print("\(name) is \(score)!")
                    self.uid.append(UserID)
                    
                    count += 1
                }
                print(self.arr)
                self.tableView.reloadData()
            }
        }

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem
    }

    // MARK: - Table view data source

//    override func numberOfSections(in tableView: UITableView) -> Int {
//        // #warning Incomplete implementation, return the number of sections
//        return 0
//    }
//
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return arr.count
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Scores", for: indexPath)
        cell.textLabel?.text = arr[indexPath.row]
        return cell
    }
    

    /*
    // Override to support conditional editing of the table view.
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }
    */

    /*
    // Override to support editing the table view.
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            // Delete the row from the data source
            tableView.deleteRows(at: [indexPath], with: .fade)
        } else if editingStyle == .insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }    
    }
    */

    /*
    // Override to support rearranging the table view.
    override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the item to be re-orderable.
        return true
    }
    */

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    @IBAction func goBack(_ sender: Any) {
        self.dismiss(animated: true, completion: nil)
//        self.dismiss(animated: true, completion: nil)
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if let vc = storyboard?.instantiateViewController(identifier: "Profile") as? ProfileViewController {
            vc.selectedUser = uid[indexPath.row]
            navigationController?.pushViewController(vc, animated: true)
        }
    }
    
    @IBAction func changeChoice(_ sender: Any) {
        self.arr = [String]()
        self.uid = [String]()
        let db = Firestore.firestore()
        let score = db.collection("users")
        var scores = score.order(by: "high", descending: true)
        if selector.selectedSegmentIndex == 0{
            scores = score.order(by: "high", descending: true)
        }
        else if selector.selectedSegmentIndex == 1{
            scores = score.order(by: "speed", descending: true)
        }
        
        scores.getDocuments { (data, err) in
            if err != nil{
                print("Error: \(err)")
            }
            else {
                var count = 1
                for documents in  data!.documents {
                    let daMap = documents.data()
                    let score = daMap["high"] as! Int
                    let speeda = daMap["speed"] ?? 0
                    var speed = speeda as! Double
                    speed = round(speed*100)/100
                    let name = daMap["firstname"] as! String
                    let UserID = daMap["uid"] as! String
                    self.uid.append(UserID)
                    if self.selector.selectedSegmentIndex == 0{
                        self.arr.append("\(count). \(name) (\(score) clicks)")
                    }
                    else if self.selector.selectedSegmentIndex == 1{
                        self.arr.append("\(count). \(name) (\(speed) clicks/s)")
                    }
                    
                    print("\(name) is \(score)!")
//                    self.uid.append(UserID)
                    
                    count += 1
                }
                print(self.arr)
                self.tableView.reloadData()
            }
        }
        
        
    }
}
