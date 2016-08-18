//
//  Triangle.h
//  Inheritance Example
//
//  Created by MacBook Air on 6/9/15.
//  Copyright (c) 2015 MacBook Air. All rights reserved.
//

// Base class for triangles
#ifndef Inheritance_Example_Triangle_h
#define Inheritance_Example_Triangle_h

#include <iostream>
using namespace std;
class Triangle{
public:
    Triangle();
    Triangle(int);
    void setHeight(int);
    int getHeight() const;
    double getArea(int) const;
    ~Triangle();
private:
int height;
};
#endif
