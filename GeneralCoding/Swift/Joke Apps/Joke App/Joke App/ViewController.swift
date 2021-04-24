//
//  ViewController.swift
//  Joke App
//
//  Created by Xiao Nianhe on 4/4/21.
//

import UIKit
import Firebase

class ViewController: UIViewController {
    var currentJoke = 0
    var choice = true
    var nextJoke: String = ""
    var nextPunch: String? = nil
    var nextVote = 0
    var currentVote = 0
    var currentId: String = ""
    var nextId: String = ""
    @IBOutlet weak var barUp: UIBarButtonItem!
    @IBOutlet weak var barDown: UIBarButtonItem!
    @IBOutlet weak var barLabel: UIBarButtonItem!
    
    
    


    @IBOutlet weak var noIdea: UIButton!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var answerLabel: UILabel!
    @IBOutlet weak var continueLabel: UILabel!
    @IBOutlet var tapButton: UITapGestureRecognizer!
    
    override func viewDidLoad() {
        navigationController?.navigationBar.prefersLargeTitles = true
        barLabel.tintColor = .systemGreen
//        barLabel.isEnabled = false
        
        self.title = ""
        super.viewDidLoad()
        getData(first: true)
        getData(first: false)
        noIdea.layer.cornerRadius = 10
        answerLabel.alpha = 0
        continueLabel.isHidden = true
        
    }
    
    @IBAction func answerRequested(_ sender: Any) {
        if noIdea.currentTitle == "No idea :o" {
            UIView.animate(withDuration: 1) {
                self.answerLabel.alpha = 1
            }
            noIdea.setTitle("Tap for new", for: .normal)
        }
        
        else if noIdea.currentTitle == "Tap for new"{
            
            let alert = UIAlertController(title: "Opinion", message: "Did you like that joke?", preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: NSLocalizedString("Yes", comment: "Default action"), style: .default, handler: { _ in
                self.addUpVote()
                let alert2 = UIAlertController(title: "Thank you", message: "We appreciate your love for this joke.", preferredStyle: .alert)
                alert2.addAction(UIAlertAction(title: NSLocalizedString("Continue", comment: "Default action"), style: .default, handler: { _ in
                    self.updateQuestionAnswer()
                }))
                
                self.present(alert2, animated: true)
            }))
            alert.addAction(UIAlertAction(title: NSLocalizedString("No", comment: "Default action"), style: .default, handler: { _ in
//                NSLog("Not ok alert chosen.")
//                self.updateQuestionAnswer()
                
                let alert2 = UIAlertController(title: "Disgraceful...", message: "Is this not a great joke???", preferredStyle: .alert)
                alert2.addAction(UIAlertAction(title: NSLocalizedString("Continue", comment: "Default action"), style: .default, handler: { _ in
//                    NSLog("Continue alert chosen.")
                    self.updateQuestionAnswer()
                }))
                
//                alert2.addAction(UIAlertAction(title: NSLocalizedString("Cancel", comment: "Default action"), style: .default, handler: { _ in
//                    NSLog("Cancel alert chosen.")
////                    self.updateQuestionAnswer()
////                    self.questionLabel.text = self.nextJoke;
//                }))
                
                self.present(alert2, animated: true)
                
            }))
            self.present(alert, animated: true) {
                self.getData(first: false)
            }
            
        }
        
        
        
//        getData()
    }
    
