//
//  ViewControllerSignIn.swift
//  CloudMobile
//
//  Created by Tyler Sustare on 8/14/16.
//  Copyright © 2016 Tyler Sustare. All rights reserved.
//

import Foundation

import UIKit

class ViewControllerSignIn: UIViewController, UINavigationControllerDelegate, UIImagePickerControllerDelegate{
    
    @IBOutlet var sInAttempt: UITextField!
    @IBOutlet weak var sInPass: UITextField!
    
    @IBOutlet weak var warn: UILabel!
    @IBAction func signIn(_ sender: AnyObject) {
        //        if let url = URL(string: "http://api.openweathermap.org/data/2.5/weather?q=" + cityTextField.text!.replacingOccurrences(of: " ", with: "%20") + "&appid=51da705806d6cfc92d74540c77c87385"){

        var signedInFlag = false

        if let url = URL(string: "http://52.10.195.0:3000/users"){
            let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
                if error != nil {
                    print(error)
                } else {
                    if let urlContent = data {
                        do{
                            let jsonResult = try JSONSerialization.jsonObject(with: urlContent, options: JSONSerialization.ReadingOptions.mutableContainers)
                            let arraySize = jsonResult["Count"] as! Int
                            var i:Int = 0
                            while i < arraySize{
                                if (jsonResult["Items"]??[i]["UserName"] as! String == self.sInAttempt.text! && jsonResult["Items"]??[i]["TeamName"] as! String == self.sInPass.text! ){
                                        signedInFlag = true
                                }
                                i += 1
                            }
                        } catch {
                            print("JSON processing error")
                        }
                    }
                }
            }
            if (signedInFlag){
                task.resume()
            }else{
                return
            }
        } else {
        }

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
