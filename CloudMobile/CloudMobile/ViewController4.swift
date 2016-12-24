//
//  ViewController4.swift
//  CloudMobile
//
//  Created by Tyler Sustare on 8/14/16.
//  Copyright © 2016 Tyler Sustare. All rights reserved.
//

import Foundation

import UIKit

class ViewController4: UIViewController {
    
    
    @IBOutlet weak var userName: UITextField!
    @IBOutlet weak var teamName: UITextField!
    @IBOutlet weak var level: UITextField!
    @IBOutlet weak var isSubscribed: UISwitch!
    @IBOutlet weak var role: UITextField!
//    @IBOutlet weak var isSubscribed: UISwitch! // starter
//    @IBOutlet weak var role: UITextField! // number
//    @IBOutlet weak var level: UITextField! // position
//    @IBOutlet weak var teamName: UITextField! // coach name
//    @IBOutlet var userName: UITextField! // player name
    @IBAction func update(_ sender: AnyObject) {
        let request = NSMutableURLRequest(url: NSURL(string: "http://52.10.195.0:3000/users/update")! as URL)
        request.httpMethod = "POST"
        let key = teamName.text! + "_" + userName.text! as String
        let postString = "UserKey=" + key + "&UserName=" + userName.text! + "&TeamName=" + teamName.text! +  "&IsSignedUp=" + "\(isSubscribed.isOn)"
        request.httpBody = postString.data(using: String.Encoding.utf8)
        let task = URLSession.shared.dataTask(with: request as URLRequest) { data, response, error in
            guard error == nil && data != nil else {      // check for networking error
                print("error=\(error)")
                return
            }
            
            if let httpStatus = response as? HTTPURLResponse , httpStatus.statusCode != 200 {           // check for http errors
                print("statusCode should be 200, but is \(httpStatus.statusCode)")
                print("response = \(response)")
            }
            
            let responseString = NSString(data: data!, encoding: String.Encoding.utf8.rawValue)
            print("responseString = \(responseString)")
        }
        task.resume()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
