//
//  ViewController.swift
//  CloudMobile
//
//  Created by Tyler Sustare on 7/30/16.
//  Copyright © 2016 Tyler Sustare. All rights reserved.
//

import UIKit
var si = ViewControllerSignIn()

class ViewController: UIViewController {
    
    @IBOutlet var siUN: UITextField!
//    @IBOutlet var cityTextField: UITextField!
    @IBOutlet var resultLabel: UILabel!
    @IBAction func submit(_ sender: AnyObject) {
//        if let url = URL(string: "http://api.openweathermap.org/data/2.5/weather?q=" + cityTextField.text!.replacingOccurrences(of: " ", with: "%20") + "&appid=51da705806d6cfc92d74540c77c87385"){
        if let url = URL(string: "http://52.10.195.0:3000/users"){
            
            let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
                if error != nil {
                    print(error)
                } else {
                    if let urlContent = data {
                        do{
                            let jsonResult = try JSONSerialization.jsonObject(with: urlContent, options: JSONSerialization.ReadingOptions.mutableContainers)
                            print("Here comes JSON\n\n")
                            print(jsonResult)
                            print(jsonResult["Items"]??[0])
                            let arraySize = jsonResult["Count"] as! Int
                            var i:Int = 0
                            while i < arraySize{
                                let tN = jsonResult["Items"]??[i]["TeamName"] as! String
                                if tN.range(of: self.siUN.text!) != nil{
                                    
                                    if let userName = jsonResult["Items"]??[i]["UserName"] as! String? {
                                        DispatchQueue.main.sync(execute: {
                                            self.resultLabel.text! += "Name: " + userName + "\n" //+ "\(temp) Degrees Fahrenheit"
                                        })
                                    }
                                    if let level = jsonResult["Items"]??[i]["Level"] as! String? {
                                        DispatchQueue.main.sync(execute: {
                                            self.resultLabel.text! += "Position: " + level + "\n" //+ "\(temp) Degrees Fahrenheit"
                                        })
                                    }
                                    
                                    if let role = jsonResult["Items"]??[i]["Role"] as! String? {
                                        DispatchQueue.main.sync(execute: {
                                            self.resultLabel.text! += "Number: " + role + "\n" //+ "\(temp) Degrees Fahrenheit"
                                        })
                                    }
                                    
                                    if let starter = jsonResult["Items"]??[i]["IsSignedUp"] as! String? {
                                        DispatchQueue.main.sync(execute: {
                                            self.resultLabel.text! += "Starter: " + starter + "\n" //+ "\(temp) Degrees Fahrenheit"
                                        })
                                    }
                                }
                                i += 1
                            }
                            
                        } catch {
                            print("JSON processing error")
                        }
                    }
                }
            }
            task.resume()
        } else {
            resultLabel.text = "Couldn't find the weather."
        }
    }
    
//    let request = NSMutableURLRequest(url: NSURL(string: "http://52.10.195.0:3000/users")! as URL)
//    request.httpMethod = "POST"
//    let postString = "UserName=newestSwiftTest&TeamName=NewTestTeamName&Level=NewTestLevel&Role=coach&IsSignedUp=true"
//    request.httpBody = postString.data(using: String.Encoding.utf8)
//    let task = URLSession.shared.dataTask(with: request as URLRequest) { data, response, error in
//        guard error == nil && data != nil else {                                                          // check for fundamental networking error
//            print("error=\(error)")
//            return
//        }
//        
//        if let httpStatus = response as? HTTPURLResponse where httpStatus.statusCode != 200 {           // check for http errors
//            print("statusCode should be 200, but is \(httpStatus.statusCode)")
//            print("response = \(response)")
//        }
//
//        let responseString = NSString(data: data!, encoding: String.Encoding.utf8.rawValue)
//        print("responseString = \(responseString)")
//    }
//    task.resume()
//    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}

