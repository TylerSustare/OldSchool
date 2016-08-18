//
//  main.cpp
//  Inheritance Example
//
//  Created by MacBook Air on 6/9/15.
//  Copyright (c) 2015 MacBook Air. All rights reserved.
//

#include <iostream>
#include "Isosceles.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int base, height, equalSide;
    
    cout << "Please select a base length: ";
    cin >> base;
    cout << "Please type in the height: ";
    cin >> height;
    cout << "Please type int he side that is equal: ";
    cin >> equalSide;
    
    Isosceles myTriangle(base, equalSide, height);
    cout << endl;
    myTriangle.printInfo();
    
    return 0;
}