//    @IBAction func screenTapped(_ sender: Any) {
//        getData(first: false)
//    }
    
    func setJoke(){
        tapButton.isEnabled = false
        noIdea.isEnabled = true
        answerLabel.alpha = 0
        continueLabel.isHidden = true
    }
    
    func newJoke(){
        
    }
    
    func getData (first: Bool){
        var value = [String]()
        let url = URL(string: "https://icanhazdadjoke.com/")!
        var request = URLRequest(url: url)
        request.httpMethod = "GET"
        request.setValue("application/json", forHTTPHeaderField:"Accept")
        let task = URLSession.shared.dataTask(with: request) {(data, response, error) in
            guard let data = data else { return }
            var result: Response?
            do {
                result = try JSONDecoder().decode(Response.self, from: data)
            }
            catch {
                print("Fail")
            }
            if let joke = result {
                var joky = joke.joke
                if joky.count > 100 {
                    DispatchQueue.main.async {
                        self.getData(first: first)
                    }
                    return
                }
                print(joke.id)
                let db = Firestore.firestore()
                let docRef = db.collection("jokes").document(joke.id)
                self.nextId = joke.id

                docRef.getDocument { [self] (document, error) in
                    if let document = document, document.exists {
                        let dataDescription = document.data()!//.map(String.init(describing:)) ?? "nil"
                        let upvotes = dataDescription["upvotes"] ?? 0
                        let downvotes = dataDescription["downvotes"] ?? 0
                        let upvote = upvotes as! Int
                        let downvote = downvotes as! Int
                        self.nextVote = (upvote - downvote)
                    } else {
                        db.collection("jokes").document(joke.id).setData(["upvotes": 0, "downvotes": 0, "joke": joke.joke]) { (err) in
                            if let err = err {
                                print("Error writing document: \(err)")
                            } else {
                                print("Document successfully written!")
                            }
                        }
                        self.nextVote = 0
                    }
                }
                
                joky = joky.trimmingCharacters(in: .whitespacesAndNewlines)
//                print(joky)
                if joky.contains("? "){
                    var arr = joky.split(separator: "?")
                    arr[0] = arr[0]+"?"
                    arr[1] = Substring(arr[1].trimmingCharacters(in: .whitespaces))
                    value.append(String(arr[0]))
                    value.append(String(arr[1]))
                    print(arr)
                    DispatchQueue.main.async {
//                        self.questionLabel.text = String(arr[0])
//                        self.answerLabel.text = String(arr[1])
                        self.nextJoke = String(arr[0])
                        self.nextPunch = String(arr[1])
//                        self.tapButton.isEnabled = false
//                        self.noIdea.isEnabled = true
//                        self.answerLabel.alpha = 0
//                        self.noIdea.setTitle("No idea :o", for: .normal)
//                        self.choice = true
                        if first{
//                            self.questionLabel.text = self.nextJoke;
//                            self.currentId = self.nextId
//                            if let punch = self.nextPunch{
//                                self.answerLabel.text = punch
//                                self.noIdea.setTitle("No idea :o", for: .normal)
//                            }
//                            else {
//                                self.noIdea.setTitle("Tap for new", for: .normal)
//                            }
                            self.updateQuestionAnswer()
                        }
                    }
                    
                }
                else {
//                    joky += "."
                    print(joky)
//                    self.setQuestion(label: joky)
//                    self.tapButton.isEnabled = true
                    value.append(joky)
                    DispatchQueue.main.async {
                        self.nextJoke = joky
                        self.nextPunch = nil
//                        self.questionLabel.text = joky
//                        self.noIdea.isEnabled = true
////                        self.tapButton.isEnabled = true
//                        self.answerLabel.alpha = 0
//                        self.noIdea.setTitle("Tap for new", for: .normal)
//                        self.choice = false
                        if first {
                            self.updateQuestionAnswer()
                        }
                    }
                    
//                    return value
//                    return value
                }
            }
            
        }

        task.resume()
//        return value
//        return value
    }
    
    func setQuestion(label: String){
        questionLabel.text = label
    }
    
    func updateQuestionAnswer() {
        answerLabel.alpha = 0
        
        if let punch = nextPunch{
            answerLabel.text = punch
            noIdea.setTitle("No idea :o", for: .normal)
        }
        else {
            self.noIdea.setTitle("Tap for new", for: .normal)
        }
        questionLabel.text = nextJoke;
        currentId = nextId
        currentVote = nextVote
        barLabel.title = "\(self.currentVote)"
        if currentVote < 0{
            barLabel.tintColor = .systemRed
        }
        else {
            barLabel.tintColor = .systemGreen
        }
        
    }
    
    @IBAction func changeJoke(_ sender: Any) {
        updateQuestionAnswer()
        getData(first: false)
        
    }
    func addUpVote(){
        let db = Firestore.firestore()
        let docRef = db.collection("jokes").document(currentId)

        docRef.getDocument { (document, error) in
            if let document = document, document.exists {
                var dataDescription = document.data()!//.map(String.init(describing:)) ?? "nil"
                let upvotes = dataDescription["upvotes"] ?? 0
                let upvote = upvotes as! Int
                dataDescription["upvotes"] = upvote + 1
                print(dataDescription)
                print(type(of: dataDescription))
                
                db.collection("jokes").document(self.currentId).setData(dataDescription) { (err) in
                    if let err = err {
                        print("Error writing document: \(err)")
                    } else {
                        print("Document successfully written!")
                    }
                }
            }
        }
    }
}
    


struct Response: Codable{
    let id: String
    let joke: String
    let status: Int
}

