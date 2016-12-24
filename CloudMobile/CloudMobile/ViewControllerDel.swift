//
//  ViewControllerDelete.swift
//  CloudMobile
//
//  Created by Tyler Sustare on 8/14/16.
//  Copyright © 2016 Tyler Sustare. All rights reserved.
//

import Foundation
import UIKit

class ViewControllerDel: UIViewController {
    
    @IBOutlet weak var userName: UITextField!
    @IBOutlet weak var teamName: UITextField!
    
    @IBAction func leave(_ sender: AnyObject) {
       let request = NSMutableURLRequest(url: NSURL(string: "http://52.10.195.0:3000/users/delete")! as URL)
        request.httpMethod = "POST"
        let postString = "UserKey=" + teamName.text! + "_" + userName.text!
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

