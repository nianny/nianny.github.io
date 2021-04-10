//
//  MyTableViewCell.swift
//  SkooLink
//
//  Created by Xiao Nianhe on 10/4/21.
//

import UIKit

class MyTableViewCell: UITableViewCell {
    @IBOutlet weak var profilePicture: UIImageView!
    @IBOutlet weak var userName: UIButton!
    @IBOutlet weak var postLabel: UILabel!
    static let identifier = "MyTableViewCell"
    
    static func nib() -> UINib {
        return UINib(nibName: identifier, bundle: nil)
    }
    
    public func configure(with username: String, imageName: String){
        userName.setTitle(username, for: .normal)
        profilePicture.image = UIImage(systemName: imageName)
    }
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
